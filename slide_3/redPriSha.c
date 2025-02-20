#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define SOMA_INICIAL 1000

int main(void)
{
    int i, n= 25;
    int a[n], soma;
    int ref = SOMA_INICIAL + ((n-1)*n)/2;

    omp_set_num_threads(4);

    //Inicialização de vetores
    for(i=0; i<n; i++){
        a[i] = i;
        soma = SOMA_INICIAL;
    }

    printf("Soma inicial: %d\n", soma);

    #pragma omp parallel default(none) shared(n,a) reduction(+:soma)
    {
        int id = omp_get_thread_num();
        #pragma omp for
        for(i=0; i<n; i++){
            soma += a[i];
        }

        #pragma omp sections
        {
            #pragma omp section
            {
                printf("Thread: %d passou pela primeira seção\n", id);
            }
            #pragma omp section
            {
                printf("Thread: %d passou pela segunda seção\n", id);
            }
        }
        #pragma omp barrier
    }
            printf("Soma final: %d\n", soma);


}