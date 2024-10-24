#include <stdio.h>

// Function to check if a number is perfect
int isPerfect(int num) {
    int sum = 1;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            if(i * i != num)
                sum = sum + i + num / i;
            else
                sum = sum + i;
        }
    } 
    if (sum == num && num != 1)
        return 1;	//Number is perfect
    return 0;	//Number is not perfect
}

// Function to print perfect numbers in given range
void printPerfectNumbers(int low, int high) {
    for (int i = low; i <= high; i++) {
        if (isPerfect(i))
            printf("%d\n", i);
    }
}

int main() {
    int low, high;
    printf("Enter the lower limit: ");
    scanf("%d", &low);
    printf("Enter the upper limit: ");
    scanf("%d", &high);
    printPerfectNumbers(low, high);
    return 0;
}

