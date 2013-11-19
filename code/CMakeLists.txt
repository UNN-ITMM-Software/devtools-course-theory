cmake_minimum_required(VERSION 2.8.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/")
include(../cmake/general.cmake)

# Build GoogleTest
#add_dir_inc("${CMAKE_SOURCE_DIR}/../3rdparty/gtest-1.7.0/include")
#add_lib_static(googletest "${CMAKE_SOURCE_DIR}/../3rdparty/gtest-1.7.0/src")

#####################################################

# Enable ExternalProject CMake module
include(ExternalProject)

# Set the build type if it isn't already
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

# Add gtest
ExternalProject_Add(
    googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    SVN_REVISION -r 664
    TIMEOUT 10
    #PATCH_COMMAND svn patch ${CMAKE_SOURCE_DIR}/gtest.patch ${CMAKE_BINARY_DIR}/ThirdParty/src/googletest
    # Force separate output paths for debug and release builds to allow easy
    # identification of correct lib in subsequent TARGET_LINK_LIBRARIES commands
    CMAKE_ARGS -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
               -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
               -Dgtest_force_shared_crt=ON
    # Disable install step
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
include_directories(${source_dir}/include)

#####################################################

# Build our projects
add_all_sub_dir("${CMAKE_SOURCE_DIR}")

# Enable testing
enable_testing()
set(bin_dir "/Users/kirill-kornyakov/Work/GitRepos/devtools-course/build_cmake/bin/")