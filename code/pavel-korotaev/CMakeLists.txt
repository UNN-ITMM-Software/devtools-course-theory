#############################################
##### Declaring
#############################################

set(libname "pavel-korotaev-weight-convertor-library")
set(appname "pavel-korotaev-weight-convertor-sample")
set(testname "pavel-korotaev-weight-convertor-test")

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
