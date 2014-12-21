cmake_minimum_required(VERSION 2.6)
project(fibonacci)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_definitions(-std=c++11)
set(warnings "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${warnings}")

# add_subdirectory(src/fibonacci_lib)

# Main application
add_executable(fibonacci
                src/main.cpp 
                ./src/fibonacci_lib/fibonacci.cpp
                )
# target_link_libraries(fibonacci fibonacci_lib)

# Profiled solution #1 for valgrind
add_executable(fibonacci_recalc 
                ./src/fibonacci_recalc_prof.cpp 
                ./src/fibonacci_lib/fibonacci.cpp
                )
# target_link_libraries(fibonacci_recalc fibonacci_lib)

# Profiled solution #2 for valgrind
add_executable(fibonacci_cached 
                ./src/fibonacci_cached_prof.cpp 
                ./src/fibonacci_lib/fibonacci.cpp
                )
# target_link_libraries(fibonacci_cached fibonacci_lib)

# Profiled solution #1 for gprof
add_executable(fibonacci_recalc_pg 
                ./src/fibonacci_recalc_prof.cpp 
                ./src/fibonacci_lib/fibonacci.cpp
                )
# target_link_libraries(fibonacci_recalc_pg fibonacci_lib)

# Profiled solution #2 for gprof
add_executable(fibonacci_cached_pg
                ./src/fibonacci_cached_prof.cpp 
                ./src/fibonacci_lib/fibonacci.cpp
                )
# target_link_libraries(fibonacci_cached_pg fibonacci_lib)

set(GPROF_FLAG "-pg")
get_target_property(TEMP fibonacci_cached_pg COMPILE_FLAGS)
if(TEMP STREQUAL "TEMP-NOTFOUND")
  SET(TEMP "") # set to empty string
else()
  SET(TEMP "${TEMP} ") # a space to cleanly separate from existing content
endif()
# append our values
SET(TEMP "${TEMP}${GPROF_FLAG}")
set_target_properties(fibonacci_cached_pg fibonacci_recalc_pg PROPERTIES COMPILE_FLAGS "${TEMP}")

get_target_property(TEMP fibonacci_cached_pg LINK_FLAGS)
if(TEMP STREQUAL "TEMP-NOTFOUND")
  SET(TEMP "") # set to empty string
else()
  SET(TEMP "${TEMP} ") # a space to cleanly separate from existing content
endif()
# append our values
SET(TEMP "${TEMP}${GPROF_FLAG}")
set_target_properties(fibonacci_cached_pg fibonacci_recalc_pg PROPERTIES LINK_FLAGS "${TEMP}")
