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
CMAKE_COMMAND = /home/hectorramirez/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/hectorramirez/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.7142.39/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hectorramirez/CLionProjects/redirection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hectorramirez/CLionProjects/redirection/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/validation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/validation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/validation.dir/flags.make

CMakeFiles/validation.dir/validation.c.o: CMakeFiles/validation.dir/flags.make
CMakeFiles/validation.dir/validation.c.o: ../validation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hectorramirez/CLionProjects/redirection/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/validation.dir/validation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/validation.dir/validation.c.o   -c /home/hectorramirez/CLionProjects/redirection/validation.c

CMakeFiles/validation.dir/validation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/validation.dir/validation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/hectorramirez/CLionProjects/redirection/validation.c > CMakeFiles/validation.dir/validation.c.i

CMakeFiles/validation.dir/validation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/validation.dir/validation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/hectorramirez/CLionProjects/redirection/validation.c -o CMakeFiles/validation.dir/validation.c.s

# Object files for target validation
validation_OBJECTS = \
"CMakeFiles/validation.dir/validation.c.o"

# External object files for target validation
validation_EXTERNAL_OBJECTS =

validation: CMakeFiles/validation.dir/validation.c.o
validation: CMakeFiles/validation.dir/build.make
validation: CMakeFiles/validation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hectorramirez/CLionProjects/redirection/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable validation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/validation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/validation.dir/build: validation

.PHONY : CMakeFiles/validation.dir/build

CMakeFiles/validation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/validation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/validation.dir/clean

CMakeFiles/validation.dir/depend:
	cd /home/hectorramirez/CLionProjects/redirection/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hectorramirez/CLionProjects/redirection /home/hectorramirez/CLionProjects/redirection /home/hectorramirez/CLionProjects/redirection/cmake-build-debug /home/hectorramirez/CLionProjects/redirection/cmake-build-debug /home/hectorramirez/CLionProjects/redirection/cmake-build-debug/CMakeFiles/validation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/validation.dir/depend
