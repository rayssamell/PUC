#include <stdio.h>

//funcao para gravar arquivo com os dados de entrada
void gravarArquivo(int n, char filename[]){
    FILE *arquivo = fopen(filename, "w");

    for (int i = 0; i < n; i++) {
        double valor;
        //ler valor
        scanf("%lf", &valor);
        // guarda no arquivo
        fprintf(arquivo, "%g\n", valor);
    }
    fclose(arquivo);
}

//funcao para ler arquivo
void lerArquivo(int n, char filename[]){
    FILE *arquivo = fopen(filename, "r");
    double valor;

    //posiciona no fim do arquivo
    fseek(arquivo, 0, SEEK_END);
    //guarda a posicao
    long pos = ftell(arquivo);
    
    while(pos > 0){
        fseek(arquivo, --pos, SEEK_SET);
        if(fgetc(arquivo) =='\n' || pos == 0){
            if (pos == 0) {
                fseek(arquivo, pos, SEEK_SET);
            } else {
                fseek(arquivo, pos + 1, SEEK_SET);
            }

            // le o valor do arquivo e mostra
            if (fscanf(arquivo, "%lf", &valor) == 1) {
                printf("%g\n", valor);
            }

            // move o ponteiro de volta para a posicao anterior
            fseek(arquivo, pos, SEEK_SET);
        }
    }
    fclose(arquivo);
}

//metodo principaç
int main(){
    int n;
    scanf("%d", &n);

    gravarArquivo(n, "teste.txt");
    lerArquivo(n, "teste.txt");

    return 0;
}