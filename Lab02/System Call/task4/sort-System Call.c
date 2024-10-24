#include <stdio.h>
#include <stdlib.h>

int compare(const void * a, const void * b) {
    return (*(int*)b - *(int*)a);
}

int main(int argc, char *argv[]) {
    int numbers[argc-1];
    for(int i = 1; i < argc; i++) {
        numbers[i-1] = atoi(argv[i]);
    }
    qsort(numbers, argc-1, sizeof(int), compare);
    for(int i = 0; i < argc-1; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    return 0;
}

/*when we run the program, we need to pass the numbers as command line arguments. For example, if we want to sort the numbers 5, 3, and 9, we would run the program like this: ./sort 5 3 9 */
