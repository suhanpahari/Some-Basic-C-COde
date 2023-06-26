# include<stdio.h>

int main() {
    float pi=3.141;
    int r;
    printf("radius of the circle ");
    scanf("%d", &r);
    printf("Area of circle :%f \n", pi*r*r);
    printf("Circumference of the circle :%f", 2*pi*r);
    return 0;
}