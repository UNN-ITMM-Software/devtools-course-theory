
#####################################################################
# 
# list of global variables:
# 
# * target_name (str)
# * target_global_list_libs (list)
# * target_use_qt (bool)
# * target_global_list_code (list)
# * target_global_list_moc_code (list)
# * target_global_list_moc_obj (list)
# 
#####################################################################







#####################################################################
#
# --------------------- LIST OF GLOBAL FUNCTION ---------------------
#
#####################################################################


#####################################################################
# * add_dir_lib("dir name1" "dir name2" ...)
#
#####################################################################


#####################################################################
# * add_dir_inc("dir name1" "dir name2" ...)
#
#####################################################################


#####################################################################
# * add_apps("dir name")
#
#####################################################################


#####################################################################
# * add_app("name" "dir or file" ...)
#
#####################################################################


#####################################################################
# * add_lib("name" "dir or file" ...)
#
#####################################################################


#####################################################################
# * set_solution("solution name")
#
#####################################################################


#####################################################################
# * set_option(NAME  "Description"  VALUE (CONDITION))
#       NAME "Description"
#       VALUE: ON, OFF
#
#   example:
#       set_option(ENABLE_PROFILING  "Enable profiling in the GCC compiler"  OFF  IF (CXX_GCC))
#       set_option(CMAKE_VERBOSE     "Verbose mode"                          ON)
#
#####################################################################


#####################################################################
# * compiler_required("name compiler" "version")
#####################################################################
#       name compiler: gcc, icc, clang, msvc; version: "X.Y.Z"
#
#   example:
#       compiler_required("gcc"   "4.7.3")
#       compiler_required("clang" "3.2")
#
#####################################################################


#####################################################################
# * clear_dependency()
#
# * add_local_dependency("name1" "name2")
#    not used find_package()
#
# * add_dependency("name1" "name2" ...)
#
# * set_dependency("name1" "name2" ...)
#   {
#       clear_dependency()
#       add_dependency("name1" ...)
#   }
#
#####################################################################


#####################################################################
# * create_cmake_module("module_name")
#
#####################################################################


#####################################################################
#----------------------------- TEMPLATE ----------------------------#
#####################################################################
#
# cmake_minimum_required(VERSION 2.8.6)
# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
# include(cmake/general.cmake)
# 
#####################################################################

macro(set_solution name)
  set(target_name ${name})
  project(${target_name})
endmacro()

include(project_utils REQUIRED)
include(dependency REQUIRED)

include(config REQUIRED)

include(status REQUIRED)
include(compiler REQUIRED)

macro(print_status)
    status("    sources: ")
    foreach(s ${target_global_list_code})
        status("        ${s}")
    endforeach()

    status("    libraries: ")
    foreach(l ${target_global_list_libs})
    	if((${l} STREQUAL "debug") OR (${l} STREQUAL "optimized"))
    		
    	else()
    		status("        ${l}")
    	endif()
    endforeach()

    if (target_use_qt)
        status("    moc objects: ")
        foreach(m ${target_global_list_moc_obj})
            status("        ${m}")
        endforeach()
    endif()
endmacro()

include(add_library REQUIRED)
include(add_application REQUIRED)
include(android REQUIRED)
