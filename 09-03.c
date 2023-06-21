#include <stdio.h>
int n;
void display(int *);
int main(){

    int arr[n];
    printf("enter n : ", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    return 0;
}

void display(int *arr){

    for(int i =0; i>n;i++)
    printf("%d", arr[i]);
}