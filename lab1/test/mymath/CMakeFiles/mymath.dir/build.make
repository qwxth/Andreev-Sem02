# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oem/labs/Andreev-Sem02/lab1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oem/labs/Andreev-Sem02/lab1/test

# Include any dependencies generated for this target.
include mymath/CMakeFiles/mymath.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include mymath/CMakeFiles/mymath.dir/compiler_depend.make

# Include the progress variables for this target.
include mymath/CMakeFiles/mymath.dir/progress.make

# Include the compile flags for this target's objects.
include mymath/CMakeFiles/mymath.dir/flags.make

mymath/CMakeFiles/mymath.dir/mymath.cpp.o: mymath/CMakeFiles/mymath.dir/flags.make
mymath/CMakeFiles/mymath.dir/mymath.cpp.o: /home/oem/labs/Andreev-Sem02/lab1/mymath/mymath.cpp
mymath/CMakeFiles/mymath.dir/mymath.cpp.o: mymath/CMakeFiles/mymath.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/oem/labs/Andreev-Sem02/lab1/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object mymath/CMakeFiles/mymath.dir/mymath.cpp.o"
	cd /home/oem/labs/Andreev-Sem02/lab1/test/mymath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT mymath/CMakeFiles/mymath.dir/mymath.cpp.o -MF CMakeFiles/mymath.dir/mymath.cpp.o.d -o CMakeFiles/mymath.dir/mymath.cpp.o -c /home/oem/labs/Andreev-Sem02/lab1/mymath/mymath.cpp

mymath/CMakeFiles/mymath.dir/mymath.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/mymath.dir/mymath.cpp.i"
	cd /home/oem/labs/Andreev-Sem02/lab1/test/mymath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oem/labs/Andreev-Sem02/lab1/mymath/mymath.cpp > CMakeFiles/mymath.dir/mymath.cpp.i

mymath/CMakeFiles/mymath.dir/mymath.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/mymath.dir/mymath.cpp.s"
	cd /home/oem/labs/Andreev-Sem02/lab1/test/mymath && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oem/labs/Andreev-Sem02/lab1/mymath/mymath.cpp -o CMakeFiles/mymath.dir/mymath.cpp.s

# Object files for target mymath
mymath_OBJECTS = \
"CMakeFiles/mymath.dir/mymath.cpp.o"

# External object files for target mymath
mymath_EXTERNAL_OBJECTS =

mymath/libmymath.a: mymath/CMakeFiles/mymath.dir/mymath.cpp.o
mymath/libmymath.a: mymath/CMakeFiles/mymath.dir/build.make
mymath/libmymath.a: mymath/CMakeFiles/mymath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/oem/labs/Andreev-Sem02/lab1/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmymath.a"
	cd /home/oem/labs/Andreev-Sem02/lab1/test/mymath && $(CMAKE_COMMAND) -P CMakeFiles/mymath.dir/cmake_clean_target.cmake
	cd /home/oem/labs/Andreev-Sem02/lab1/test/mymath && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mymath.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
mymath/CMakeFiles/mymath.dir/build: mymath/libmymath.a
.PHONY : mymath/CMakeFiles/mymath.dir/build

mymath/CMakeFiles/mymath.dir/clean:
	cd /home/oem/labs/Andreev-Sem02/lab1/test/mymath && $(CMAKE_COMMAND) -P CMakeFiles/mymath.dir/cmake_clean.cmake
.PHONY : mymath/CMakeFiles/mymath.dir/clean

mymath/CMakeFiles/mymath.dir/depend:
	cd /home/oem/labs/Andreev-Sem02/lab1/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oem/labs/Andreev-Sem02/lab1 /home/oem/labs/Andreev-Sem02/lab1/mymath /home/oem/labs/Andreev-Sem02/lab1/test /home/oem/labs/Andreev-Sem02/lab1/test/mymath /home/oem/labs/Andreev-Sem02/lab1/test/mymath/CMakeFiles/mymath.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : mymath/CMakeFiles/mymath.dir/depend

