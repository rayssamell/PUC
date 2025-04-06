#include <stdio.h>

char **idioma;
char **texto;

void start(int n){
    idioma = (char *)malloc(n *sizeof(char*));
    texto = (char *)malloc(n *sizeof(char*));
}

int main(){
    int n = 0;
    char id[50];
    char tx[50];

    scanf("%d", &n);
    start(n);
    for(int i=0; i<n; i++){
        scanf(" %s", id);
        scanf(" %s", tx);
        idioma[i] = id;
        texto[i] = tx;

    }
}