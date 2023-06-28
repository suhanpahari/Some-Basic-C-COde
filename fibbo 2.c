# include<stdio.h>

int fibo(int n);

int main() {
    int n;

    printf("enter Nth order :");
    scanf("%d", &n);

    printf(" is fibbo: %d", fibo(n));
    return 0;
}      

int fibo(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }

    int fiboNm1 = fibo(n-1);
    int fiboNm2 = fibo(n-2);
    int fiboN = fiboNm1 + fiboNm2;
    
    return fiboN;
}