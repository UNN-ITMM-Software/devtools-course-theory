#############################################
##### Declaring
#############################################

set(libname "moshkov-yuriy-dist-vectors-library")
set(appname "moshkov-yuriy-dist-vectors-sample")
set(testname "moshkov-yuriy-dist-vectors-test")

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

# Declare unit tests
add_app(${testname} "test")
target_link_libraries(${testname})

#############################################
##### Testing
#############################################

include("CTestTests.txt")
