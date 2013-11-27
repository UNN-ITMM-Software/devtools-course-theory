cmake_minimum_required(VERSION 2.8.6)
project (DevTools)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/")
include(../cmake/general.cmake)

# Google Test
include_directories(SYSTEM "3rdparty")
add_subdirectory("3rdparty")

clear_dependency()
add_local_dependency("gtest")

# Include subprojects
add_all_sub_dir("${CMAKE_SOURCE_DIR}" except "3rdparty")

# Enable testing
enable_testing()