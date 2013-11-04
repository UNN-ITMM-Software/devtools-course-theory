
# need gcc >=4.7.1

if(CXX_GCC)
    if(${ENABLE_WARNINGS_ARE_ERRORS})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -Werror ")
    endif()

    if(${ENABLE_OPTIMIZATION})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -funroll-loops -flto -fschedule-insns -fsched-pressure -march=native ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -Ofast -funroll-loops -flto -fschedule-insns -fsched-pressure -march=native ")
    endif()

    if(${ENABLE_C++11})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wc++11-compat ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -std=c++11 -Wc++11-compat ")
    endif()

    if(${ENABLE_RELEASE})
        set(CMAKE_BUILD_TYPE "Release")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -O3 ")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -O0 ")
        set(ENABLE_DEBUG_INFO ON)
    endif()

    if(${ENABLE_DEBUG_INFO})
        set(CMAKE_BUILD_TYPE "Debug")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3 -ggdb ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -g3 -ggdb ")
    endif()

    if(${ENABLE_ALLWARNING})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Weffc++ -Wconversion -Wsign-conversion -Wold-style-cast -Wunreachable-code -Woverloaded-virtual -Wctor-dtor-privacy -Wnon-virtual-dtor -Wenum-compare -Wshadow -Wformat=2 -Wstrict-overflow=5 ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -Weffc++ -Wconversion -Wsign-conversion -Wold-style-cast -Wunreachable-code -Woverloaded-virtual -Wctor-dtor-privacy -Wnon-virtual-dtor -Wenum-compare -Wshadow -Wformat=2 -Wstrict-overflow=5 ")
    endif()

    if(${ENABLE_PROFILING})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg -fsanitize=address -fsanitize=thread ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -pg -fsanitize=address -fsanitize=thread ")
    endif()

    if(${ENABLE_SSE})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -msse ")
    endif()

    if(${ENABLE_SSE2})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse2 ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -msse2 ")
    endif()

    if(${ENABLE_SSE3})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse3 ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -msse3 ")
    endif()

    if(${ENABLE_SSSE3})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mssse3 ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -mssse3 ")
    endif()

    if(${ENABLE_SSE41})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.1 ")
        set(CMAKE_C_FLAGS   "  ${CMAKE_C_FLAGS} -msse4.1 ")
    endif()

    if(${ENABLE_SSE42})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -msse4.2 ")
        set(CMAKE_C_FLAGS   "  ${CMAKE_C_FLAGS} -msse4.2 ")
    endif()

    if(${ENABLE_AVX})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -mavx ")
    endif()

    if(${ENABLE_AVX2})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx2 ")
        set(CMAKE_C_FLAGS     "${CMAKE_C_FLAGS} -mavx2 ")
    endif()

    if(${ENABLE_OPENMP})
        find_package(OpenMP REQUIRED)
    endif()

endif()
