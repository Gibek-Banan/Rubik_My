# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\arekj\OneDrive\Pulpit\Rubik_My

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build

# Include any dependencies generated for this target.
include CMakeFiles/Exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exe.dir/flags.make

CMakeFiles/Exe.dir/src/main.cpp.obj: CMakeFiles/Exe.dir/flags.make
CMakeFiles/Exe.dir/src/main.cpp.obj: ../src/main.cpp
CMakeFiles/Exe.dir/src/main.cpp.obj: CMakeFiles/Exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Exe.dir/src/main.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Exe.dir/src/main.cpp.obj -MF CMakeFiles\Exe.dir\src\main.cpp.obj.d -o CMakeFiles\Exe.dir\src\main.cpp.obj -c C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\main.cpp

CMakeFiles/Exe.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exe.dir/src/main.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\main.cpp > CMakeFiles\Exe.dir\src\main.cpp.i

CMakeFiles/Exe.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exe.dir/src/main.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\main.cpp -o CMakeFiles\Exe.dir\src\main.cpp.s

CMakeFiles/Exe.dir/src/Rubik.cpp.obj: CMakeFiles/Exe.dir/flags.make
CMakeFiles/Exe.dir/src/Rubik.cpp.obj: ../src/Rubik.cpp
CMakeFiles/Exe.dir/src/Rubik.cpp.obj: CMakeFiles/Exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Exe.dir/src/Rubik.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Exe.dir/src/Rubik.cpp.obj -MF CMakeFiles\Exe.dir\src\Rubik.cpp.obj.d -o CMakeFiles\Exe.dir\src\Rubik.cpp.obj -c C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Rubik.cpp

CMakeFiles/Exe.dir/src/Rubik.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exe.dir/src/Rubik.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Rubik.cpp > CMakeFiles\Exe.dir\src\Rubik.cpp.i

CMakeFiles/Exe.dir/src/Rubik.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exe.dir/src/Rubik.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Rubik.cpp -o CMakeFiles\Exe.dir\src\Rubik.cpp.s

CMakeFiles/Exe.dir/src/Wall.cpp.obj: CMakeFiles/Exe.dir/flags.make
CMakeFiles/Exe.dir/src/Wall.cpp.obj: ../src/Wall.cpp
CMakeFiles/Exe.dir/src/Wall.cpp.obj: CMakeFiles/Exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Exe.dir/src/Wall.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Exe.dir/src/Wall.cpp.obj -MF CMakeFiles\Exe.dir\src\Wall.cpp.obj.d -o CMakeFiles\Exe.dir\src\Wall.cpp.obj -c C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Wall.cpp

CMakeFiles/Exe.dir/src/Wall.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exe.dir/src/Wall.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Wall.cpp > CMakeFiles\Exe.dir\src\Wall.cpp.i

CMakeFiles/Exe.dir/src/Wall.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exe.dir/src/Wall.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Wall.cpp -o CMakeFiles\Exe.dir\src\Wall.cpp.s

CMakeFiles/Exe.dir/src/Element.cpp.obj: CMakeFiles/Exe.dir/flags.make
CMakeFiles/Exe.dir/src/Element.cpp.obj: ../src/Element.cpp
CMakeFiles/Exe.dir/src/Element.cpp.obj: CMakeFiles/Exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Exe.dir/src/Element.cpp.obj"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Exe.dir/src/Element.cpp.obj -MF CMakeFiles\Exe.dir\src\Element.cpp.obj.d -o CMakeFiles\Exe.dir\src\Element.cpp.obj -c C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Element.cpp

CMakeFiles/Exe.dir/src/Element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Exe.dir/src/Element.cpp.i"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Element.cpp > CMakeFiles\Exe.dir\src\Element.cpp.i

CMakeFiles/Exe.dir/src/Element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Exe.dir/src/Element.cpp.s"
	C:\PROGRA~1\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\arekj\OneDrive\Pulpit\Rubik_My\src\Element.cpp -o CMakeFiles\Exe.dir\src\Element.cpp.s

# Object files for target Exe
Exe_OBJECTS = \
"CMakeFiles/Exe.dir/src/main.cpp.obj" \
"CMakeFiles/Exe.dir/src/Rubik.cpp.obj" \
"CMakeFiles/Exe.dir/src/Wall.cpp.obj" \
"CMakeFiles/Exe.dir/src/Element.cpp.obj"

# External object files for target Exe
Exe_EXTERNAL_OBJECTS =

Exe.exe: CMakeFiles/Exe.dir/src/main.cpp.obj
Exe.exe: CMakeFiles/Exe.dir/src/Rubik.cpp.obj
Exe.exe: CMakeFiles/Exe.dir/src/Wall.cpp.obj
Exe.exe: CMakeFiles/Exe.dir/src/Element.cpp.obj
Exe.exe: CMakeFiles/Exe.dir/build.make
Exe.exe: CMakeFiles/Exe.dir/linklibs.rsp
Exe.exe: CMakeFiles/Exe.dir/objects1.rsp
Exe.exe: CMakeFiles/Exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Exe.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Exe.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exe.dir/build: Exe.exe
.PHONY : CMakeFiles/Exe.dir/build

CMakeFiles/Exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Exe.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Exe.dir/clean

CMakeFiles/Exe.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\arekj\OneDrive\Pulpit\Rubik_My C:\Users\arekj\OneDrive\Pulpit\Rubik_My C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build C:\Users\arekj\OneDrive\Pulpit\Rubik_My\build\CMakeFiles\Exe.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Exe.dir/depend
