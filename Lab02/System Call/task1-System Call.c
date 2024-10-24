#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "a");
    if(file == NULL) {
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }

    char input[100];
    while(1) {
        printf("Enter a string (-1 to stop): ");
        fgets(input, 100, stdin);
        if(input[0] == '-' && input[1] == '1' && (input[2] == '\n' || input[2] == '\r'))
            break;
        fputs(input, file);
    }

    fclose(file);
    return 0;
}
/*When running the program, provide the filename as a command line argument. For example, if our program is named “task1.c”, we can compile it with gcc -o task1 task1.c and run it with ./task1 test1.txt. Then, we can enter strings that will be written to “test1.txt”. Enter “-1” when we want to stop entering strings. The strings we entered will be appended to “file.txt”. If “test1.txt” did not exist before we ran the program, it will be created. If it did exist, the strings we entered will be added to the end of the file, preserving any content that was already there.*/
