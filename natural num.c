# include<stdio.h>

int main() {
    float a;
    printf("enter a nuber:");
    scanf("%f", &a);
    int b = (int)a;
    
    if(a>=1) {
        if(a-b == 0){
             printf("natural number");
             }
       else {
        printf("not a natural number");
       }
    }
    else {
        printf("not natural nuber");
    }

    return 0;
}