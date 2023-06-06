cmake_minimum_required(VERSION 3.5)

project(custom_lib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(custom_lib
  manager.cpp
  manager.h
  worker.cpp
  worker.h
)

install(TARGETS custom_lib
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
