project(cuda_main CXX CUDA)

file(
    GLOB_RECURSE CUDAMAIN_SOURCE_FILES
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} CONFIGURE_DEPENDS src/*.c*)
add_executable(cuda_main ${CUDAMAIN_SOURCE_FILES})
target_link_libraries(cuda_main PRIVATE my_cuda_lib)
