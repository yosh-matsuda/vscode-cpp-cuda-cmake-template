cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

project(my_header_lib CXX)

add_library(${PROJECT_NAME} INTERFACE)

# dependencies
find_package(fmt 10.0.0 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} INTERFACE fmt::fmt-header-only)

# header
target_include_directories(${PROJECT_NAME}
                           INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
