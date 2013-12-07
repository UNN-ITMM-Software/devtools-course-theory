#Copyright 2013 Ilia Udalov

cmake_minimum_required(VERSION 2.8)

#############################################
##### Declaring
#############################################

set(libname "ilia-udalov-regexlibrary")
set(appname "ilia-udalov-regex-sample")
set(testname "ilia-udalov-regex-test")

message("")
message("############################################")
message("##### Testing ${appname}")
message("############################################")
message("")

#############################################
##### Building
#############################################

# Declare directory with public headers
add_dir_inc("./")

# Declare static library
add_lib_static(${libname} "library" "library/src")

# Declare application
add_local_dependency(${libname})
add_app(${appname} "sample")

# Declare unit tests
add_app(${testname} "test")
target_link_libraries(${testname})

#############################################
##### Testing
#############################################

include("CTestTests.txt")
