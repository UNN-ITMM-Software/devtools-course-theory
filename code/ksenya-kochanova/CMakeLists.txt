#############################################
##### Declaring
#############################################

set(libname "ksenya-kochanova-temperatureConv-library")
set(appname "ksenya-kochanova-temperatureConv-samples")
set(testname "ksenya-kochanova-temperatureConv-test")

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
add_app(${appname} "samples")

# Declare unit test
add_app(${app_name} "test")
target_link_libraries(${testname} ${gtest})

#############################################
##### Testing
#############################################

include("CTestTests.txt")