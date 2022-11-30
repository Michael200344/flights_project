# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /workspaces/CS225/flights_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/CS225/flights_project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/airport.h.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/airport.h.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/airport.h.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/airport.h.dir/flags.make

src/CMakeFiles/airport.h.dir/adjacency_list.cpp.o: src/CMakeFiles/airport.h.dir/flags.make
src/CMakeFiles/airport.h.dir/adjacency_list.cpp.o: ../src/adjacency_list.cpp
src/CMakeFiles/airport.h.dir/adjacency_list.cpp.o: src/CMakeFiles/airport.h.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/flights_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/airport.h.dir/adjacency_list.cpp.o"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/airport.h.dir/adjacency_list.cpp.o -MF CMakeFiles/airport.h.dir/adjacency_list.cpp.o.d -o CMakeFiles/airport.h.dir/adjacency_list.cpp.o -c /workspaces/CS225/flights_project/src/adjacency_list.cpp

src/CMakeFiles/airport.h.dir/adjacency_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/airport.h.dir/adjacency_list.cpp.i"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/flights_project/src/adjacency_list.cpp > CMakeFiles/airport.h.dir/adjacency_list.cpp.i

src/CMakeFiles/airport.h.dir/adjacency_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/airport.h.dir/adjacency_list.cpp.s"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/flights_project/src/adjacency_list.cpp -o CMakeFiles/airport.h.dir/adjacency_list.cpp.s

src/CMakeFiles/airport.h.dir/airport.cpp.o: src/CMakeFiles/airport.h.dir/flags.make
src/CMakeFiles/airport.h.dir/airport.cpp.o: ../src/airport.cpp
src/CMakeFiles/airport.h.dir/airport.cpp.o: src/CMakeFiles/airport.h.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/flights_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/airport.h.dir/airport.cpp.o"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/airport.h.dir/airport.cpp.o -MF CMakeFiles/airport.h.dir/airport.cpp.o.d -o CMakeFiles/airport.h.dir/airport.cpp.o -c /workspaces/CS225/flights_project/src/airport.cpp

src/CMakeFiles/airport.h.dir/airport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/airport.h.dir/airport.cpp.i"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/flights_project/src/airport.cpp > CMakeFiles/airport.h.dir/airport.cpp.i

src/CMakeFiles/airport.h.dir/airport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/airport.h.dir/airport.cpp.s"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/flights_project/src/airport.cpp -o CMakeFiles/airport.h.dir/airport.cpp.s

src/CMakeFiles/airport.h.dir/bfs.cpp.o: src/CMakeFiles/airport.h.dir/flags.make
src/CMakeFiles/airport.h.dir/bfs.cpp.o: ../src/bfs.cpp
src/CMakeFiles/airport.h.dir/bfs.cpp.o: src/CMakeFiles/airport.h.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/flights_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/airport.h.dir/bfs.cpp.o"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/airport.h.dir/bfs.cpp.o -MF CMakeFiles/airport.h.dir/bfs.cpp.o.d -o CMakeFiles/airport.h.dir/bfs.cpp.o -c /workspaces/CS225/flights_project/src/bfs.cpp

src/CMakeFiles/airport.h.dir/bfs.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/airport.h.dir/bfs.cpp.i"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/flights_project/src/bfs.cpp > CMakeFiles/airport.h.dir/bfs.cpp.i

src/CMakeFiles/airport.h.dir/bfs.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/airport.h.dir/bfs.cpp.s"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/flights_project/src/bfs.cpp -o CMakeFiles/airport.h.dir/bfs.cpp.s

src/CMakeFiles/airport.h.dir/flight.cpp.o: src/CMakeFiles/airport.h.dir/flags.make
src/CMakeFiles/airport.h.dir/flight.cpp.o: ../src/flight.cpp
src/CMakeFiles/airport.h.dir/flight.cpp.o: src/CMakeFiles/airport.h.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/flights_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/airport.h.dir/flight.cpp.o"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/airport.h.dir/flight.cpp.o -MF CMakeFiles/airport.h.dir/flight.cpp.o.d -o CMakeFiles/airport.h.dir/flight.cpp.o -c /workspaces/CS225/flights_project/src/flight.cpp

src/CMakeFiles/airport.h.dir/flight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/airport.h.dir/flight.cpp.i"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/flights_project/src/flight.cpp > CMakeFiles/airport.h.dir/flight.cpp.i

src/CMakeFiles/airport.h.dir/flight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/airport.h.dir/flight.cpp.s"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/flights_project/src/flight.cpp -o CMakeFiles/airport.h.dir/flight.cpp.s

src/CMakeFiles/airport.h.dir/utils.cpp.o: src/CMakeFiles/airport.h.dir/flags.make
src/CMakeFiles/airport.h.dir/utils.cpp.o: ../src/utils.cpp
src/CMakeFiles/airport.h.dir/utils.cpp.o: src/CMakeFiles/airport.h.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/flights_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/airport.h.dir/utils.cpp.o"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/airport.h.dir/utils.cpp.o -MF CMakeFiles/airport.h.dir/utils.cpp.o.d -o CMakeFiles/airport.h.dir/utils.cpp.o -c /workspaces/CS225/flights_project/src/utils.cpp

src/CMakeFiles/airport.h.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/airport.h.dir/utils.cpp.i"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/flights_project/src/utils.cpp > CMakeFiles/airport.h.dir/utils.cpp.i

src/CMakeFiles/airport.h.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/airport.h.dir/utils.cpp.s"
	cd /workspaces/CS225/flights_project/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/flights_project/src/utils.cpp -o CMakeFiles/airport.h.dir/utils.cpp.s

# Object files for target airport.h
airport_h_OBJECTS = \
"CMakeFiles/airport.h.dir/adjacency_list.cpp.o" \
"CMakeFiles/airport.h.dir/airport.cpp.o" \
"CMakeFiles/airport.h.dir/bfs.cpp.o" \
"CMakeFiles/airport.h.dir/flight.cpp.o" \
"CMakeFiles/airport.h.dir/utils.cpp.o"

# External object files for target airport.h
airport_h_EXTERNAL_OBJECTS =

src/libairport.h.a: src/CMakeFiles/airport.h.dir/adjacency_list.cpp.o
src/libairport.h.a: src/CMakeFiles/airport.h.dir/airport.cpp.o
src/libairport.h.a: src/CMakeFiles/airport.h.dir/bfs.cpp.o
src/libairport.h.a: src/CMakeFiles/airport.h.dir/flight.cpp.o
src/libairport.h.a: src/CMakeFiles/airport.h.dir/utils.cpp.o
src/libairport.h.a: src/CMakeFiles/airport.h.dir/build.make
src/libairport.h.a: src/CMakeFiles/airport.h.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/CS225/flights_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libairport.h.a"
	cd /workspaces/CS225/flights_project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/airport.h.dir/cmake_clean_target.cmake
	cd /workspaces/CS225/flights_project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/airport.h.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/airport.h.dir/build: src/libairport.h.a
.PHONY : src/CMakeFiles/airport.h.dir/build

src/CMakeFiles/airport.h.dir/clean:
	cd /workspaces/CS225/flights_project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/airport.h.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/airport.h.dir/clean

src/CMakeFiles/airport.h.dir/depend:
	cd /workspaces/CS225/flights_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/CS225/flights_project /workspaces/CS225/flights_project/src /workspaces/CS225/flights_project/build /workspaces/CS225/flights_project/build/src /workspaces/CS225/flights_project/build/src/CMakeFiles/airport.h.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/airport.h.dir/depend

