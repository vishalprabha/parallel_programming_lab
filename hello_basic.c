#include<omp.h>
#include<stdio.h>

void main() {
    #pragma omp parallel 
    {
    printf("This is parallel programming. This is thread %d of %d\n",omp_get_thread_num(),omp_get_num_threads());
    }
}
