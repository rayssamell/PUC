#include <stdio.h>
#include <string.h>

void contar(char *s1, char *s2){
    int letras[256] = {0};
    int contador = 0;

    // Marca os caracteres presentes na primeira palavra
    for (int i = 0; i< strlen(s1); i++) {
        letras[s1[i]] = 1;
    }

    // Conta as ocorrências dos caracteres da primeira palavra na segunda
    for (int i = 0; i < strlen(s2); i++) {
        if (letras[s2[i]]) {
            contador++;
        }
    }
    printf("%d\n", contador);
}

int main(){
    char string1[100], string2[100];

    // Continua lendo enquanto consegue capturar dois strings na mesma linha
   
    while (fgets(string1, sizeof(string1), stdin) != NULL &&
           fgets(string2, sizeof(string2), stdin) != NULL) {

        string1[strcspn(string1, "\n")] = '\0';
        string2[strcspn(string2, "\n")] = '\0';

        contar(string1, string2);
        
    }



    return 0;
}