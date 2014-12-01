PROJECT (TestLib)

CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

FIND_PACKAGE(CUDA REQUIRED)

set (CUDA_NVCC_FLAGS "-arch=sm_13" CACHE STRING "nvcc flags" FORCE)

SET (CUDA_VERBOSE_BUILD ON CACHE BOOL "nvcc verbose" FORCE) 
#HW capability 1.3

SET(LIB_TYPE STATIC)	#set the lib type
CUDA_ADD_LIBRARY(TestLib ${LIB_TYPE} add_vect.h add_vect.cu)


# lib exe for HW capability 1.3
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/build_win64/Release)
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/build_win64/Release)
CUDA_ADD_EXECUTABLE(main_exe main.cpp)
ADD_DEPENDENCIES(main_exe TestLib)
TARGET_LINK_LIBRARIES(main_exe TestLib)


