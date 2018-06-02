#include directories
include_directories ("${PROJECT_SOURCE_DIR}/includes/interface")
include_directories ("${PROJECT_SOURCE_DIR}/includes/protocol")
include_directories ("${PROJECT_SOURCE_DIR}/gtestlibs")

#include link directories
link_directories ("${PROJECT_SOURCE_DIR}/gtestlibs")

#add gtest link
link_libraries(libgtest.a libgtest_main.a)

#add other link
link_libraries(pthread)

#generate executable file
add_executable (gtest gtest.cpp)

#add c++ compile flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -ggdb")
