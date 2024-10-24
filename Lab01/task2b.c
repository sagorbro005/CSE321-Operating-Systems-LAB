#include<stdio.h>
#include<string.h>

void rmv_extra_spaces(char *str){
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' || (str[i] == ' ' && str[i - 1] != ' '))
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}

int main(){
    char str[100];
    printf("Enter a sentence:\n");
    scanf("%[^\n]s", str);
    getchar();
    rmv_extra_spaces(str); 
    printf("The sentence without extra spaces:\n%s\n", str);
    return 0;
}

