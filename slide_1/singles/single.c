#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 20

int main(void){

    int i = 0;

    omp_set_num_threads(8);
    #pragma omp parallel
    {
        int id_thread = omp_get_thread_num();
        #pragma omp single
            printf("Thread %d inicia a paralelização\n", id_thread);
        
        
        #pragma omp for
            for(int i=0; i<N; i++){
                printf("Thread %d executa a iteração %d do loop\n", id_thread, i);
            }
    }

    return 0;
}