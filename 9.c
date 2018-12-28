#include<omp.h>
#include<stdio.h>

void main() {
    int i;
  #pragma omp parallel for ordered
	for(i = 97; i<=122; i++)
  #pragma omp ordered
	    printf("%c",i);
    printf("\n");
}
