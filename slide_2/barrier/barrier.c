#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void){

    omp_set_num_threads(4);
    #pragma omp parallel 
    {
        int id_thread = omp_get_thread_num();
        int num_threads = omp_get_num_threads();

        if (id_thread == 0){
            printf("Iniciando a paralelização com %d threads\n", num_threads);
        }

        #pragma omp for
        for(int i=0; i<10; i++){
                printf("Thread %d executando a iteração %d\n", id_thread, i);
            }

        #pragma omp barrier
            printf("Thread %d chegou na barreira\n", id_thread);

    }//printf("Enter the number of threads: ");

    return 0;
}