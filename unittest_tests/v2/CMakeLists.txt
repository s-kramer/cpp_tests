cmake_minimum_required(VERSION 2.6)
project(soundex2)
enable_testing()

add_definitions(-std=c++14)
# set(warnings "-Wall -Wextra -Werror")
set(warnings "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "${warnings}")

add_executable(soundex_test Soundex.h Soundex.cpp soundex_unittest.cpp)
add_test(soundex_test soundex_test)
target_link_libraries(soundex_test boost_unit_test_framework)

add_custom_command(TARGET soundex_test
    POST_BUILD
    COMMAND soundex_test
    WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
    COMMENT "Running ${target}" VERBATIM)

add_executable(soundex_test_sanitize_address EXCLUDE_FROM_ALL Soundex.h Soundex.cpp soundex_unittest.cpp)
add_test(soundex_test_sanitize_address soundex_test_sanitize_address)
target_link_libraries(soundex_test_sanitize_address boost_unit_test_framework)

# add_executable(soundex_test_sanitize_memory EXCLUDE_FROM_ALL Soundex.h Soundex.cpp soundex_unittest.cpp)
# add_test(soundex_test_sanitize_memory soundex_test_sanitize_memory)
# target_link_libraries(soundex_test_sanitize_memory boost_unit_test_framework)

add_executable(soundex_test_sanitize_undefined EXCLUDE_FROM_ALL Soundex.h Soundex.cpp soundex_unittest.cpp)
add_test(soundex_test_sanitize_undefined soundex_test_sanitize_undefined)
target_link_libraries(soundex_test_sanitize_undefined boost_unit_test_framework)

set_property(TARGET soundex_test_sanitize_address APPEND PROPERTY COMPILE_FLAGS "-fsanitize=address")
# set_property(TARGET soundex_test_sanitize_memory APPEND PROPERTY COMPILE_FLAGS "-fsanitize=memory")
set_property(TARGET soundex_test_sanitize_undefined APPEND PROPERTY COMPILE_FLAGS "-fsanitize=undefined")

add_custom_target( clang-tests 
    COMMAND soundex_test_sanitize_address
    # COMMAND soundex_test_sanitize_memory
    COMMAND soundex_test_sanitize_undefined
    VERBATIM)

# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug ..
# scan-build -v cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug ..
