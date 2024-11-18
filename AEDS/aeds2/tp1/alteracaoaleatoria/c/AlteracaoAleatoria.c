#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>  // pra uso do rand()

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
    
// funcao para substituir caractere na String
void substituirString(char s[], int i,char novaFrase[], char letraAntiga, char letraNova){
    //char novaFrase[500] = "";
   
	if(i == str_len(s)){
		novaFrase[i] ='\0';
		printf("%s\n", novaFrase);
	} else {
    	if (s[i] == letraAntiga) {
        	novaFrase[i] = letraNova;
    	} else {
        	novaFrase[i] = s[i];
		}
		substituirString(s, i + 1, novaFrase, letraAntiga, letraNova);
    }
}

//metodo principal
int main (){
    char s[500];
	char novaFrase[500];
	srand(4); //seed 4

    scanf(" %[^\n]", s);  
    
    while(!str_cmp(s, "FIM")){
		char letraAntiga = 'a' + (rand() % 26);
    	char letraNova = 'a' + (rand() % 26);  

        substituirString(s, 0, novaFrase, letraAntiga, letraNova);
        scanf(" %[^\n]", s);  
	}
    return 0;
}
