# include<stdio.h>

int main() {
    char ch ;
    printf("write a chatercter :");
    scanf("%s",&ch);
     if(ch>='a' && ch<'z'){
        printf("lower case");
     }
     else if (ch>='A' && ch<'Z'){
        printf("upper case");
     }
    else if(ch>=0){
        printf("digit");
    }
    else{
        printf("thank you");
    }
    
     return 0;
}