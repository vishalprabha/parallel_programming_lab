#include <stdio.h>
#include <omp.h>

void main() {
    int i,j;
    int n;
    printf("Enter  number\n");
    scanf("%d",&n);
    int a[4] = {0};
    #pragma omp parallel for firstprivate(n) lastprivate(i) num_threads(4) 
    for(j = 0; j<=n; j++) {
        i += j*j*j*j;
        //printf("%d\n",i);
        a[omp_get_thread_num()] = i;
    } 
    printf("Sum of squares(4)[Quadruples] %d\n",a[0] + a[1] + a[2] + a[3]);
    
}
