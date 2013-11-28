set(project_name "gtest")
project(${project_name})

if((CXX_GCC OR CXX_CLANG) AND (${CMAKE_SYSTEM_NAME} MATCHES "Linux"))
    set(Pthread "-pthread")
endif()

# The idea is that we silence all warnings here, that's why we 
# don't reuse the old value of the CMAKE_CXX_FLAGS variable 
if(CXX_MS)
    set(CMAKE_CXX_FLAGS "/EHsc")
else()
    set(CMAKE_CXX_FLAGS "")
endif()
add_lib_static(${project_name} gtest)
target_link_libraries(${project_name} ${Pthread})
