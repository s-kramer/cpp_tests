cmake_minimum_required(VERSION 2.6)
project(soundex2)
enable_testing()

add_definitions(-std=c++14)
set(warnings "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${warnings}")
# set(CMAKE_C_COMPILER clang)
# set(CMAKE_CXX_COMPILER clang++)

set (soundex_filenames Soundex.cpp soundex_unittest.cpp)

add_executable(soundex_test ${soundex_filenames})
target_link_libraries(soundex_test boost_unit_test_framework)
add_test(soundex_test soundex_test)

add_custom_command(TARGET soundex_test
    POST_BUILD
    COMMAND soundex_test
    COMMENT "Running basic soundex unittest suite" VERBATIM)

function(add_sanitized_test target sanitization)
    add_executable(${target} EXCLUDE_FROM_ALL ${soundex_filenames})
    target_link_libraries(${target} boost_unit_test_framework)
    set_target_properties(${target} PROPERTIES COMPILE_FLAGS -fsanitize=${sanitization} LINK_FLAGS -fsanitize=${sanitization})
    add_test(${target} ${target})

    add_custom_command(TARGET ${target}
                       POST_BUILD
                       COMMAND ${target}
                       COMMENT "Running ${target}" VERBATIM)
endfunction()

add_sanitized_test("soundex_test_sanitize_address"     "address")
add_sanitized_test("soundex_test_sanitize_memory"      "memory")
add_sanitized_test("soundex_test_sanitize_undefined"   "undefined")
 
add_custom_target( clang-tests 
    DEPENDS soundex_test_sanitize_address soundex_test_sanitize_memory soundex_test_sanitize_undefined
    VERBATIM)

# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug ..
# scan-build -v cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug ..
