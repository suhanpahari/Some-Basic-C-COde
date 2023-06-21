// write a program using main(), get(), display()

#include <stdio.h>
int *get(int);   // fn. call by value & returning reference


void display(int*, int); //fn. call by refference & returning void / nothing */

int main(){
    int n, *array;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    array = get(n);               // get() returns an addrs when called by value 'n'
    display(array, n);               // display() is called by reference 
    return 0;
}

int *get(int n)
{
    int a[n], *p;
    p = a;                     // here & is not reqd bcz name of array it self is base addrs of block
    printf("enter %d elements: ",n);

    for(int i = 0; i<n; i++)
        scanf("%d", &a[i]);
return p;
}

void display(int *p, int n){
    printf("the %d elements in array are: ", n);
    for(int i=0; i<n; i++)
    {
        printf("%d\n", p[i]);
    }
}
