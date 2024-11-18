#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


bool sequencia(char c, char d){
    return (c == 'S' && d == 'B') || (c == 'B' && d == 'S') ||
           (c == 'F' && d == 'C') || (c == 'C' && d == 'F');
}

void organizar(char fita[]) {
    int tam = strlen(fita);
    int cont = 0;

    for (int i = 0; i < tam - 1 ; i++) {
        for (int j = tam - i - 1; j >= tam / 2; j--) {
            if (sequencia(fita[i], fita[j])) {
                cont++;
            }
        }
    }
    printf("%d\n", cont);
}

int main(){
    char fita[300];

    //scanf(" %s", fita);
    while(scanf(" %s", fita) != EOF){
        organizar(fita);
      //  scanf(" %s", fita);
    }
}