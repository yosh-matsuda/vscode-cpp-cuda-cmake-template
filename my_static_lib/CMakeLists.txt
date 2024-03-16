cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(my_static_lib CXX)

file(
  GLOB_RECURSE STATIC_SOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  CONFIGURE_DEPENDS src/*.c*)
add_library(${PROJECT_NAME} STATIC ${STATIC_SOURCE_FILES})

# dependencies
find_package(fmt 10.0.0 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} INTERFACE fmt::fmt-header-only)

# header
target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
