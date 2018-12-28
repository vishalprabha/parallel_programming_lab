#include <stdio.h>
#include <mpi.h>
#include <math.h>
double dx_arctan(double x)
{    
    return (1.0 / (1.0 + x*x));
}
int main(int argc, char *argv[])
{
    int n;
    double PI25DT = 3.141592653589793238462643;
    double mypi, h, pi, i, sum, x, a, startwtime, endwtime;
    int myid, numprocs, resultlen;
    char name[MPI_MAX_PROCESSOR_NAME] ; 
    MPI_Init(&argc,&argv);
    MPI_Comm_size(MPI_COMM_WORLD,&numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD,&myid);
    MPI_Get_processor_name(name, &resultlen); 
    printf("This is Process-%d/%d running on %s \n",
           myid,numprocs,name);
    fflush(0);
    MPI_Barrier(MPI_COMM_WORLD);
    if(myid == 0) 
    {
        printf("This program uses %d processes\n", numprocs);
	 n = 100000;
        printf("The number of intervals = %d \n", n); 
        startwtime = MPI_Wtime();
    }
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);
    sum = 0.0;
    h   = 1.0/n;
    for (i=myid+0.5; i<n; i+=numprocs)
    {
        sum += dx_arctan(i*h);
    }
    mypi = 4.0*h*sum;
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    if (myid == 0)
    {
        endwtime = MPI_Wtime();
        printf("pi is approximately %.16f, Error is %.16f\n",
                pi, fabs(pi - PI25DT)); 
        printf("wall clock time = %f\n", endwtime-startwtime); 
    }
    MPI_Finalize();
    return 0;
}
