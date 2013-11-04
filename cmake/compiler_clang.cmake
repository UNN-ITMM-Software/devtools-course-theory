
# need clang >=3.2

if(CXX_CLANG)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fdiagnostics-show-template-tree ")
    set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -fdiagnostics-show-template-tree ")

    if(${ENABLE_C++11})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -std=c++11 ")
    endif()

    if(${ENABLE_ALLWARNING})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Weverything -pedantic ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -Weverything -pedantic ")
    endif()

    if(${ENABLE_WARNINGS_ARE_ERRORS})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -pedantic-errors ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -Werror -pedantic-errors ")
    endif()

    if(${ENABLE_PROFILING})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -pg ")
    endif()

endif()
