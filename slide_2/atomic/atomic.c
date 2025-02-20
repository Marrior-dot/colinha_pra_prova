#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 5

int main(void){
    int i, id, n;
    float a[N];
    float soma = 0.0, sumLocal = 0.0;

    for (i = 0; i < N; i++)
    {
        a[i] = i * 1.0;
    }
    
    #pragma omp parallel shared(n, soma) private(id)
    {
        id = omp_get_thread_num();
        #pragma omp for
        for (i = 0; i < N; i++)
        {
            sumLocal += a[i];
        }

        #pragma omp atomic update
        soma += sumLocal;
        
        printf("Thread %d: soma = %f\n", id, soma);
    }

    return 0;
}