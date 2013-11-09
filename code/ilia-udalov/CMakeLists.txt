#Copyright 2013 Ilia Udalov

cmake_minimum_required(VERSION 2.8)

#############################################
##### Declaring
#############################################

set(libname "ilia-udalov-regexlibrary")
set(appname "ilia-udalov-regex-sample")

message("")
message("############################################")
message("##### Testing ${appname}")
message("############################################")
message("")

#############################################
##### Building
#############################################

# Declare directory with public headers
add_dir_inc("include")

# Declare static library
add_lib_static(${libname} "src")

# Declare application
add_local_dependency(${libname})
add_app(${appname} "samples")

#############################################
##### Testing
#############################################

include("CTestTests.txt")
