cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(my_shared_lib CXX)

file(
  GLOB_RECURSE SHARED_SOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS src/*.c*)
add_library(my_shared_lib SHARED ${SHARED_SOURCE_FILES})

# Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.65.0.0 REQUIRED)
target_compile_definitions(
  my_shared_lib PRIVATE $<$<NOT:$<CONFIG:Debug>>:BOOST_UBLAS_NDEBUG>
  $<$<NOT:$<CONFIG:Debug>>:BOOST_DISABLE_ASSERTS>)
target_include_directories(my_shared_lib SYSTEM PRIVATE ${Boost_INCLUDE_DIRS})

# header
target_include_directories(my_shared_lib
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
