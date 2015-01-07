cmake_minimum_required(VERSION 2.6)
project("soundex1")
enable_testing()

add_definitions(-std=c++14)
set(warnings "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${warnings}")

add_executable(soundex_test soundex.cpp soundex_utils.cpp soundex_unittest.cpp)
add_test(soundex_test soundex_test)
target_link_libraries(soundex_test boost_unit_test_framework)

add_custom_command(TARGET soundex_test
    POST_BUILD
    COMMAND soundex_test
    WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
    COMMENT "Running ${target}" VERBATIM)

# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug ..
