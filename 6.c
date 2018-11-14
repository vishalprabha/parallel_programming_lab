#include<omp.h>
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void main() {
	int max_p = INT_MIN;
	int max_s = INT_MIN;
	int i,a[100];
	for(i=0;i<100;i++) {
	    a[i] = rand()%1000;
	}
	printf("Check max through parallel\n");
	#pragma omp parallel for num_threads(8)
	for(i=0;i<100;i++) {
	    if(a[i]>max_p) {
	    	#pragma omp critical
	    	max_p = a[i];
	    }
	}
	printf("Check max through serial\n");
	for(i=0;i<100;i++) {
	    if(a[i]>max_s)
	        max_s = a[i];
	}
	printf("Parallel max %d serial max %d\n",max_p,max_s);
}
