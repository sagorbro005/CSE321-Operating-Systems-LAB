#include <stdio.h>
#include <string.h>

int main() {
    char email[100];

    printf("Enter the email address: ");
    scanf("%s", email);

    if (strstr(email, "@sheba.xyz") != NULL) {
        printf("Email address is okay\n");
    } else {
        printf("Email address is outdated\n");
    }

    return 0;
}

