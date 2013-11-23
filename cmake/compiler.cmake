
cmake_minimum_required(VERSION 2.8.6)

################# define compilers #################

if(NOT APPLE)
  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_COMPILER_IS_GNUCXX 1)
  endif()
  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_COMPILER_IS_GNUCC 1)
  endif()
endif()

unset(current_compiler_name)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(CXX_CLANG 1)
  set(current_compiler_name "clang")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(CXX_GCC 1)
  set(current_compiler_name "gcc")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
	set(CXX_INTEL 1)
  set(current_compiler_name "icc")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(CXX_MS 1)
  set(current_compiler_name "msvc")
endif()

###################################################

set_option(ENABLE_C++11                 "Support C++11"                                               ON   )
set_option(ENABLE_PROFILING             "Enable profiling in the GCC compiler (Add flags: -g -pg)"    OFF  IF (CXX_GCC) )
set_option(ENABLE_SSE                   "Enable SSE instructions"                                     OFF  IF (CXX_INTEL OR CXX_GCC OR CXX_CLANG OR CXX_MS) )
set_option(ENABLE_SSE2                  "Enable SSE2 instructions"                                    OFF  IF (CXX_INTEL OR CXX_GCC OR CXX_CLANG OR CXX_MS) )
set_option(ENABLE_SSE3                  "Enable SSE3 instructions"                                    OFF  IF (CXX_INTEL OR CXX_GCC OR CXX_CLANG) )
set_option(ENABLE_SSSE3                 "Enable SSSE3 instructions"                                   OFF  IF (CXX_INTEL OR CXX_GCC OR CXX_CLANG) )
set_option(ENABLE_SSE41                 "Enable SSE4.1 instructions"                                  OFF  IF (CXX_INTEL OR CXX_GCC OR CXX_CLANG) )
set_option(ENABLE_SSE42                 "Enable SSE4.2 instructions"                                  OFF  IF (CXX_INTEL OR CXX_GCC OR CXX_CLANG) )
set_option(ENABLE_AVX                   "Enable AVX instructions"                                     OFF  IF (CXX_INTEL OR CXX_GCC OR CXX_CLANG) )
set_option(ENABLE_AVX2                  "Enable AVX2 instructions"                                    OFF  IF (CXX_INTEL OR CXX_GCC OR CXX_CLANG) )

set_option(ENABLE_OPTIMIZATION          "Enable optimization"                                         OFF  )

set_option(ENABLE_ALLWARNING            "Show all warnings even if they are too noisy"                ON   )
set_option(ENABLE_WARNINGS_ARE_ERRORS   "Treat warnings as errors"                                    ON  )

#set_option(ENABLE_OPENMP                "Enamble OpenMP"                                              ON   IF (CXX_MS OR CXX_GCC OR CXX_INTEL) )
set_option(ENABLE_DEBUG_INFO            "Add debug info"                                              ON   )
set_option(ENABLE_RELEASE               "Build RELEASE"                                               OFF  )
set_option(CMAKE_VERBOSE                "Verbose mode"                                                OFF  )

##################################################

macro(compiler_required compiler_name compiler_version)
  if ("${compiler_name}" STREQUAL "${current_compiler_name}")
    exec_program(${CMAKE_CXX_COMPILER} ARGS --version OUTPUT_VARIABLE current_compiler_output)
    string(REGEX REPLACE ".* ([0-9]\\.[0-9]\\.[0-9]).*" "\\1" current_compiler_version ${current_compiler_output})
    if(${current_compiler_version} VERSION_LESS "${compiler_version}")
      message(FATAL_ERROR "\nCurrent version : ${current_compiler_version}\nRequired the version of compiler >= ${compiler_version}    [${current_compiler_name}]\n\n")
    else()
      message(STATUS "compiler version: ${current_compiler_version} [${current_compiler_name}]")
    endif()
  endif()
endmacro()

############## include all compilers #############

include(compiler_gcc)
include(compiler_clang)
include(compiler_ms)

status("compiler flags: ${CMAKE_CXX_FLAGS}")

###################################################
