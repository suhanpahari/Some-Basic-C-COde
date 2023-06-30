# include<stdio.h>

int main() {
    int n;
    printf(" Enter a num :");
    for( int i = 1; ; i++ ){
        scanf("%d", &n);
        if( n%2 != 0){
            break;
        }  
     }
     printf("thank you");
    return 0;
}