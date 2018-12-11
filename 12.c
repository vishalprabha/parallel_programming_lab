#include<omp.h>
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void findprimes(int n) {
    double t1,t2;
    int p,i;
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    t1 = omp_get_wtime();
    #pragma omp parallel for num_threads(8)
    for(p = 2; p<=n; p++) {
        if (prime[p] == true) {  
            for (i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }
    t2 = omp_get_wtime();
    int tot = 0;
    printf("Prime numbers in given range are\n"); 
    for (p=2; p<=n; p++) {
        if (prime[p]) {
            printf("%d ",p);
            tot++;
        }
    }
    printf("\nTotal number of prime numbers are %d \n",tot);
    printf("Total time taken %0.6f \n",t2-t1);
}
void main() {
    int n;
    printf("Enter a number\n");
    scanf("%d",&n);
    findprimes(n);
}
