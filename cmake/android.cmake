
################################################################################
# NOTE:
#
# to update project run from android directory of the project:
#    android update project --target android-11 --path . --library ../sdk/java
#
# to update opencv run from "sdk/java":
#    android update lib-project --target android-11 --path .
#
################################################################################

macro(add_android project_name path_to_android_project)

    set(path_to_android "${CMAKE_SOURCE_DIR}/${path_to_android_project}")

    add_custom_target( ${project_name}
                    COMMAND ${ANT_EXECUTABLE} -q -noinput -k clean
                    COMMAND ${ANT_EXECUTABLE} -q -noinput -k debug
                    # ant does not update the timestamp of updated apk
                    COMMAND ${CMAKE_COMMAND}  -E touch
                    "${path_to_android}/bin/${project_name}-debug.apk"
                    COMMAND ${CMAKE_COMMAND}  -E copy
                    "${path_to_android}/bin/${project_name}-debug.apk"
                    "${CMAKE_CURRENT_BINARY_DIR}/${project_name}.apk"
                    WORKING_DIRECTORY "${path_to_android}"
                    COMMENT "Generating ${project_name}"
    )

    if(EXISTS "${path_to_android}/jni/Android.mk")
        add_custom_target("${project_name}_ndk"
            COMMAND ndk-build clean
            COMMAND ndk-build -j8
            WORKING_DIRECTORY "${path_to_android}"
            COMMENT "ndk-build"
        )
        add_dependencies(${project_name} "${project_name}_ndk")
    endif()

endmacro()
