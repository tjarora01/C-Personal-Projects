# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tanmayarora/CLionProjects/Imagionary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tanmayarora/CLionProjects/Imagionary/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Imagionary.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Imagionary.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Imagionary.dir/flags.make

CMakeFiles/Imagionary.dir/main.cpp.o: CMakeFiles/Imagionary.dir/flags.make
CMakeFiles/Imagionary.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tanmayarora/CLionProjects/Imagionary/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Imagionary.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Imagionary.dir/main.cpp.o -c /Users/tanmayarora/CLionProjects/Imagionary/main.cpp

CMakeFiles/Imagionary.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Imagionary.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tanmayarora/CLionProjects/Imagionary/main.cpp > CMakeFiles/Imagionary.dir/main.cpp.i

CMakeFiles/Imagionary.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Imagionary.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tanmayarora/CLionProjects/Imagionary/main.cpp -o CMakeFiles/Imagionary.dir/main.cpp.s

# Object files for target Imagionary
Imagionary_OBJECTS = \
"CMakeFiles/Imagionary.dir/main.cpp.o"

# External object files for target Imagionary
Imagionary_EXTERNAL_OBJECTS =

Imagionary: CMakeFiles/Imagionary.dir/main.cpp.o
Imagionary: CMakeFiles/Imagionary.dir/build.make
Imagionary: CMakeFiles/Imagionary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tanmayarora/CLionProjects/Imagionary/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Imagionary"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Imagionary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Imagionary.dir/build: Imagionary

.PHONY : CMakeFiles/Imagionary.dir/build

CMakeFiles/Imagionary.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Imagionary.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Imagionary.dir/clean

CMakeFiles/Imagionary.dir/depend:
	cd /Users/tanmayarora/CLionProjects/Imagionary/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tanmayarora/CLionProjects/Imagionary /Users/tanmayarora/CLionProjects/Imagionary /Users/tanmayarora/CLionProjects/Imagionary/cmake-build-debug /Users/tanmayarora/CLionProjects/Imagionary/cmake-build-debug /Users/tanmayarora/CLionProjects/Imagionary/cmake-build-debug/CMakeFiles/Imagionary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Imagionary.dir/depend

