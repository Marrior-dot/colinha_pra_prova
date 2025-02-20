#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 20

int main(void){

    int i, n;
    int a[N], b[N], c[N]; //Arrays

    for(i=0; i<N; i++){
        a[i] = b[i] = i * 1.0;
    }
    n = N;

    omp_set_num_threads(8);
    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        #pragma omp for
        for(i=0; i<n; i++){
            c[i] = a[i] + b[i];
        printf("Thread %d executa a iteração %d do loop\n", id, i);
        }
    }

    //printf("Enter the number of threads: ");

    return 0;
}