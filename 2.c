#include<omp.h>
#include<stdio.h>

void main() {
	int a[10],i,sum = 0;
	for(i=0;i<10;i++) {
	    a[i] = i;
	}
    #pragma omp parallel num_threads(4)
    {
        int temp = 0,x;
        #pragma omp for
        for(x=0;x<10;x++)
            temp += a[x];
        #pragma omp critical
        {
            sum += temp;
        }
    }
    printf("%d\n",sum);
}
