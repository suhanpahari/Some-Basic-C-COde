#include <stdio.h>
#include <cuda.h>

#define N 1024  // Array size

// CUDA kernel for vector addition
__global__ void vectorAdd(int *a, int *b, int *c, int size) {
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < size) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    int *h_a, *h_b, *h_c;  // Host arrays
    int *d_a, *d_b, *d_c;  // Device arrays
    int size = N * sizeof(int);

    // Allocate memory on the host
    h_a = (int*)malloc(size);
    h_b = (int*)malloc(size);
    h_c = (int*)malloc(size);

    // Initialize input arrays
    for (int i = 0; i < N; i++) {
        h_a[i] = i;
        h_b[i] = N - i;
    }

    // Allocate memory on the GPU
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

    // Copy data from host to device
    cudaMemcpy(d_a, h_a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, size, cudaMemcpyHostToDevice);

    // Launch the kernel with N threads
    int threadsPerBlock = 256;
    int blocksPerGrid = (N + threadsPerBlock - 1) / threadsPerBlock;
    vectorAdd<<<blocksPerGrid, threadsPerBlock>>>(d_a, d_b, d_c, N);

    // Copy the result back to the host
    cudaMemcpy(h_c, d_c, size, cudaMemcpyDeviceToHost);

    // Print a few results
    printf("Sample results:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d + %d = %d\n", h_a[i], h_b[i], h_c[i]);
    }

    // Free memory
    free(h_a); free(h_b); free(h_c);
    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);

    return 0;
}
