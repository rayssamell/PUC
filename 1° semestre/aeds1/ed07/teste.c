#include <stdio.h>
#include<string.h>
#include "io.h"

int ehPrimo(int valor){
	int impar = 1, cont = 0;
	
	if(valor == 2) {
		return 2;
	}
	else{
		if(valor % 2 != 0){
			while(impar <= valor){
				if(valor % impar == 0){
					cont =  cont + 1;
				}
				impar = impar + 2;
			}
		}
	}
	if(cont == 2){
		return valor;
	}
	
	return 0;
}

void p_06(void){
	int num = 11, cont = 0;
	int p1= 0, p2 = 0;
	int parSheldon = 0, primo = 0;
	
	while(num <= 99){
		primo = ehPrimo(num);
		
		p1 = (primo % 10) * 10;
		p2 = primo / 10;
		parSheldon = p1 + p2;
		
		if(ehPrimo(parSheldon)){
			printf("\n%d e %d\n", primo, parSheldon);
			cont = cont + 1;
		}
		num = num + 2;
	}
	printf("\nHa %d numeros de sheldon no intervalo", cont);
}


int f_07(char p[]){
	int x = 0, temT=0, temU=0;
	int naoUT = 0;
	
	for( x = 0; x < strlen(p); x = x + 1){
		
		if(p[x]=='T'){
		    temT = 1;
		}

		if(p[x]=='U'){
			temU = 1;
		}
		else{
			if(p[x]!= 'T' && p[x]!= 'U'){
				naoUT = 1;
			}
		}
	}
	if(temT && !(temU)){
		printf("DNA:2");
	}
	else{
		if(temU != temT){
			printf("RNA: 1");
		}
		else{
			if(naoUT){
				printf("0");
			}
			else{
				if(temT && temU){
					printf("-1");
				}
			}
		}
	}
	return 0;
}

void p_07(void){
	char p[] = "TACAGATA";
	f_07(p);
	
	
}

int main(){
	
	int opcao = 0;
	printf ( "%s\n", "Exercicios 0700 - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
		
	do{
		printf("\n%s\n", "\nOpcoes: ");
		printf("\n%s", "0 - Terminar");
		printf("\n%s", "1 - Metodo_01	2 - Metodo_02");
			
		printf("\n%s", "\nOpcao = ");
		scanf("%d", &opcao);
		getchar();
		// para mostrar a opcao lida
		printf ( "\n%s%d", "Opcao =  ", opcao );
		getchar();
		//testar valor
		switch (opcao) {
			case 1:
				p_06();
				break;
			case 2:
				p_07();
				break;
			default:
				printf("Erro: opcao invalida.");
				break;
			}
			
		}while(opcao != 0);
		
		printf("Aperte ENTER para terminar.");
		getchar();
		return(0);
		
}
	


