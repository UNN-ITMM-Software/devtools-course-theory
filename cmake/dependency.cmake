
macro(clear_dependency)
  unset(target_global_list_libs)
  set(target_global_list_libs)
  set(target_use_qt FALSE)
endmacro()

macro(add_local_dependency)
  foreach(arg ${ARGV})
    list(APPEND target_global_list_libs ${arg})
  endforeach()
endmacro()

macro(add_dependency)
  
  foreach(arg ${ARGV})
    status("Finding library: ${arg}")

    if (arg STREQUAL "opencv")
      find_package(OpenCV REQUIRED)
      list(APPEND target_global_list_libs ${OpenCV_LIBS})


    elseif(arg STREQUAL "eigen3")
      find_package(Eigen3 REQUIRED)
      list(APPEND target_global_list_libs ${EIGEN3_LIBRARIES})


    elseif(arg STREQUAL "ffmpeg")
      find_package(FFMPEG REQUIRED)
      list(APPEND target_global_list_libs ${FFMPEG_LIBRARIES})


    elseif(arg STREQUAL "gtest")
      find_package(GTest REQUIRED)
      list(APPEND target_global_list_libs ${GTEST_LIBRARIES})


    elseif(arg STREQUAL "pat")
      find_package(PAT REQUIRED)
      list(APPEND target_global_list_libs ${PAT_LIBS})


    elseif(arg STREQUAL "webp")
      find_package(WebP REQUIRED)
      list(APPEND target_global_list_libs ${WEBP_LIBRARIES})


    elseif(arg STREQUAL "vpx")
      find_package(Vpx REQUIRED)
      list(APPEND target_global_list_libs ${VPX_LIBRARIES})


    elseif(arg STREQUAL "ant")
      include(cmake/find_ant.cmake REQUIRED)


    elseif(arg STREQUAL "android-ndk")
      include(cmake/find_android_ndk.cmake REQUIRED)


    elseif(arg STREQUAL "mlib")
      find_package(mlib REQUIRED)
      list(APPEND target_global_list_libs ${MLIB_LIBS})


    elseif(arg STREQUAL "sdl")
      find_package(SDL REQUIRED)
      list(APPEND target_global_list_libs ${SDL_LIBRARY})


    elseif(arg STREQUAL "pthread")
      find_package(Threads REQUIRED)
      list(APPEND target_global_list_libs ${CMAKE_THREAD_LIBS_INIT})


    elseif(arg STREQUAL "qt4")
      set(target_use_qt TRUE)
      find_package(Qt4 4.8.0 COMPONENTS QtCore QtGui QtOpenGL QtScript QtNetwork QtTest REQUIRED)
      include(${QT_USE_FILE})
      include_directories( ${QT_INCLUDE_DIR} )
      list(APPEND target_global_list_libs ${QT_LIBRARIES})


    elseif(arg STREQUAL "tbb")
      find_package(TBB REQUIRED)
      list(APPEND target_global_list_libs ${TBB_LIBRARIES})


    elseif(arg STREQUAL "opengl")
      find_package(OpenGL REQUIRED)
      list(APPEND target_global_list_libs ${OPENGL_LIBRARIES})
      find_package(GLEW REQUIRED)
      list(APPEND target_global_list_libs ${GLEW_LIBRARIES})

    elseif(arg STREQUAL "freeglut")
      find_package(FreeGLUT REQUIRED)
      include_directories(${FREEGLUT_INCLUDE_DIRS})
      list(APPEND target_global_list_libs ${FREEGLUT_LIBRARIES})


    else()
      add_local_dependency(${arg})
    endif()
  endforeach()

endmacro()

macro(set_dependency)
  clear_dependency()
  add_dependency(${ARGV})
endmacro()

