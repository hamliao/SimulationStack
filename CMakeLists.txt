#required cmake minimum realese 
cmake_minimum_required(VERSION 2.8)

#project information
project(StackSimulation)

#add sub directories
add_subdirectory(ut)

#check CXX compile release
include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
if(NOT COMPILER_SUPPORTS_CXX11)
	message(FATAL_ERROR "your g++ is not support for c++11")
endif()
