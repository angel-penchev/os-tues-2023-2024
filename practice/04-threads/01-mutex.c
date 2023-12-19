#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *increment_count(void *arg);

typedef struct {
    int *count;
    pthread_mutex_t *count_mutex;
} increment_count_args;


int main()
{
    pthread_t thread1;
    pthread_mutex_t count_mutex;
    pthread_mutex_init(&count_mutex, NULL);

    int count = 0;
    increment_count_args args = {&count, &count_mutex};

    if (pthread_create(&thread1, NULL, increment_count, (void *) &args) != 0) {
        printf("pthread_create() error\n");
        return 1;
    }
    increment_count((void *) &args);

    pthread_mutex_destroy(&count_mutex);

    
    char *retval;
    pthread_join(thread1, (void *) &retval);
    printf("Return Value - %s\n", retval);
    printf("Count - %d\n", count);
    
    return 0;
}

void *increment_count(void *arg) {
    increment_count_args *arg_struct = (increment_count_args *) arg;

    for (size_t i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(arg_struct->count_mutex);
        (*arg_struct->count)++;
        pthread_mutex_unlock(arg_struct->count_mutex);
    }
    return (void *) "shdaflsdkjaf";
}
