#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) { 	// child process
        printf("Child process ID: %d\n", getpid());
        for (int i = 0; i < 3; i++) {
            pid_t grandchild_pid = fork();
            if (grandchild_pid == 0) { 	// grandchild process
                printf("Grand Child process ID: %d\n", getpid());
                exit(0); 	// grandchild process ends after printing its PID
            }
        }
    } else if (pid > 0) { 	// parent process
        printf("Parent process ID: %d\n", getpid());
    } else { 	// fork failed
        printf("Fork failed!\n");
    }

    return 0;
}

