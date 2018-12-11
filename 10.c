#include<omp.h>
#include<stdio.h>

void main() {
	long long fact1 = 1,fact2 = 1;
	int a,i;
	printf("Enter a number to check its factorial\n");
	scanf("%d",&a);
	#pragma omp parallel for firstprivate(a) num_threads(8)
	for(i = 2; i<=a; i++) {
	    fact1 = fact1 * i;
    }
    printf("When first private is not used\n");
    printf("factorial of %d is %llu \n",a,fact1);
    #pragma omp parallel for firstprivate(a,fact2) num_threads(8)
	for(i = 2; i<=a; i++) {
	    fact2 = fact2 * i;
    }
    printf("When first private is used\n");
    printf("factorial of %d is %llu \n",a,fact2);
}
