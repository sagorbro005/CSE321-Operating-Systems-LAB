#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    for(int i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        if(num % 2 == 0) {
            printf("%d is even\n", num);
        } else {
            printf("%d is odd\n", num);
        }
    }
    return 0;
}

/* when we run the program, we need to pass the numbers as command line arguments. For example, if we want to check the numbers 5, 3, and 9 is odd or even, we would run the program like this: ./oddeven 5 3 9 */
