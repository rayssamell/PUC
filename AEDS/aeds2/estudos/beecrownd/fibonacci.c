#include <stdio.h>

int fibonacci(int x, int *calls){
    (*calls)++;
    if(x == 0) return 0;
    if(x == 1 || x == 2) return 1;
    return fibonacci(x-1, calls) + fibonacci(x-2, calls);
}

int main(){
    int n = 0;
    int x = 0;

    scanf("%d", &n);
    for(int i=0; i < n; i++){
        int calls = 0;
        scanf("%d", &x);
        int resultado = fibonacci(x, &calls);
        printf("fib(%d) = %d calls = %d\n", x, calls, resultado);
    }


    return 0;
}