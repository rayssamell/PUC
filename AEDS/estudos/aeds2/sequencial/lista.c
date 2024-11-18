#include <stdio.h>

#define MAXTAM 6

int array[MAXTAM];
int n;

void start(){
    n = 0;
}

void inserirInicio(int valor){
    if(n >= MAXTAM)
        printf("Erro");
    for(int i=n; i > 0; i--){
       array[i] = array[i-1];
    }
    array[0] = valor;
    n++; 
}
//inserir no fim
void inserirFim(int valor){
    if(n >= MAXTAM)
        printf("Erro\n");
    array[n++] = valor;
}
//inserir em posicao
void inserir(int valor, int pos){
    if(n >= MAXTAM || pos < 0 || pos > n)
        printf("Erro\n");

    for(int i=n; i > pos; i--){
        array[i] = array[i-1];
    }
    array[pos] = valor;
    n++;
}
//remover no inicio
int removerInicio(){
    if(n == 0)
        printf("Erro\n");

    int resp = array[0];
    n--;
    for(int i=0; i < n; i++){
        array[i] = array[i+1];
    }
    return resp;
}
//remover no fim
int removerFim(){
    if(n == 0)
        printf("Erro\n"); 
    return array[--n];
}
//remover em posicao
int remover(int pos){
    if(n == 0 || pos < 0 || pos > n)
        printf("Erro\n");
        
    int resp = array[pos];
    n--;
    for(int i=pos; i < n; i++){
        array[i] = array[i+1];
    }
    return resp;
}
//mostrar arranjo
void mostrar(){
    printf("\n[ ");
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
    }
    printf(" ]\n");
}

int main(){
    printf("\n==== LISTA LINEAR ====\n");
    int x1, x2, x3;
    inserirInicio(1);
    inserirFim(7);
    inserirFim(9);
    inserirInicio(3);
    inserir(8, 3);
    inserir(4, 2);
    mostrar();
    x1 = removerInicio();
    x2 = removerFim();
    x3 = remover(2);
    printf("%d, %d, %d", x1, x2, x3);
    mostrar();

    return 0;
}