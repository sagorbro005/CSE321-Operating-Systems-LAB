#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 100

void* calculate_ascii(void* arg) {
    char* name = (char*) arg;
    int* result = malloc(sizeof(int));
    *result = 0;

    for(int i = 0; i < strlen(name); i++) {
        *result += name[i];
    }


    return result;
}

int main() {
    pthread_t threads[3];
    char names[3][MAX_NAME_LENGTH];

    for(int i = 0; i < 3; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        // Remove the newline character from the input
        names[i][strcspn(names[i], "\n")] = 0;
    }

    for(int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, calculate_ascii, names[i]);
    }

    int results[3];

    for(int i = 0; i < 3; i++) {
        int* result;
        pthread_join(threads[i], (void**) &result);
        results[i] = *result;
        free(result);
    }

    if(results[0] == results[1] && results[1] == results[2]) {
        printf("Youreka\n");
    } else if(results[0] == results[1] || results[1] == results[2] || results[0] == results[2]) {
        printf("Miracle\n");
    } else {
        printf("Hasta la vista\n");
    }

    return 0;
}



