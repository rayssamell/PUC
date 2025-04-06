#include <stdio.h>

int main(){
    int a = 0, b = 0, c = 0, d = 0;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);

    if(c > 0 && d > 0 && b > c && d > a){
        int soma1 = a + b;
        int soma2 = c + d;

        if(soma2 > soma1 && a % 2 == 0){
            printf("Valores aceitos");
        }
    } else {
        printf("Valores nao aceitos");
    }
}