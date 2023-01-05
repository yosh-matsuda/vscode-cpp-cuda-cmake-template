cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(my_header_lib CXX)

add_library(my_header_lib INTERFACE)

# Boost
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.65.0.0 REQUIRED)
target_compile_definitions(
  my_header_lib INTERFACE $<$<NOT:$<CONFIG:Debug>>:BOOST_UBLAS_NDEBUG>
  $<$<NOT:$<CONFIG:Debug>>:BOOST_DISABLE_ASSERTS>)
target_include_directories(my_header_lib SYSTEM INTERFACE ${Boost_INCLUDE_DIRS})

# header
target_include_directories(my_header_lib
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
