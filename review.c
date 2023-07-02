#include <stdio.h>

int main(){

    int a = 12 ,b = 23;
    
    printf("enter a %d\n");
    //scanf("enter a%d ", &a);
    
    printf("enter b %d\n");
    //scanf("enter b %d", &b);

    int *prt1 = &a;
    int *prt2 = &b;
    //int **a = &*prt2;
    //int **b = &*prt1;
    
    printf(" %d\n %d\n %d\n %d\n %d\n %d\n", a, b, *prt1 , *prt2 , prt1, prt2);
    printf(" %u\n %u\n %u\n %u\n", &a, &b , &prt1, &prt2);
    
    return 0;
    
}