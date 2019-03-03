# openmp-mpi-pi-calc-demo
A simple demonstration program to calculate the value of PI using both MPI (multiprocess) and OPENMP (multithread)

This is a hybrid program that achieves parallelization using multiple processors and also multiple threads on each processor.

It does a simple integration using rectangles to numerically estimate the value of PI

Usage: 

To compile: mpicc pi_omp_mpi.c -o pi_omp_mpi -fopenmp

To run: mpiexec -n <processors> ./pi_omp_mpi -steps <steps> -threads <threads>
