cmake_minimum_required(VERSION 2.8.6)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../cmake/")
include(../cmake/general.cmake)

#####################################################
# Add GoogleTest
#####################################################

# Enable ExternalProject CMake module
include(ExternalProject)

# Set default ExternalProject root directory
set_directory_properties(PROPERTIES EP_PREFIX ${CMAKE_BINARY_DIR}/ThirdParty)

# Add gtest
ExternalProject_Add(
    googletest
    SVN_REPOSITORY http://googletest.googlecode.com/svn/trunk/
    SVN_REVISION -r 664
    TIMEOUT 10
    #PATCH_COMMAND svn patch ${CMAKE_SOURCE_DIR}/gtest.patch ${CMAKE_BINARY_DIR}/ThirdParty/src/googletest
    CMAKE_ARGS -Dgtest_force_shared_crt=ON
    # Disable install step
    INSTALL_COMMAND ""
    # Wrap download, configure and build steps in a script to log output
    LOG_DOWNLOAD ON
    LOG_CONFIGURE ON
    LOG_BUILD ON)

# Specify include dir
ExternalProject_Get_Property(googletest source_dir)
include_directories(${source_dir}/include)

ExternalProject_Get_Property(googletest binary_dir)
if(MSVC)
  set(Suffix ".lib")
else()
  set(Suffix ".a")
  set(Pthread "-pthread")
endif()

set(gtest "${binary_dir}/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}")

#####################################################

# Build our projects
add_all_sub_dir("${CMAKE_SOURCE_DIR}")

# Enable testing
enable_testing()
set(bin_dir "/Users/kirill-kornyakov/Work/GitRepos/devtools-course/build_cmake/bin/")