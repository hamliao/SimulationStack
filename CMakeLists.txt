#required cmake minimum realese 
cmake_minimum_required(VERSION 3.0)

#project information
project(StackSimulation)

#add sub directories
add_subdirectory(ut)

if (CMAKE_COMPILER_IS_GUNCXX)
	add_compile_options(-std=c++11)
	add_compile_options(-Wall)
	add_compile_options(-g)
endif(CMAKE_COMPILER_IS_GUNCXX)
