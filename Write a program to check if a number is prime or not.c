# include<stdio.h>

int main() {
    int n;
    printf("enter a number :");
    scanf("%d", &n);

    for(int i = 1; ;i++){
        if(n%i != 0){
            printf("not a prime");
        }
        else{
            printf("a prime");
        }
    }


    return 0;
}