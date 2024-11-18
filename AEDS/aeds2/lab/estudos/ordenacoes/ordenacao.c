#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct para guardar dados
typedef struct { 
    int idade; //idade
    char nome[100]; //nome
} Pessoa;

void bubbleSort(Pessoa pessoas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Comparar por idade
            if (pessoas[j].idade > pessoas[j + 1].idade ||
                (pessoas[j].idade == pessoas[j + 1].idade &&
                 strcmp(pessoas[j].nome, pessoas[j + 1].nome) > 0)) {
                // Trocar elementos
                Pessoa temp = pessoas[j];
                pessoas[j] = pessoas[j + 1];
                pessoas[j + 1] = temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Pessoa *pessoas = (Pessoa *)malloc(n * sizeof(Pessoa));

    for (int i = 0; i < n; i++) {
        scanf(" %s %d", pessoas[i].nome, &pessoas[i].idade);
    }

    bubbleSort(pessoas, n);

    // Imprimir a lista ordenada
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", pessoas[i].nome, pessoas[i].idade);
    }
}