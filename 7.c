#include<omp.h>
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
void main() {
	omp_lock_t lock;
	int max_p = INT_MIN;
	int max_s = INT_MIN;
	int i,a[100];
	for(i=0;i<100;i++) {
	    a[i] = rand()%1000;
	}
	printf("Check max through parallel\n");
	omp_init_lock(&lock);
	#pragma omp parallel for num_threads(8)
	for(i=0;i<100;i++) {
	    if(a[i]>max_p) {
	        omp_set_lock(&lock);
	        max_p = a[i];
	        omp_unset_lock(&lock);
	    }
	}
	omp_destroy_lock(&lock);
	printf("Check max through serial\n");
	for(i=0;i<100;i++) {
	    if(a[i]>max_s)
	        max_s = a[i];
	}
	printf("Parallel max %d serial max %d\n",max_p,max_s);
}
