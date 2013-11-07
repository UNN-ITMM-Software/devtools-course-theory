#############################################
##### Declaring
#############################################

set(libname "dmitriy-gorokhov-quadraticequation-library")
set(appname "dmitriy-gorokhov-quadraticequation-sample")

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
