# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = "/Users/ssjia/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/ssjia/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Q16__mid.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Q16__mid.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Q16__mid.dir/flags.make

CMakeFiles/Q16__mid.dir/main.cpp.o: CMakeFiles/Q16__mid.dir/flags.make
CMakeFiles/Q16__mid.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Q16__mid.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Q16__mid.dir/main.cpp.o -c /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/main.cpp

CMakeFiles/Q16__mid.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Q16__mid.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/main.cpp > CMakeFiles/Q16__mid.dir/main.cpp.i

CMakeFiles/Q16__mid.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Q16__mid.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/main.cpp -o CMakeFiles/Q16__mid.dir/main.cpp.s

# Object files for target Q16__mid
Q16__mid_OBJECTS = \
"CMakeFiles/Q16__mid.dir/main.cpp.o"

# External object files for target Q16__mid
Q16__mid_EXTERNAL_OBJECTS =

Q16__mid: CMakeFiles/Q16__mid.dir/main.cpp.o
Q16__mid: CMakeFiles/Q16__mid.dir/build.make
Q16__mid: CMakeFiles/Q16__mid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Q16__mid"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Q16__mid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Q16__mid.dir/build: Q16__mid

.PHONY : CMakeFiles/Q16__mid.dir/build

CMakeFiles/Q16__mid.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Q16__mid.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Q16__mid.dir/clean

CMakeFiles/Q16__mid.dir/depend:
	cd /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/cmake-build-debug /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/cmake-build-debug /Users/ssjia/git_Proj/leetcode-jzoffer/Q16-数值的整数次方-mid/cmake-build-debug/CMakeFiles/Q16__mid.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Q16__mid.dir/depend

