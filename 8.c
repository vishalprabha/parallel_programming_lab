#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

void main() {
	int m,n,i,j;
	printf("Enter the size of the matrix\n");
	scanf("%d %d",&m,&n);
	printf("Matrix is of size %d * %d. Initialising matrix and vector of size %d * 1 with random values\n",m,n,n);
	int mat[m][n], vec[n], res[m];
	for(i = 0; i<m; i++) {
	    for(j = 0; j<n; j++) {
            mat[i][j] = rand()%100;
        }
        res[i] = 0;
    }
    for(i = 0; i<n; i++)
        vec[i] = rand()%100;
    
    printf("Matrix\n");
    for(i = 0; i<m; i++) {
        for(j = 0; j<n; j++) {
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
    printf("Vector\n");
    for(i = 0; i<n; i++)
        printf("%d\n",vec[i]);
    
    #pragma omp parllel for num_threads(8)
    for(i = 0; i<m; i++)
        for(j = 0; j<n; j++)
            res[i] = res[i] + mat[i][j] * vec[j];
    
    printf("Result after multiplication\n");
    for(i = 0; i<n; i++)
        printf("%d ",res[i]);        
    printf("\n");
}
