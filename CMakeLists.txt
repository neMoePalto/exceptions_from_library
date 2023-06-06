cmake_minimum_required(VERSION 3.5)

project(library_linkage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(library_linkage
  main.cpp
)

add_subdirectory(custom_lib)

target_link_libraries(library_linkage
  custom_lib
)

install(TARGETS library_linkage
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
