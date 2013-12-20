#############################################
##### Declaring
#############################################

set(libname "kirill-nikolaev-numconverter-library")
set(appname "kirill-nikolaev-numconverter-sample")
set(testname "kirill-nikolaev-numconverter-test")

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