#include <cstdio>
#include "my_cuda_lib.h"

__global__ void CudaLibFuncImpl() { printf("Hello my CUDA library\n"); }

void CudaLibFunc()
{
    CudaLibFuncImpl<<<1, 1>>>();
    cudaDeviceSynchronize();
}
