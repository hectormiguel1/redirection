# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /home/hector/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hector/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hector/CLionProjects/Assigment_5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hector/CLionProjects/Assigment_5/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/display.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/display.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/display.dir/flags.make

CMakeFiles/display.dir/display.c.o: CMakeFiles/display.dir/flags.make
CMakeFiles/display.dir/display.c.o: ../display.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hector/CLionProjects/Assigment_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/display.dir/display.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/display.dir/display.c.o   -c /home/hector/CLionProjects/Assigment_5/display.c

CMakeFiles/display.dir/display.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/display.dir/display.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hector/CLionProjects/Assigment_5/display.c > CMakeFiles/display.dir/display.c.i

CMakeFiles/display.dir/display.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/display.dir/display.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hector/CLionProjects/Assigment_5/display.c -o CMakeFiles/display.dir/display.c.s

CMakeFiles/display.dir/errorPrinter.c.o: CMakeFiles/display.dir/flags.make
CMakeFiles/display.dir/errorPrinter.c.o: ../errorPrinter.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hector/CLionProjects/Assigment_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/display.dir/errorPrinter.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/display.dir/errorPrinter.c.o   -c /home/hector/CLionProjects/Assigment_5/errorPrinter.c

CMakeFiles/display.dir/errorPrinter.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/display.dir/errorPrinter.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hector/CLionProjects/Assigment_5/errorPrinter.c > CMakeFiles/display.dir/errorPrinter.c.i

CMakeFiles/display.dir/errorPrinter.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/display.dir/errorPrinter.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hector/CLionProjects/Assigment_5/errorPrinter.c -o CMakeFiles/display.dir/errorPrinter.c.s

# Object files for target display
display_OBJECTS = \
"CMakeFiles/display.dir/display.c.o" \
"CMakeFiles/display.dir/errorPrinter.c.o"

# External object files for target display
display_EXTERNAL_OBJECTS =

display: CMakeFiles/display.dir/display.c.o
display: CMakeFiles/display.dir/errorPrinter.c.o
display: CMakeFiles/display.dir/build.make
display: CMakeFiles/display.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hector/CLionProjects/Assigment_5/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable display"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/display.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/display.dir/build: display

.PHONY : CMakeFiles/display.dir/build

CMakeFiles/display.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/display.dir/cmake_clean.cmake
.PHONY : CMakeFiles/display.dir/clean

CMakeFiles/display.dir/depend:
	cd /home/hector/CLionProjects/Assigment_5/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hector/CLionProjects/Assigment_5 /home/hector/CLionProjects/Assigment_5 /home/hector/CLionProjects/Assigment_5/cmake-build-debug /home/hector/CLionProjects/Assigment_5/cmake-build-debug /home/hector/CLionProjects/Assigment_5/cmake-build-debug/CMakeFiles/display.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/display.dir/depend

