# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/skramer/c_test/cmake_tutorial

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/skramer/c_test/cmake_tutorial/build

# Include any dependencies generated for this target.
include CMakeFiles/ToDo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ToDo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ToDo.dir/flags.make

CMakeFiles/ToDo.dir/main.cpp.o: CMakeFiles/ToDo.dir/flags.make
CMakeFiles/ToDo.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skramer/c_test/cmake_tutorial/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ToDo.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ToDo.dir/main.cpp.o -c /home/skramer/c_test/cmake_tutorial/main.cpp

CMakeFiles/ToDo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ToDo.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/skramer/c_test/cmake_tutorial/main.cpp > CMakeFiles/ToDo.dir/main.cpp.i

CMakeFiles/ToDo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ToDo.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/skramer/c_test/cmake_tutorial/main.cpp -o CMakeFiles/ToDo.dir/main.cpp.s

CMakeFiles/ToDo.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/ToDo.dir/main.cpp.o.requires

CMakeFiles/ToDo.dir/main.cpp.o.provides: CMakeFiles/ToDo.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ToDo.dir/build.make CMakeFiles/ToDo.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ToDo.dir/main.cpp.o.provides

CMakeFiles/ToDo.dir/main.cpp.o.provides.build: CMakeFiles/ToDo.dir/main.cpp.o

CMakeFiles/ToDo.dir/ToDo.cpp.o: CMakeFiles/ToDo.dir/flags.make
CMakeFiles/ToDo.dir/ToDo.cpp.o: ../ToDo.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/skramer/c_test/cmake_tutorial/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/ToDo.dir/ToDo.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/ToDo.dir/ToDo.cpp.o -c /home/skramer/c_test/cmake_tutorial/ToDo.cpp

CMakeFiles/ToDo.dir/ToDo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ToDo.dir/ToDo.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/skramer/c_test/cmake_tutorial/ToDo.cpp > CMakeFiles/ToDo.dir/ToDo.cpp.i

CMakeFiles/ToDo.dir/ToDo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ToDo.dir/ToDo.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/skramer/c_test/cmake_tutorial/ToDo.cpp -o CMakeFiles/ToDo.dir/ToDo.cpp.s

CMakeFiles/ToDo.dir/ToDo.cpp.o.requires:
.PHONY : CMakeFiles/ToDo.dir/ToDo.cpp.o.requires

CMakeFiles/ToDo.dir/ToDo.cpp.o.provides: CMakeFiles/ToDo.dir/ToDo.cpp.o.requires
	$(MAKE) -f CMakeFiles/ToDo.dir/build.make CMakeFiles/ToDo.dir/ToDo.cpp.o.provides.build
.PHONY : CMakeFiles/ToDo.dir/ToDo.cpp.o.provides

CMakeFiles/ToDo.dir/ToDo.cpp.o.provides.build: CMakeFiles/ToDo.dir/ToDo.cpp.o

# Object files for target ToDo
ToDo_OBJECTS = \
"CMakeFiles/ToDo.dir/main.cpp.o" \
"CMakeFiles/ToDo.dir/ToDo.cpp.o"

# External object files for target ToDo
ToDo_EXTERNAL_OBJECTS =

ToDo: CMakeFiles/ToDo.dir/main.cpp.o
ToDo: CMakeFiles/ToDo.dir/ToDo.cpp.o
ToDo: CMakeFiles/ToDo.dir/build.make
ToDo: CMakeFiles/ToDo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ToDo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ToDo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ToDo.dir/build: ToDo
.PHONY : CMakeFiles/ToDo.dir/build

CMakeFiles/ToDo.dir/requires: CMakeFiles/ToDo.dir/main.cpp.o.requires
CMakeFiles/ToDo.dir/requires: CMakeFiles/ToDo.dir/ToDo.cpp.o.requires
.PHONY : CMakeFiles/ToDo.dir/requires

CMakeFiles/ToDo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ToDo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ToDo.dir/clean

CMakeFiles/ToDo.dir/depend:
	cd /home/skramer/c_test/cmake_tutorial/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/skramer/c_test/cmake_tutorial /home/skramer/c_test/cmake_tutorial /home/skramer/c_test/cmake_tutorial/build /home/skramer/c_test/cmake_tutorial/build /home/skramer/c_test/cmake_tutorial/build/CMakeFiles/ToDo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ToDo.dir/depend
