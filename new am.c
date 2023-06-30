#include<stdio.h>
#include<math.h>

float armstrong(int);  
  
int main()  
{  
    int count, start, end, temp;  
  
    printf("Enter start and end values\n");  
    scanf("%d%d", &start, &end);  
  
    if(start > end)  
    {  
        temp = start;  
        start= end;  
        end  = temp;  
    }  
  
    printf("Armstrong numbers between %d and %d are\n", start, end);  
  
    for(count = start; count <= end; count++)  
    {  
        if(count == armstrong(count))  
        {  
            printf("%d is an Armstrong number\n", count);  
        }  
    }  
  
    return 0;  
}  
  
float armstrong(int num)  
{  
    int rem, n = 0, temp;  
    float sum = 0.0;  
  
    temp = num;  
  
    while(temp)  
    {  
        temp = temp / 10;  
        n++;  
    }  
  
    while(num)  
    {  
        rem = num % 10;  
        sum = sum + pow(rem, n);  
        num = num / 10;  
    }  
  
    return(sum);  
} 
