#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void){
    int secao = 10;
    int a,b = 10;
    int i = 0;

    omp_set_num_threads(4);
    #pragma omp parallel  shared(a, b) private(i) 
    {
    int thread_id = omp_get_thread_num();
        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Thread %d executando seção 1\n", thread_id);
                #pragma omp critical
                {
                    secao++;
                    printf("Valor Seção 1: %d\n", secao);
                }

            }
        }

        //int id = omp_get_thread_num();
        #pragma omp for
        for (i = 0; i < b; i++)
        {
            printf("Thread %d executando seção \n", thread_id);
        }
        
    }
    return 0;
}