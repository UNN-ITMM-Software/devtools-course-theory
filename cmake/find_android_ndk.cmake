
if(NOT COMMAND find_host_program)
  macro(find_host_program)
    find_program(${ARGN})
  endmacro()
endif()

if(EXISTS "${ANDROID_EXECUTABLE}")
  set(ANDROID_SDK_DETECT_QUIET TRUE)
endif()

file(TO_CMAKE_PATH "$ENV{ProgramFiles}" ProgramFiles_ENV_PATH)
file(TO_CMAKE_PATH "$ENV{HOME}" HOME_ENV_PATH)

if(CMAKE_HOST_WIN32)
  set(ANDROID_NDK_NAME ndk-build.exe)
else()
  set(ANDROID_NDK_NAME ndk-build)
endif()

if(CMAKE_HOST_WIN32)
  set(ANDROID_SDK_OS windows)
elseif(CMAKE_HOST_APPLE)
  set(ANDROID_SDK_OS macosx)
else()
  set(ANDROID_SDK_OS linux)
endif()

#find android SDK: search in ANDROID_SDK first
find_host_program(ANDROID_EXECUTABLE
  NAMES android.bat android
  PATH_SUFFIXES tools
  PATHS
    ENV ANDROID_SDK
  DOC "Android SDK location"
  NO_DEFAULT_PATH
  )

# Now search default paths
find_host_program(ANDROID_EXECUTABLE
  NAMES android.bat android
  PATH_SUFFIXES android-sdk-${ANDROID_SDK_OS}/tools
                android-sdk-${ANDROID_SDK_OS}_x86/tools
                android-sdk-${ANDROID_SDK_OS}_86/tools
                android-sdk/tools
  PATHS /opt
        "${HOME_ENV_PATH}/NVPACK"
        "$ENV{SystemDrive}/NVPACK"
        "${ProgramFiles_ENV_PATH}/Android"
  DOC "Android SDK location"
  )

if(ANDROID_EXECUTABLE)
  if(NOT ANDROID_SDK_DETECT_QUIET)
    message(STATUS "Found android tool: ${ANDROID_EXECUTABLE}")
  endif()

  get_filename_component(ANDROID_SDK_TOOLS_PATH "${ANDROID_EXECUTABLE}" PATH)

  #read source.properties
  if(EXISTS "${ANDROID_SDK_TOOLS_PATH}/source.properties")
    file(STRINGS "${ANDROID_SDK_TOOLS_PATH}/source.properties" ANDROID_SDK_TOOLS_SOURCE_PROPERTIES_LINES REGEX "^[ ]*[^#].*$")
    foreach(line ${ANDROID_SDK_TOOLS_SOURCE_PROPERTIES_LINES})
      string(REPLACE "\\:" ":" line ${line})
      string(REPLACE "=" ";" line ${line})
      list(GET line 0 line_name)
      list(GET line 1 line_value)
      string(REPLACE "." "_" line_name ${line_name})
      SET(ANDROID_TOOLS_${line_name} "${line_value}" CACHE INTERNAL "from ${ANDROID_SDK_TOOLS_PATH}/source.properties")
      MARK_AS_ADVANCED(ANDROID_TOOLS_${line_name})
    endforeach()
  endif()

  #fix missing revision (SDK tools before r9 don't set revision number correctly)
  if(NOT ANDROID_TOOLS_Pkg_Revision)
    SET(ANDROID_TOOLS_Pkg_Revision "Unknown" CACHE INTERNAL "")
    MARK_AS_ADVANCED(ANDROID_TOOLS_Pkg_Revision)
  endif()

  status("Android Tools : ${ANDROID_TOOLS_Pkg_Revision} revision")

  #fix missing description
  if(NOT ANDROID_TOOLS_Pkg_Desc)
    SET(ANDROID_TOOLS_Pkg_Desc "Android SDK Tools, revision ${ANDROID_TOOLS_Pkg_Revision}." CACHE INTERNAL "")
    MARK_AS_ADVANCED(ANDROID_TOOLS_Pkg_Desc)
  endif()

  #warn about outdated SDK
  if(NOT ANDROID_TOOLS_Pkg_Revision GREATER 13)
    message(FATAL_ERROR "It is recommended to update your SDK tools to revision 14 or newer.")
  endif()

  SET(ANDROID_PROJECT_PROPERTIES_FILE project.properties)
  SET(ANDROID_ANT_PROPERTIES_FILE ant.properties)

  set(ANDROID_MANIFEST_FILE AndroidManifest.xml)
  set(ANDROID_LIB_PROJECT_FILES build.xml local.properties proguard-project.txt ${ANDROID_PROJECT_PROPERTIES_FILE})
  set(ANDROID_PROJECT_FILES ${ANDROID_LIB_PROJECT_FILES})

  #get installed targets
  execute_process(COMMAND ${ANDROID_EXECUTABLE} list target -c
    RESULT_VARIABLE ANDROID_PROCESS
    OUTPUT_VARIABLE ANDROID_SDK_TARGETS
    ERROR_VARIABLE ANDROID_PROCESS_ERRORS
    OUTPUT_STRIP_TRAILING_WHITESPACE
    )
  string(REGEX MATCHALL "[^\n]+" ANDROID_SDK_TARGETS "${ANDROID_SDK_TARGETS}")

  if(NOT ANDROID_PROCESS EQUAL 0)
    message(ERROR "Failed to get list of installed Android targets.")
    set(ANDROID_EXECUTABLE "ANDROID_EXECUTABLE-NOTFOUND")
  endif()

  # clear ANDROID_SDK_TARGET if no target is provided by user
  if(NOT ANDROID_SDK_TARGET)
    set(ANDROID_SDK_TARGET "" CACHE STRING "Android SDK target for the OpenCV Java API and samples")
  endif()
  if(ANDROID_SDK_TARGETS AND CMAKE_VERSION VERSION_GREATER "2.8")
    set_property(CACHE ANDROID_SDK_TARGET PROPERTY STRINGS ${ANDROID_SDK_TARGETS})
  endif()
endif(ANDROID_EXECUTABLE)
