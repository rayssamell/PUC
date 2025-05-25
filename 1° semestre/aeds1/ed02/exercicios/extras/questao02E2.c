/*
Exercicios Extras - v0.0. - 17 / 03 / 2024
Author: Rayssa Mell de Souza Silva //860210
*/

#include <stdio.h> // para entradas e saidas
#include "io.h"

int main(){
	//identificar
	IO_id("\nQuestao 02E2- Programa - v0.0");
	//definir variaveis
	char x,y,z;
	//ler dados
	x = IO_readchar("Digite um caractere: ");
	y = IO_readchar("Digite um caractere: ");
	z = IO_readchar("Digite um caractere: ");
	//testar dados
	if( y != z){
		if(!(((y<=x) && (x<=z)) || ((y>=x) && (x>=z)))){
			IO_printf ("\n%s(%c)%s(%c)%s(%c)","O primeiro caractere ",x," nao esta no intevalo ",y ," e ",z);
		}
		else{
			IO_printf ("\n%s(%c)%s(%c)%s(%c)","O primeiro caractere ",x," esta no intevalo ",y ," e ",z);
		}
	}
	else
	{
		printf("O segundo e o terceiro caractere sao iguais");
	}
	IO_pause("\nApertar ENTER para continuar.");
	getchar( ); // aguardar por ENTER
}//end main
