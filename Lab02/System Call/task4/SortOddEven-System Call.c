#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main(int argc, char *argv[]) {
    pid_t pid = fork();
    if(pid == 0) { 	// child process
        int numbers[argc-1];
        for(int i = 1; i < argc; i++) {
            numbers[i-1] = atoi(argv[i]);
        }
        qsort(numbers, argc-1, sizeof(int), compare);
        for(int i = 0; i < argc-1; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
    } else if(pid > 0) { 	// parent process
        wait(NULL); 	// wait for child process to finish
        for(int i = 1; i < argc; i++) {
            int num = atoi(argv[i]);
            if(num % 2 == 0) {
                printf("%d is even\n", num);
            } else {
                printf("%d is odd\n", num);
            }
        }
    } else { 	// fork failed
        printf("Fork failed!\n");
    }
    return 0;
}

