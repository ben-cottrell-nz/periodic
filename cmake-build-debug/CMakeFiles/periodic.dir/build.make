# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/ben/Downloads/CLion-2021.1.3/clion-2021.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ben/Downloads/CLion-2021.1.3/clion-2021.1.3/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ben/CLionProjects/periodic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ben/CLionProjects/periodic/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/periodic.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/periodic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/periodic.dir/flags.make

CMakeFiles/periodic.dir/main.cpp.o: CMakeFiles/periodic.dir/flags.make
CMakeFiles/periodic.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/periodic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/periodic.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/periodic.dir/main.cpp.o -c /home/ben/CLionProjects/periodic/main.cpp

CMakeFiles/periodic.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/periodic.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/CLionProjects/periodic/main.cpp > CMakeFiles/periodic.dir/main.cpp.i

CMakeFiles/periodic.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/periodic.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/CLionProjects/periodic/main.cpp -o CMakeFiles/periodic.dir/main.cpp.s

CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.o: CMakeFiles/periodic.dir/flags.make
CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.o: /home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ben/CLionProjects/periodic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.o -c /home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp

CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp > CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.i

CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp -o CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.s

# Object files for target periodic
periodic_OBJECTS = \
"CMakeFiles/periodic.dir/main.cpp.o" \
"CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.o"

# External object files for target periodic
periodic_EXTERNAL_OBJECTS =

periodic: CMakeFiles/periodic.dir/main.cpp.o
periodic: CMakeFiles/periodic.dir/home/ben/Documents/repositories/Cinder/blocks/Cairo/src/Cairo.cpp.o
periodic: CMakeFiles/periodic.dir/build.make
periodic: /home/ben/Documents/repositories/Cinder/lib/linux/x86_64/ogl/Debug/libcinder.a
periodic: /usr/lib/x86_64-linux-gnu/libGL.so
periodic: /usr/lib/x86_64-linux-gnu/libGLU.so
periodic: /usr/lib/x86_64-linux-gnu/libSM.so
periodic: /usr/lib/x86_64-linux-gnu/libICE.so
periodic: /usr/lib/x86_64-linux-gnu/libX11.so
periodic: /usr/lib/x86_64-linux-gnu/libXext.so
periodic: /usr/lib/x86_64-linux-gnu/libz.so
periodic: /usr/lib/x86_64-linux-gnu/libcurl.so
periodic: /usr/lib/x86_64-linux-gnu/libfontconfig.so
periodic: /usr/lib/x86_64-linux-gnu/libpulse.so
periodic: /usr/lib/x86_64-linux-gnu/libmpg123.so
periodic: /usr/lib/x86_64-linux-gnu/libsndfile.so
periodic: /usr/lib/x86_64-linux-gnu/libgobject-2.0.so
periodic: /usr/lib/x86_64-linux-gnu/libglib-2.0.so
periodic: /usr/lib/x86_64-linux-gnu/libgstreamer-1.0.so
periodic: /usr/lib/x86_64-linux-gnu/libgstbase-1.0.so
periodic: /usr/lib/x86_64-linux-gnu/libgstapp-1.0.so
periodic: /usr/lib/x86_64-linux-gnu/libgstvideo-1.0.so
periodic: /usr/lib/x86_64-linux-gnu/libgstgl-1.0.so
periodic: CMakeFiles/periodic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ben/CLionProjects/periodic/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable periodic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/periodic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/periodic.dir/build: periodic
.PHONY : CMakeFiles/periodic.dir/build

CMakeFiles/periodic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/periodic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/periodic.dir/clean

CMakeFiles/periodic.dir/depend:
	cd /home/ben/CLionProjects/periodic/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ben/CLionProjects/periodic /home/ben/CLionProjects/periodic /home/ben/CLionProjects/periodic/cmake-build-debug /home/ben/CLionProjects/periodic/cmake-build-debug /home/ben/CLionProjects/periodic/cmake-build-debug/CMakeFiles/periodic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/periodic.dir/depend
