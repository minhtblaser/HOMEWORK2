#include<stdio.h>
//bt24
int main (){
   int n;
   float S = 0;
   printf("nhap N: ");
   scanf("%d", &n);
   for (int i = 1; i <= n; i++){
       if ( n % i == 0){
            if ( i % 2 == 0 ){
                printf("cac uoc so chan: %d  ", i);
                    S += i;
            }
       }
    }
    printf(" \n S = %.f", S);
    return 0; 
}