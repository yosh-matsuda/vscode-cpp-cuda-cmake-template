cmake_minimum_required(VERSION 3.20.0 FATAL_ERROR)

# CUDA compilation flags
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_EXTENSIONS OFF)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

if(NOT DEFINED CMAKE_CUDA_ARCHITECTURES)
  set(CMAKE_CUDA_ARCHITECTURES 70 80)
endif()

set(CMAKE_CUDA_FLAGS "${CMAKE_CUDA_FLAGS} -Xcompiler=\"${CMAKE_CXX_FLAGS}\"")
set(CMAKE_CUDA_FLAGS_DEBUG "${CMAKE_CUDA_FLAGS_DEBUG} -Xcompiler=\"${CMAKE_CXX_FLAGS_DEBUG}\"")
set(CMAKE_CUDA_FLAGS_RELEASE "${CMAKE_CUDA_FLAGS_RELEASE} -Xcompiler=\"${CMAKE_CXX_FLAGS_RELEASE}\"")

# Check CUDA installed
include(CheckLanguage)
check_language(CUDA)

if(CMAKE_CUDA_COMPILER)
  add_subdirectory(my_cuda_lib)
  add_subdirectory(cuda_main)
else()
  message(STATUS "No CUDA support")
endif()
