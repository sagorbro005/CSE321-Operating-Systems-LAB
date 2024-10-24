#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_thread(void* arg) {
    int* thread_num = (int*)arg;
    printf("thread-%d running\n", *thread_num);
    printf("thread-%d closed\n", *thread_num);
    free(arg);
    return NULL;
}

int main() {
    pthread_t threads[5];
    for(int i = 0; i < 5; i++) {
        int* thread_num = malloc(sizeof(int));
        *thread_num = i + 1;
        pthread_create(&threads[i], NULL, print_thread, thread_num);
        pthread_join(threads[i], NULL); 	// wait for the thread to finish
    }
    
    return 0;
}

