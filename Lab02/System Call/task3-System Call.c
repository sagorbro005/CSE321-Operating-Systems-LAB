#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t a, b, c;
    int count = 1; // for the parent process

    a = fork();
    if (a > 0) { // parent process
        if (a % 2 != 0) { // if PID is odd
            fork();
            count++;
        }
        count++;
    }

    b = fork();
    if (b > 0) { // parent process
        if (b % 2 != 0) { // if PID is odd
            fork();
            count++;
        }
        count++;
    }

    c = fork();
    if (c > 0) { // parent process
        if (c % 2 != 0) { // if PID is odd
            fork();
            count++;
        }
        count++;
    }

    printf("Total processes created: %d\n", count);

    return 0;
}

