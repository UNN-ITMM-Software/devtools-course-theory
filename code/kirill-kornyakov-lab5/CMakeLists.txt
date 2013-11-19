#############################################
##### Declaring
#############################################

set(libname "kirill-kornyakov-calc2-library")
set(appname "kirill-kornyakov-calc2-sample")
set(testname "kirill-kornyakov-calc-test")

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

#Declare tests
#add_local_dependency("googletest")
add_app(${testname} "test")

ExternalProject_Get_Property(googletest binary_dir)
if(MSVC)
  set(Suffix ".lib")
else()
  set(Suffix ".a")
  set(Pthread "-pthread")
endif()
target_link_libraries(
    ${testname}
    debug ${binary_dir}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}
    optimized ${binary_dir}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${Suffix}
    ${Pthread})

#############################################
##### Testing
#############################################

include("CTestTests.txt")
