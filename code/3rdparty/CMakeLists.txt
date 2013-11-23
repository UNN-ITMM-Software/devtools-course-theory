# Add Google Test

if(CXX_MS)
    set(CMAKE_CXX_FLAGS "/EHsc")
else()
    set(CMAKE_CXX_FLAGS "")
endif()

add_lib_static(${gtest} "gtest")
