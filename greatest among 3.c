# include<stdio.h>

int main() {
   int n1, n2, n3;
   printf("enter three number :");
   scanf("%d %d %d", &n1, &n2, &n3);

   if (n1>n2 && n1>n3){
    printf("largest num is %d", n1);
   }
   else if (n2>n1 && n2>n3)
   {
    printf("largest num is %d", n2);
   }
   else
   {
    printf("largest num is %d", n3);
   }

    return 0;
}