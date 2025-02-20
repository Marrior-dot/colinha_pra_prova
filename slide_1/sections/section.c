#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void){

    int  secao = 0;

    omp_set_num_threads(4);
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            int id = omp_get_num_threads();
            secao ++;
            printf("Ordem da execucao: %d\nthread:%d\n", secao, id);
        } //Executa primeiramente esse pragma

        printf("\n");
        #pragma omp section
        {
            int id = omp_get_num_threads();
            secao ++;
            printf("Ordem da execucao: %d\nthread:%d", secao, id);
        } //Executa primeiramente por segundo esse pragma
    }

    //printf("Enter the number of threads: ");

    return 0;
}