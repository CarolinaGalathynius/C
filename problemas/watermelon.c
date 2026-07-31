#include <stdio.h>
int main(){
    int peso;
    scanf("%d", &peso);
    if(peso%4==0){
        printf("YES");
    }
    else{
        printf("NO");
    }
}