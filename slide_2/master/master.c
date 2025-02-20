#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(void){
    int a, i, n = 5, b[n];
    printf("%d",a);

    //omp_set_num_threads(4);
    #pragma omp parallel shared(a, b) private(i)
    {
        int thread_id = omp_get_thread_num();
        #pragma omp master
        {
            a = 10;
            printf("thread: %d\nValor de a: %d\n", thread_id,a);
        }

        
        #pragma omp for
        for(i = 0; i < n; i++){
        b[i] = i;
        printf("Preenchendoo o array b, dentro da diretiva for\nthread %d", thread_id);};
        
        
    }

    return 0;
}