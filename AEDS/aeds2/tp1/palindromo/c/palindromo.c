#include <stdio.h>
#include <stdbool.h>

// funcao para determinar tamanho da palavra
int str_len(char *palavra){
    int length = 0;
	while(*(palavra+length)){ 
		length++;
	}
	return(length);
}

//funcao para comparar strings 
bool str_cmp(char palavra1[], char palavra2[]){
    bool resp = true;
    int length = str_len(palavra1);

    if(length != str_len(palavra2)){
        resp = false;    
    } else {
        for(int i = 0; i < length; i++){
            if(palavra1[i] != palavra2[i]){
               resp = false;
               i = length;
            } 
        }
    }
    return (resp);
}

//procedimento para determinar se uma palavra e' ou nao palindromo
void classificarPalindromo(char palavra[]){
    int n = str_len(palavra);
    bool resp = true;
    for(int i = 0; i < n / 2; i++){
        if(palavra[i] != palavra[n - i - 1]){
           resp = false;
           i = n;
        } 
    }
    if(resp) printf("SIM\n");
    else printf("NAO\n");
}

//metodo principal
int main (){
    char palavra[500];
    scanf(" %[^\n]", palavra);  
    
    while(!str_cmp(palavra, "FIM")){
        classificarPalindromo(palavra);
        scanf(" %[^\n]", palavra);  
    }
    return 0;
}
