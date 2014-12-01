/* Elia A. Attardo, and Andrea Borsic (C). 
   Shuai Zheng (Kyle) (C) modified this code to make it correctly producing the results.
 */


//general purpose header files
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <ctime>
#include <time.h>

#include <cuda.h>
// CUDA runtime.
#include <cuda_runtime.h>

//ADD_VECT library header
#include "add_vect.h"




using namespace std;
int main(int argc, char *argv[])
{


        
    //check # of input arguments
    if (argc!=1)
    {
        printf("main test lib: incorrect number of input arguments\n");
		printf("Please insert:\n");
		printf("main.exe\n");
        exit(1);
    }
    
    
    //vectors
	const int N = 5;
	
	double A[N] = {31.23, 321.45, 431.123, 98, 762.14};
	double B[N] = {12.3, 3.2145, 432.3, 982.3, 7621.4};
	double C[N] = {0.0, 0.0, 0.0, 0., 0.0};
	
	
	//GPU variables
	double *dev_A, *dev_B,*dev_C;
	cudaMalloc((void **)&dev_A,N*sizeof(double));
	cudaMalloc((void **)&dev_B,N*sizeof(double));
	cudaMalloc((void **)&dev_C,N*sizeof(double));

	cudaMemcpy(dev_A,A,N*sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_B,B,N*sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(dev_C,C,N*sizeof(double), cudaMemcpyHostToDevice);
	
	
	//call the library function
	 add_vect(N, dev_A, dev_B, dev_C);
	
	//copy back
	//memcpy_to_host(C, dev_C, N);
	cudaMemcpy(C,dev_C,N*sizeof(size_t),cudaMemcpyDeviceToHost);

	for (int i=0; i<N; i++)
	{
		printf("elem %d-th = %f\n",i,C[i]);
	}
	
	cudaFree(dev_A);
	cudaFree(dev_B);
	cudaFree(dev_C);

    exit(0);
}




	

