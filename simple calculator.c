# include<stdio.h>

int main() {
    float a, b;
    char symbol;
    
    scanf("%f", &a);

    scanf("%s", &symbol);

    scanf("%f", &b);

    switch (symbol)
    {
    case '+' : printf("result %f", a + b);
        break;

    case '-' : printf("result %f", a - b);
        break;

    case '*' : printf("result %f", a * b);
        break;

    case '/' : 
    if (a/b!=0){
        
        printf(" quotient %f\n remainder %f", a/b, a%b);}
        break;
    else {
        printf(" quotient %f", a/b)
    }

    default : printf("Error !");
    }
   return 0;
}