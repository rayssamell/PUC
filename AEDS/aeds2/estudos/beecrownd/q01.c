#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "q01.h"

void posIn(char expressao[]){
    char linha[25];
    bool yes = false;
    int pos = 0;
    int k = 0;

    for(int i=0; i < strlen(expressao); i++){
        if(expressao[i] == '('){
            if(expressao[i] == '/'){
                yes = true;
            }
        } else if(!expressao[i] == '(' || !expressao[i] == '('){
            if(expressao[i] == '*' || expressao[i] == '+' || expressao[i] == '-' || expressao[i] == '^'){
                pos = i;
            }
            for(int j=0; j < pos; j++){
                linha[k++] = expressao[j];
            }
            linha[k++] = expressao[pos+1];
            linha[k++] = expressao[pos];
            linha[k++] = expressao[i];
            
        }
        linha[k] = '\0';
    }
    printf("%s", linha);
}

int main(){
    int n;
    char expressao[25];

    scanf("%d", &n);
    for(int i=0; i < n; i++){
        scanf(" %s", expressao);
        posIn(expressao);
    }
}