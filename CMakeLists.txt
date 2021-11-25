cmake_minimum_required(VERSION 3.0.0)
project(Segeom VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

add_executable(Segeom Segeom.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# add_library(GeometricFault)

# target_link_libraries(Segeom PUBLIC GeometricFault)

target_include_directories(Segeom PUBLIC 
  "${PROJECT_BINARY_DIR}" 
  "${PROJECT_SOURCE_DIR}/GeometricFault")