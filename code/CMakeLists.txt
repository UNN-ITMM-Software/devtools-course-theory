cmake_minimum_required(VERSION 2.8.6)
project (DevTools)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/")
include(../cmake/general.cmake)

# Add Google Test includes and define some variables
add_dir_inc("3rdparty")
set(gtest "gtest")
if(CXX_GCC OR CXX_CLANG)
    set(Pthread "-pthread")
endif()

# Include subprojects
add_all_sub_dir("${CMAKE_SOURCE_DIR}")  

# Enable testing
enable_testing()
