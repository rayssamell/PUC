#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char nome[20];
    char sexo[2];
    int f = 0, m = 0;

    scanf("%d", &n);
    for(int i=0; i < n; i++){
        scanf(" %s", nome);
        scanf(" %s", sexo);

        if(strcmp(sexo, "F") == 0){
            f++;
        } else {
            m++;
        }
    }
    printf("%d carrinhos\n", m);
    printf("%d bonecas\n", f);
}