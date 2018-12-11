#include<omp.h>
#include<stdio.h>

void main() {
	longlong fact = 1;
	int a,i;
	printf("Enter a number to check its factorial\n");
	scanf("%d",&a);
	#pragma omp parallel for firstprivate(fact,a) num_threads(8)
	for(i = 2; i<=a; i++)
	    fact = fact * i;
    printf("factorial of %d is %ld",a,fact);
}
