#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    // Create child process
    pid = fork();

    if (pid < 0) { 	// Error occurred
        fprintf(stderr, "Fork Failed");
        return 1;
    } else if (pid == 0) { 	// Child process
        pid_t pid2;

        // Create grandchild process
        pid2 = fork();

        if (pid2 < 0) { 	// Error occurred
            fprintf(stderr, "Fork Failed");
            return 1;
        } else if (pid2 == 0) { 	// Grandchild process
            printf("I am grandchild\n");
        } else { 	// Child process
            wait(NULL);
            printf("I am child\n");
        }
    } else { 	// Parent process
        wait(NULL);
        printf("I am parent\n");
    }

    return 0;
}

