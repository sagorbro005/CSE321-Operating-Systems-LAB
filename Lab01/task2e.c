#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int start = 0;
    int end;

    printf("Enter a string: ");
    scanf("%s", str);

    end = strlen(str) - 1;

    while (start < end) {
        if (str[start] != str[end]) {
            printf("Not Palindrome\n");
            return 0;
        }
        start++;
        end--;
    }

    printf("Palindrome\n");
    return 0;
}

