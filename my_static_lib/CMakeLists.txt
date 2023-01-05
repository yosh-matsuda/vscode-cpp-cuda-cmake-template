cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(my_static_lib CXX)

file(
  GLOB_RECURSE STATIC_SOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS src/*.c*)
add_library(my_static_lib STATIC ${STATIC_SOURCE_FILES})

# Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.65.0.0 REQUIRED)
target_compile_definitions(
  my_static_lib PRIVATE $<$<NOT:$<CONFIG:Debug>>:BOOST_UBLAS_NDEBUG>
  $<$<NOT:$<CONFIG:Debug>>:BOOST_DISABLE_ASSERTS>)
target_include_directories(my_static_lib SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})

# header
target_include_directories(my_static_lib
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
