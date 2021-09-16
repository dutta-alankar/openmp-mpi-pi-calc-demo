# openmp-mpi-pi-calc-demo
A simple demonstration program to calculate the value of PI using both MPI (multiprocess) and OPENMP (multithread)

```
      ################################  

    ##################################  

   ###################################  

   ####    #####         ####           

  ###      #####        #####           

  #        #####        #####           

  #        #####        ####            

           ####         ####            

           ####         ####            

           ####         ####            

          #####        #####            

          #####        #####            

          ####         #####            

          ####         #####            

         #####         #####            

        ######         #####            

        #####          #####        ##  

       #######         ######       ##  

      #######           ##############  

     #######            #############   

     #######             ###########    

     ######               #########     


```

This is a hybrid program that achieves parallelization using multiple processors and also multiple threads on each processor.

It does the following integration using rectangles to numerically estimate the value of PI:

<img src="https://user-images.githubusercontent.com/39578361/133594893-341f6b01-c046-4311-a0f9-8e5577bd1bd7.png" width="200" height="80" />

Usage: 

To compile: ```mpicc pi_omp_mpi.c -o pi_omp_mpi -fopenmp```

To run: ```mpiexec -n <processors> ./pi_omp_mpi -steps <steps> -threads <threads>```
