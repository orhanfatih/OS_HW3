//2 array 200 int (0-50)+++
//create 2 threads+++
//pass sth+++
//pass half to each thread (first first half)+++
// calculate dot product
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

struct thread1_struct
{
    char str[32];
    int x;
};

int main()
{
    int array1[200], array2[200]; //initialize arrays here
    arrays(array1, array2);       //creation of arrays

    //divide array into 2 parts
    // int array1_first_part[100], array1_second_part[100];
    // int array2_first_part[100], array2_second_part[100];
    int first_halves[200], second_halves[200];

    // int i;
    // for (i = 0; i < 200; i++)
    // {
    //     printf("%d%s%d\n", i, " : ", array1[i]);
    // }
    // printf("   array1    \n");

    int b;
    for (b = 0; b < 100; b++)
    {
        //first parts
        first_halves[b] = array1[b];
        first_halves[b + 100] = array2[b];
        //second parts
        second_halves[b] = array1[100 + b];
        second_halves[b + 100] = array2[100 + b];

        // array1_first_part[b] = array1[b];
        // array2_first_part[b] = array2[b];
        // array1_second_part[b + 100] = array1[b + 100];
        // array2_second_part[b + 100] = array2[b + 100];
    }
    // printf(" esitlendi\n");

    // int a;
    // for (a = 0; a < 200; a++)
    // {
    //     printf("%d%s%d\n", a, " : ", second_halves[a]);
    // }
    // printf("  aaaaaaaaaaaaaaaaaaa\n");

    pthread_t thread1, thread2;

    int iret1, iret2;

    /* Create independent threads each of which will execute function */

    iret1 = pthread_create(&thread1, NULL, first, (int *)first_halves);
    iret2 = pthread_create(&thread2, NULL, second, (int *)second_halves);

    /* Wait till threads are complete before main continues. Unless we  */
    /* wait we run the risk of executing an exit which will terminate   */
    /* the process and all threads before the threads have completed.   */
    struct thread1_struct *resp;
    pthread_join(thread1, (void **)&resp);

    pthread_join(thread2, NULL);

    printf("%s %d\n", resp->str, resp->x);
    free(resp);
    // printf("Thread 1 returns: %d\n", iret1);
    printf("Thread 2 returns: %d\n", iret2);
    //exit(0);
    return 0;
}

void *first(void *array)
{
    int *ptr = (int *)array;
    int a = dot_product_array(ptr);

    struct thread1_struct *eg = malloc(sizeof(struct thread1_struct));
    strcpy(eg->str, "Thread 1 returns: ");
    eg->x = a;
    pthread_exit(eg);

    // int *x = malloc(sizeof(int));

    printf(" 1 bitti\n");
    // return (void *)x;
    // pthread_exit((void *)x);
    // dot_product_array(ptr);
}

void *second(void *array)
{
    int *ptr = (int *)array;
    dot_product_array(ptr);

    // int i;
    // for (i = 0; i < 200; i++)
    // {
    //     // printf("%d%s%d\n", i, " : ", ptr[i]);
    // }
    printf(" 2 bitti\n");
}
