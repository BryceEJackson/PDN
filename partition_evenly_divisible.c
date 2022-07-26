#include <stdio.h>
#include <stdlib.h>
/*
    Assuming that the number of values in the array is divisible
    by the number of threads, create a program that assigns each thread
    a starting and ending index to add the numbers. This partition algorithm
    allocates the data among the threads evenly. 

*/


/*
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    sum_array(array[])
    {
        returns sum of all elements of the array
    }

    way 1) not parallel
    
    1+2+.....+10 = sum

    way 2) parallel

    1) 1 + 2  
    2) 3 + 4
    3) 5 + 6
    4) 7 + 8
    5) 9 + 10

    then add for the final result

*/

/*
    thread struct to hold start and end indexes, and master flag
*/
typedef struct thread 
{
    int start; 
    int end; 
    int isMaster;

} thread;


int min = 0;

int main(int argc, char *argv[])
{
    int num_threads = 5; // the number of threads 
    int size = 10; // the number of data elements to be processed, divisible by num_threads
    
    int batch_size = size/num_threads; // the number of data elements per thread
    thread *list = malloc(sizeof(struct thread) * num_threads);
        
    // loop through and mark a thread as master thread
    for(int i = 0; i < num_threads; i++)
    {
        if(i == 0){
        (list+i)->isMaster = 1;
        }
        else{
        (list+i)->isMaster = 0;
        }
    }


    // loop through and assign each thread their index bounds
    for(int i = 0; i < num_threads; i++)
    {
        (list+i)->start = min; 
        min+=batch_size;
        (list+i)->end = min;

        // DEBUG: print the thread number and bounds for computation.
        printf("thread %d start: %d end: %d \n", i, (list+i)->start, (list+i)->end);
    }



    return 0; //return 0 on exit normal

}

/*
    Next, create an implementation that works when 
    size isn't evenly divisible by num_threads.
*/