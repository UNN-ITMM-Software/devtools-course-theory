cmake_minimum_required(VERSION 2.8)

project(Sorter)

include_directories("./include/")

set(HEADERS
  "./include/sort.h"
  )

set(SOURCES
  "./samples/sample.cpp"
  "./src/sort.cpp"
  )				

add_executable(Sorter
  ${HEADERS}
  ${SOURCES}
  )
  