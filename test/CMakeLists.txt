cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(my_library_test CXX)

# Google Test
find_package(GTest CONFIG REQUIRED)

file(
  GLOB_RECURSE TEST_SOURCE_FILES
  RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS src/*.c*)
add_executable(my_library_test ${TEST_SOURCE_FILES})
target_link_libraries(
  my_library_test
  PRIVATE my_header_lib my_static_lib my_shared_lib
  GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main)

# add tests
include(GoogleTest)
gtest_discover_tests(my_library_test)
