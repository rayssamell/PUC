#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTAM 100

typedef struct Lista {
    char **nome;
    int tam;
} Lista;

Lista *createLista(){
    Lista *lista = (Lista*)malloc(sizeof(Lista));
    lista->tam = 0;
    lista->nome = (char **)malloc(MAXTAM * sizeof(char *));
    return lista;
}

void inserir(Lista *lista, char *nome) {
    lista->nome[lista->tam] = strdup(nome);
    lista->tam++;
}

void swap(Lista *lista, int i, int j) {
    char *temp = lista->nome[i];
    lista->nome[i] = lista->nome[j];
    lista->nome[j] = temp;
}

void quicksort(int esq, int dir, Lista *lista) {
    int i = esq, j = dir;
    char *pivo = lista->nome[(esq + dir) / 2];

    // Particionamento
    while (i <= j) {
        while (strcmp(lista->nome[i], pivo) < 0) i++;
        while (strcmp(lista->nome[j], pivo) > 0) j--;

        if (i <= j) {
            swap(lista, i, j);
            i++;
            j--;
        }
    }

    // Recursão para as subpartições
    if (esq < j) quicksort(esq, j, lista);
    if (i < dir) quicksort(i, dir, lista);
}

void quicksortRec(int n, Lista *lista){
    quicksort(0, n-1, lista);
}

void mostrar(Lista *lista, int n){
    for(int i=0; i < n; i++){
        printf("%s\n", lista->nome[i]);
    }
}

int main(){
    int n = 0;
    Lista *lista = createLista();
    char caractere[2];
    char nome[50];

    int comportados = 0, nComportados = 0;

    scanf("%d", &n);
    int i = 0;
    while(i < n){
        scanf(" %s", caractere);
        scanf(" %s", nome);
        inserir(lista, nome);

        if(strcmp(caractere, "+") == 0){
            comportados++;
        } else {
            nComportados++;
        }

        i++;
    }

    quicksortRec(n, lista);
    mostrar(lista, n);

    printf("Se comportaram: %d | Nao se comportaram: %d\n", comportados, nComportados);
}