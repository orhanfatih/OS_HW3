//2 array 200 int (0-50)+++
//create 2 threads+++
//pass sth+++
//pass half to each thread (first first half)+++
// calculate dot product+++
//threads terminates add results final val
//print on the screeen

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "initialize_arrays.c"
#include "dot_product.c"

void *first(void *ptr);
void *second(void *ptr);

struct thread1_struct // this struct used for thread calculation result
{
    char str[32];
    int x;
};

int main()
{
    int array1[200], array2[200]; //initialize arrays here
    arrays(array1, array2);       //creation of arrays

    //divide array into 2 parts
    int first_halves[200], second_halves[200];

    int b;
    for (b = 0; b < 100; b++) // this for loop writes first halves and second halves of arrays to new one
    {
        //first parts
        first_halves[b] = array1[b];
        first_halves[b + 100] = array2[b];
        //second parts
        second_halves[b] = array1[100 + b];
        second_halves[b + 100] = array2[100 + b];
    }

    pthread_t thread1, thread2;

    int iret1, iret2;

    /* Create independent threads each of which will execute function */

    iret1 = pthread_create(&thread1, NULL, first, (int *)first_halves);
    iret2 = pthread_create(&thread2, NULL, second, (int *)second_halves);

    /* Wait till threads are complete before main continues. Unless we  */
    /* wait we run the risk of executing an exit which will terminate   */
    /* the process and all threads before the threads have completed.   */

    struct thread1_struct *resp;           // struct used here
    pthread_join(thread1, (void **)&resp); // pthread_join is blocking to start a new thread before started one finished his process.
    struct thread1_struct *resp2;
    pthread_join(thread2, (void **)&resp2);

    printf("%s %d\n", resp->str, resp->x);
    int first_dot = resp->x;
    free(resp);
    printf("%s %d\n", resp2->str, resp2->x);
    int first_dot2 = resp->x;
    free(resp2);

    //final results here
    int final_res = first_dot + first_dot2;
    printf("Final result is : %d\n", final_res);

    return 0;
}

void *first(void *array)
{
    int *ptr = (int *)array;
    int a = dot_product_array(ptr); //calculation of dot product

    struct thread1_struct *eg = malloc(sizeof(struct thread1_struct)); // memory allocation for struct
    strcpy(eg->str, "Thread 1 returns: ");                             // writes on struct for return
    eg->x = a;                                                         // writes on struct for return
    pthread_exit(eg);                                                  // exiting the current thread
}

void *second(void *array)
{
    int *ptr = (int *)array;
    int b = dot_product_array(ptr);                                    //calculation of dot product
    struct thread1_struct *eg = malloc(sizeof(struct thread1_struct)); // memory allocation for struct
    strcpy(eg->str, "Thread 1 returns: ");                             // writes on struct for return
    eg->x = b;                                                         // writes on struct for return
    pthread_exit(eg);                                                  // exiting the current thread
}
