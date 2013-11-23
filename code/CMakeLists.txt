cmake_minimum_required(VERSION 2.8.6)
project (DevTools)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/")
include(../cmake/general.cmake)

# Add Google Test to include
set(gtest "gtest")
set(Pthread "-pthread")
add_dir_inc("3rdparty")

# Build our projects
add_all_sub_dir("${CMAKE_SOURCE_DIR}")  

# Enable testing
enable_testing()
set(bin_dir "/Users/kirill-kornyakov/Work/GitRepos/devtools-course/build_cmake/bin/")