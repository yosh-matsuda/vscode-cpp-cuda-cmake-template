project(my_cuda_lib CUDA)

file(
    GLOB_RECURSE CUDALIB_SOURCE_FILES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS src/*.c*)
add_library(my_cuda_lib STATIC ${CUDALIB_SOURCE_FILES})

# CUDA Toolkit
target_include_directories(my_cuda_lib SYSTEM
    PRIVATE ${CMAKE_CUDA_TOOLKIT_INCLUDE_DIRECTORIES})

target_include_directories(my_cuda_lib
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add CUDA compiler options
target_compile_options(my_cuda_lib PRIVATE -lineinfo -use_fast_math -Xptxas=-v)
set_target_properties(my_cuda_lib PROPERTIES CUDA_SEPARABLE_COMPILATION ON
    CUDA_RESOLVE_DEVICE_SYMBOLS ON)
