add_library(fibonacci_lib  SHARED ./fibonacci.cpp)
set(warnings "-Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${warnings}")
