#include<stdio.h>
int main(){
    int num1,num2,result;
    printf("Enter the first number: ");
    scanf("%d",&num1);

    printf("Enter the second number: ");
    scanf("%d",&num2);

    if(num1>num2){
        result=num1-num2;
        printf("The result of subtraction is: %d\n",result);
    }
    else if(num1<num2){
        result=num1+num2;
        printf("The result of addition is: %d\n",result);
    }
    else{
        result=num1*num2;
        printf("The result of multiplication is: %d\n",result);
    }
    return 0;
}
