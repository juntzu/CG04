# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2017.2.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\chris\Documents\CG04\CPP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\chris\Documents\CG04\CPP\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PerformanceSuite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PerformanceSuite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PerformanceSuite.dir/flags.make

CMakeFiles/PerformanceSuite.dir/main.cpp.obj: CMakeFiles/PerformanceSuite.dir/flags.make
CMakeFiles/PerformanceSuite.dir/main.cpp.obj: CMakeFiles/PerformanceSuite.dir/includes_CXX.rsp
CMakeFiles/PerformanceSuite.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chris\Documents\CG04\CPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PerformanceSuite.dir/main.cpp.obj"
	C:\tools\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PerformanceSuite.dir\main.cpp.obj -c C:\Users\chris\Documents\CG04\CPP\main.cpp

CMakeFiles/PerformanceSuite.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PerformanceSuite.dir/main.cpp.i"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chris\Documents\CG04\CPP\main.cpp > CMakeFiles\PerformanceSuite.dir\main.cpp.i

CMakeFiles/PerformanceSuite.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PerformanceSuite.dir/main.cpp.s"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chris\Documents\CG04\CPP\main.cpp -o CMakeFiles\PerformanceSuite.dir\main.cpp.s

CMakeFiles/PerformanceSuite.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/PerformanceSuite.dir/main.cpp.obj.requires

CMakeFiles/PerformanceSuite.dir/main.cpp.obj.provides: CMakeFiles/PerformanceSuite.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\PerformanceSuite.dir\build.make CMakeFiles/PerformanceSuite.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/PerformanceSuite.dir/main.cpp.obj.provides

CMakeFiles/PerformanceSuite.dir/main.cpp.obj.provides.build: CMakeFiles/PerformanceSuite.dir/main.cpp.obj


CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj: CMakeFiles/PerformanceSuite.dir/flags.make
CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj: CMakeFiles/PerformanceSuite.dir/includes_CXX.rsp
CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj: ../CountLeadingZeros.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chris\Documents\CG04\CPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj"
	C:\tools\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PerformanceSuite.dir\CountLeadingZeros.cpp.obj -c C:\Users\chris\Documents\CG04\CPP\CountLeadingZeros.cpp

CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.i"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chris\Documents\CG04\CPP\CountLeadingZeros.cpp > CMakeFiles\PerformanceSuite.dir\CountLeadingZeros.cpp.i

CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.s"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chris\Documents\CG04\CPP\CountLeadingZeros.cpp -o CMakeFiles\PerformanceSuite.dir\CountLeadingZeros.cpp.s

CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj.requires:

.PHONY : CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj.requires

CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj.provides: CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj.requires
	$(MAKE) -f CMakeFiles\PerformanceSuite.dir\build.make CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj.provides.build
.PHONY : CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj.provides

CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj.provides.build: CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj


# Object files for target PerformanceSuite
PerformanceSuite_OBJECTS = \
"CMakeFiles/PerformanceSuite.dir/main.cpp.obj" \
"CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj"

# External object files for target PerformanceSuite
PerformanceSuite_EXTERNAL_OBJECTS =

PerformanceSuite.exe: CMakeFiles/PerformanceSuite.dir/main.cpp.obj
PerformanceSuite.exe: CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj
PerformanceSuite.exe: CMakeFiles/PerformanceSuite.dir/build.make
PerformanceSuite.exe: CMakeFiles/PerformanceSuite.dir/linklibs.rsp
PerformanceSuite.exe: CMakeFiles/PerformanceSuite.dir/objects1.rsp
PerformanceSuite.exe: CMakeFiles/PerformanceSuite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\chris\Documents\CG04\CPP\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable PerformanceSuite.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PerformanceSuite.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PerformanceSuite.dir/build: PerformanceSuite.exe

.PHONY : CMakeFiles/PerformanceSuite.dir/build

CMakeFiles/PerformanceSuite.dir/requires: CMakeFiles/PerformanceSuite.dir/main.cpp.obj.requires
CMakeFiles/PerformanceSuite.dir/requires: CMakeFiles/PerformanceSuite.dir/CountLeadingZeros.cpp.obj.requires

.PHONY : CMakeFiles/PerformanceSuite.dir/requires

CMakeFiles/PerformanceSuite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PerformanceSuite.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PerformanceSuite.dir/clean

CMakeFiles/PerformanceSuite.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\chris\Documents\CG04\CPP C:\Users\chris\Documents\CG04\CPP C:\Users\chris\Documents\CG04\CPP\cmake-build-debug C:\Users\chris\Documents\CG04\CPP\cmake-build-debug C:\Users\chris\Documents\CG04\CPP\cmake-build-debug\CMakeFiles\PerformanceSuite.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PerformanceSuite.dir/depend

