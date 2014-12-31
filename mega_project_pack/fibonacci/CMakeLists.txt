cmake_minimum_required(VERSION 2.6)
project(fibonacci)
include_directories(${CMAKE_SOURCE_DIR}/include)
enable_testing()

add_definitions(-std=c++11)
set(warnings "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${warnings}")

set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin/")

set(GPROF_FLAG "-pg")

function(add_boost_test target)
    add_executable(${target} ${ARGN})
    target_link_libraries(${target} boost_unit_test_framework)
    add_test(${target} ${EXECUTABLE_OUTPUT_PATH}/${target})

    add_custom_command(TARGET ${target}
                       POST_BUILD
                       COMMAND ${target}
                       WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
                       COMMENT "Running ${target}" VERBATIM)

endfunction()

function(add_gprof_lib target)
    get_target_property(TEMP ${target} LINK_FLAGS)
    if(TEMP STREQUAL "TEMP-NOTFOUND")
        SET(TEMP "") # set to empty string
    endif()
    SET(TEMP "${TEMP} ${GPROF_FLAG}")
    set_target_properties(${target} PROPERTIES LINK_FLAGS "${TEMP}")

    get_target_property(TEMP ${target} COMPILE_FLAGS)
    if(TEMP STREQUAL "TEMP-NOTFOUND")
        SET(TEMP "") # set to empty string
    endif()
    SET(TEMP "${TEMP} ${GPROF_FLAG}")
    set_target_properties(${target} PROPERTIES COMPILE_FLAGS "${TEMP}")

    # Profiling triggering
    add_custom_command(TARGET ${target}
                       POST_BUILD
                       COMMAND ${target}
                       COMMAND mv gmon.out "gmon.${target}"
                       COMMAND gprof -F getNthFibonacci ${target} "gmon.${target}" > "${target}_profile"
                       COMMAND rm "gmon.${target}"
                       WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
                       COMMENT "Running ${target}" VERBATIM)
endfunction()

add_subdirectory(src)
add_subdirectory(src/fibonacci_lib)
add_subdirectory(unittest)
