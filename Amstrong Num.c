#include <stdio.h>
int main()
{
int num, originalNum, remainder,
result = 0;
printf("Enter a three-digit integer: ");
scanf("%d" , &num);
originalNum = num;

while (originalNum != 0)
{
// remainder contains the last digit 
remainder = originalNum % 10;
result += remainder * remainder * remainder;
// removing last digit from the original number
originalNum /= 10;
}
if (result == num)
printf("%d is an Amstrong number .", num);
else 
printf("%d is not an Amstrong number.", num);
return 0;
}
