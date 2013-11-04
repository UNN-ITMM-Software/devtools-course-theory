

#MSVC_VERSION >= "1600"

if(CXX_MS)
	include(ProcessorCount)
	ProcessorCount(N)
	if(NOT N EQUAL 0)
	    SET(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   /MP${N} ")
	    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP${N} ")
	endif()

	if(${ENABLE_SSE})
	    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  /arch:SSE ")
	    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}    /arch:SSE ")
	endif()

	if(${ENABLE_SSE2})
	    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  /arch:SSE2 ")
	    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}    /arch:SSE2 ")
	endif()

	if(${ENABLE_OPENMP})
	    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  /openmp ")
	    set(CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}    /openmp ")
	endif()
endif()