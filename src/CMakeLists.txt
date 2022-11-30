# Path definitions.
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR})

# Add overall src library.
file(GLOB_RECURSE src_sources CONFIGURE_DEPENDS ${src_dir}/*.cpp ${src_dir}/*.hpp)
add_library(src ${src_sources})
add_library(adjacency_list.h ${src_sources})
add_library(adjacency_list.cpp ${src_sources})
add_library(airport.h ${src_sources})
add_library(airport.cpp ${src_sources})
add_library(flight.h ${src_sources})
add_library(flight.cpp ${src_sources})
add_library(bfs.h ${src_sources})
add_library(bfs.cpp ${src_sources})
add_library(utils.h ${src_sources})
add_library(utils.cpp ${src_sources})
target_include_directories(src PUBLIC ${src_dir})
target_link_libraries(src PRIVATE libs)