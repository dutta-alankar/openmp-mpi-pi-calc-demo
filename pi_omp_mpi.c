/*Usage: mpiexec -n 4 ./pi_omp_mpi -steps 1000000000 -threads 8 */

#include <stdio.h>
#include <stdlib.h>
#include "omp.h"
#include "mpi.h"

int threads;
static long num_steps;
double step;

void main(int argc, char** argv)
{
	// Initialize the MPI environment
    	MPI_Init(NULL, NULL);
	
    	// Get the number of processes
    	int world_size;
    	MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    	// Get the rank of the process
    	int world_rank;
    	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	num_steps = atol(argv[2]);
	if (argc>3) threads = atol(argv[4]);
	double pi,sum=0.,sum_inter = 0.;
	step = 1.0/(double) num_steps;
	omp_set_num_threads(threads);
	#pragma omp parallel shared(sum) private(sum_inter)
	{
		double x;
		int ID = omp_get_thread_num();
		int workers = omp_get_num_threads()*world_size;
		for (int i=(ID+world_rank*omp_get_num_threads());i<num_steps;i+=workers)
		{
			x = (i+0.5)*step;
			sum_inter = sum_inter + 4.0/(1.0+x*x);
		}
	#pragma omp critical 
	sum += sum_inter;
	}
	//MPI_Barrier(MPI_COMM_WORLD);
	double global_sum;
	MPI_Reduce(&sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

	if (world_rank==0)
	{
		pi = step*global_sum;
		printf("PI = %f\n",pi);
	}
	// Finalize the MPI environment.
    	MPI_Finalize();
}
