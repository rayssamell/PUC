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

//funcao para determinar se uma palavra e' ou nao palindromo
bool classificarPalindromo(char palavra[], int i){
    int n = str_len(palavra);
    bool resp;
	
	if(i >= n / 2){
		resp = true;
	} else if (palavra[i] != palavra[n - i - 1]){
        resp = false;
    } else {
		resp = classificarPalindromo(palavra, i + 1);
    }

    return resp;
}

//metodo principal
int main (){
    char palavra[500];
    scanf(" %[^\n]", palavra);  
    
    while(!str_cmp(palavra, "FIM")){
        if(classificarPalindromo(palavra, 0))
			printf("SIM\n");
		else
            printf("NAO\n");
        scanf(" %[^\n]", palavra);  
    }
    return 0;
}
