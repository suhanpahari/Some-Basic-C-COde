#include <stdio.h>
int main(){
float radius, area;
printf("\nEnter the radius of circle : ");
scanf("%d", &radius);
area = 3.414 * radius * radius;
printf("\narea of circle : %f",area);
return (0);
}