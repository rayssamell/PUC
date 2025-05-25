#include <stdio.h>

double calcular(int a){
    switch (a)
    {
    case 1:
        return 4.00;
        break;
    case 2:
        return 4.50;
        break;
    case 3:
        return 5.00;
        break;
    case 4:
        return 2.00;
        break;
    case 5:
        return 1.50;
        break;
    default:
        printf("Nao disponivel");
        break;
    }
}

int main(){
    int a = 0, b = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    double total = calcular(a) * b;
    printf("Total: R$ %.2lf\n", total);

    return 0;
}