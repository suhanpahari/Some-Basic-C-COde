# include<stdio.h>

int main() {
    float num1 , num2;
    printf("enter num1 \n");
    scanf("%f", &num1);
    printf("enter num2 \n");
    scanf("%f", &num2);

    if(num1>num2){
        printf("%f", num2);
    }
    else if (num2>num1){
        printf("%f", num1);
    }
    
    return 0;
}