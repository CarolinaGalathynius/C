#include <stdio.h>
int main(){
    int peso;
    scanf("%d\n", &peso);
    if(peso%2==0&&peso>2){
        printf("YES");
    }
    else{
        printf("NO");
    }
}