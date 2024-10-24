#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char password[100];
    int i, hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    printf("Enter your password: ");
    scanf("%s", password);

    for(i = 0; i < strlen(password); i++) {
        if(isupper(password[i]))
            hasUpper = 1;
        else if(islower(password[i]))
            hasLower = 1;
        else if(isdigit(password[i]))
            hasDigit = 1;
        else if(password[i] == '_' || password[i] == ',' || password[i] == '$' || password[i] == '#' || password[i] == '@')
            hasSpecial = 1;
    }

    if(hasUpper == 0)
        printf("Uppercase character missing\n");
    if(hasLower == 0)
        printf("Lowercase character missing\n");
    if(hasDigit == 0)
        printf("Digit missing\n");
    if(hasSpecial == 0)
        printf("Special character missing\n");
    if(hasUpper && hasLower && hasDigit && hasSpecial)
        printf("OK\n");

    return 0;
}



