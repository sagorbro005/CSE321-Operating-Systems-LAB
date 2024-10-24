#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_PRINTS 5

void* print_numbers(void* arg) {
    int thread_num = *((int*)arg);
    int start = thread_num * NUM_PRINTS + 1;
    int end = start + NUM_PRINTS;
    for(int i = start; i < end; i++) {
        printf("Thread %d prints %d\n", thread_num, i);
    }
    free(arg);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++) {
        int* thread_num = malloc(sizeof(int));
        *thread_num = i;
        pthread_create(&threads[i], NULL, print_numbers, thread_num);
        pthread_join(threads[i], NULL); 	// wait for the thread to finish
    }
    
    return 0;
}

