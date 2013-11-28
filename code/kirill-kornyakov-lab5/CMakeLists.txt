#############################################
##### Declaring
#############################################

set(libname "kirill-kornyakov-ccalc-library")
set(appname "kirill-kornyakov-ccalc-sample")
set(testname "kirill-kornyakov-ccalc-test")

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
