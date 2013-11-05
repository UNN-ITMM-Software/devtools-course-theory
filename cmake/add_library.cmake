
macro(add_lib_shared project_name)
    project(${project_name} CXX)

    set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib/")

    unset(LAST_PROJECT_LIBRARY)
    set(LAST_PROJECT_LIBRARY "${project_name}")

    unset(folders)
    set(folders)

    unset(files)
    set(files)

    foreach(arg ${ARGN})
        if(IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${arg}/")
            list(APPEND folders ${arg})
        else()
            list(APPEND files ${arg})
        endif()
    endforeach()

    status(" ")
    status("---------------------------------------------------")
    status("add_shared_library:")
    status("        name        : [${project_name}]")
    status("        files       : [${files}]")
    status("        folders     : [${folders}]")
    list(LENGTH folders folders_len)
    if(NOT ${folders_len} EQUAL 0)
        get_all_files_for_build(${folders})
    else()
        unset(target_global_list_code)
        unset(target_global_list_moc_code)
    endif()

    add_library          (${project_name} SHARED ${target_global_list_code} ${files} ${target_global_list_moc_obj})
    target_link_libraries(${project_name}        ${target_global_list_libs})

    print_status()
    status("---------------------------------------------------")
    status(" ")
endmacro()

macro(add_lib_static project_name)
    project(${project_name} CXX)

    set(LIBRARY_OUTPUT_PATH "${CMAKE_BINARY_DIR}/lib/")

    unset(LAST_PROJECT_LIBRARY)
    set(LAST_PROJECT_LIBRARY "${project_name}")

    unset(folders)
    set(folders)

    unset(files)
    set(files)

    foreach(arg ${ARGN})
        if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${arg}/")
            list(APPEND folders ${arg})
        else()
            list(APPEND files ${arg})
        endif()
    endforeach()

    status(" ")
    status("---------------------------------------------------")
    status("add_static_library:")
    status("        name        : [${project_name}]")
    status("        files       : [${files}]")
    status("        folders     : [${folders}]")
    list(LENGTH folders folders_len)
    if(NOT ${folders_len} EQUAL 0)
        get_all_files_for_build(${folders})
    else()
        unset(target_global_list_code)
        unset(target_global_list_moc_code)
    endif()

    add_library          (${project_name} STATIC ${target_global_list_code} ${files} ${target_global_list_moc_obj})
    target_link_libraries(${project_name}        ${target_global_list_libs})

    print_status()
    status("---------------------------------------------------")
    status(" ")
endmacro()
