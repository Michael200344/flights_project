# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.22
cmake_policy(SET CMP0009 NEW)

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS225/flights_project/src/*.cpp")
set(OLD_GLOB
  "/workspaces/CS225/flights_project/src/adjacency_list.cpp"
  "/workspaces/CS225/flights_project/src/airport.cpp"
  "/workspaces/CS225/flights_project/src/bfs.cpp"
  "/workspaces/CS225/flights_project/src/flight.cpp"
  "/workspaces/CS225/flights_project/src/utils.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS225/flights_project/build/CMakeFiles/cmake.verify_globs")
endif()

# src_sources at src/CMakeLists.txt:5 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS225/flights_project/src/*.hpp")
set(OLD_GLOB
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS225/flights_project/build/CMakeFiles/cmake.verify_globs")
endif()

# tests_src at CMakeLists.txt:130 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/workspaces/CS225/flights_project/tests/*.cpp")
set(OLD_GLOB
  "/workspaces/CS225/flights_project/tests/tests.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/workspaces/CS225/flights_project/build/CMakeFiles/cmake.verify_globs")
endif()
