/*
Exercicios Extras - v0.0. - 17 / 03 / 2024
Author: Rayssa Mell de Souza Silva //860210
*/

#include <stdio.h> // para entradas e saidas
#include "io.h"

int main(){
	//identificar
	IO_id("\nQuestao 02E1- Programa - v0.0");
	//definir variaveis
	char x, y, z;
	//ler dados
	x = IO_readchar("Digite um caractere: ");
	y = IO_readchar("Digite um caractere: ");
	z = IO_readchar("Digite um caractere: ");
	//testar dados
	if(((y<x) && (x<z)) || ((y>x) && (x>z))){
		IO_printf ("\n%s(%c)%s(%c)%s(%c)","O caractere ",x," esta entre ",y ," e ",z);
	}
	else
	{
		if(x == y){
			IO_printf ("O primeiro (%c) e o segundo (%c) sao iguais",x,y );
		}
		else{
			if(x==z){
				IO_printf ("O primeiro (%c) e o terceiro (%c) sao iguais",x,z );
			}
			else{
				IO_printf ("O primeiro caractere nao esta entre o segundo e o terceiro e sao diferentes" );
			}
		}
	}
	IO_pause("\nApertar ENTER para finalizar.");
	getchar( ); // aguardar por ENTER
}//end main
