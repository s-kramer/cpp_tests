# Main application
add_executable(fibonacci_main "main.cpp")

# Profiled solution #1 for valgrind
add_executable(fibonacci_recalc "fibonacci_recalc_prof.cpp")

# Profiled solution #2 for valgrind
add_executable(fibonacci_cached "fibonacci_cached_prof.cpp")

# Profiled solution #1 for gprof
add_executable(fibonacci_recalc_pg "fibonacci_recalc_prof.cpp")

# Profiled solution #2 for gprof
add_executable(fibonacci_cached_pg "fibonacci_cached_prof.cpp")

target_link_libraries(fibonacci_cached fibonacci_lib)
target_link_libraries(fibonacci_recalc_pg fibonacci_lib)
target_link_libraries(fibonacci_cached_pg fibonacci_lib)
target_link_libraries(fibonacci_recalc fibonacci_lib)
target_link_libraries(fibonacci_main fibonacci_lib)

add_gprof_lib(fibonacci_cached_pg)
add_gprof_lib(fibonacci_recalc_pg)

