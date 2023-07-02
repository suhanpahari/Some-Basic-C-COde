#include<stdio.h>
#include<math.h>
    int main(){
        printf("Enter starting range: \n"); // program to check given number of armstrong number in given range
        
        int num,b,p; //b is used as function calling variable
        scanf("%d",&num); //num is used to run roop for given times by user as range
        printf("Enter ending range: \n");
        scanf("%d",&p);
        int armstrong(int a){ //a is storing number input by user 
        int quotient,remainder,sum,num2,sum2;
        num2=a;
        sum=0;
        sum2=0;
        int counter=0;
        while (a>0){
            remainder=a%10;
            counter++;
            a=a/10;}
        a=num2;
        remainder=0;
         while(a>0){
            remainder=a%10;
            a=a/10;
            sum=pow(remainder,counter);
            
            sum2=sum+sum2;
            
        }
        if(sum2==num2){
            printf("Armstrong number %d \n",num2);}

        else{
           }
        }
        for(num;num<=p;num++){
           b= armstrong(num);
        }
        return 0;
    }