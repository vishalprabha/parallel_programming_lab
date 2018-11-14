#include<omp.h>
#include<stdio.h>

void main() {
	int i,j,k;
	int a[4][3],b[3][4],c[4][4];
	omp_set_num_threads(4);
	#pragma omp parallel for 
	for(i=0;i<4;i++)
	    for(j=0;j<3;j++)
	        a[i][j] = i + j;
	
	#pragma omp parallel for 
	for(i=0;i<3;i++)
	    for(j=0;j<4;j++)
	        b[i][j] = i * j;        
	        
	#pragma omp parallel for 
	for(i=0;i<4;i++)
	    for(j=0;j<4;j++)
	        c[i][j] = 0; 

	#pragma omp parallel for 
	for(i=0;i<4;i++) {
	    printf("Thread %d did row %d\n",omp_get_thread_num(),i);
	    for(j=0;j<4;j++)
	        for(k=0;k<3;k++)
	            c[i][j] += a[i][k]*b[k][j];
    } 
    
    printf("Matrix A\n");
    for(i=0;i<4;i++) {
        for(j=0;j<3;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("Matrix B\n");
    for(i=0;i<3;i++) {
        for(j=0;j<4;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    printf("Matrix C\n");
    for(i=0;i<4;i++) {
        for(j=0;j<4;j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
}
