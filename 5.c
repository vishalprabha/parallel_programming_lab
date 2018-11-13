#include<omp.h>
#include<stdio.h>

void main() {
    int nt,np,p,mt,dy,ne;
	#pragma omp parallel num_threads(4)
	{
	    int tid = omp_get_thread_num();
	    if(tid==0) {
	        nt = omp_get_num_threads();
	        np = omp_get_num_procs();
	        p = omp_in_parallel();
	        mt = omp_get_max_threads();
	        dy = omp_get_dynamic();
	        ne = omp_get_nested();
	        printf("Number of threads%d\nNumber of processors %d\nIn parallel %d\nmax threads %d\ndynamic threads enabled %d\nnested threads %d\n",nt,np,p,mt,dy,ne);
	    }

	}
}
