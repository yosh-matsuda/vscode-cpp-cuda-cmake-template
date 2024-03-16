cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(my_shared_lib CXX)

file(
  GLOB_RECURSE SHARED_SOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  CONFIGURE_DEPENDS src/*.c*)
add_library(${PROJECT_NAME} SHARED ${SHARED_SOURCE_FILES})

# dependencies
find_package(fmt 10.0.0 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt-header-only)

# header
target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# exports
if(WIN32)
  target_compile_definitions(${PROJECT_NAME} PRIVATE MY_SHARED_LIB_BUILD_DLL)
endif()
