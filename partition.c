#include <stdio.h>
#include <stdlib.h>
/*
    Assuming that the number of values in the array is divisibleany value, 
    create a program that assigns each thread a starting and ending index to add the numbers. 
    This partition algorithm allocates the data among the threads nearly evenly. 
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
    int size = 17; // the number of data elements to be processed
    
    int extra = size % num_threads;
    int batch_size = (size-extra)/num_threads; // the number of data elements per thread
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


    //assign bounds for evenly distributable work
    for(int i = 0; i < num_threads; i++)
    {
        (list+i)->start = min; 
        min+=batch_size;
        (list+i)->end = min;

        // DEBUG: print the thread number and index bounds 
       // printf("thread %d start: %d end: %d \n", i, (list+i)->start, (list+i)->end);
    }

    int flag = extra; 
    for(int i = 0; i < num_threads; i++)
    {
        if(flag == 0) break; //break when no more extra to assign.
        (list+i)->end += 1;
        flag--;
    }

    flag = extra;
    for(int i = 1; i < num_threads; i++)
    {
        if(flag == 0) break; //break when no more extra to assign.
        (list+i)->start += 1;
        flag--;
    }
    
    // adjust bounds to account for extras i.e. not evenly distributable work
    for(int i = 0; i < num_threads; i++)
    {
        // DEBUG: print the thread number and index bounds
        printf("thread %d start: %d end: %d \n", i, (list+i)->start, (list+i)->end);
    }


    return 0; //return 0 on exit normal

}

/*
    Next, create an implementation that works when 
    size isn't evenly divisible by num_threads.
*/