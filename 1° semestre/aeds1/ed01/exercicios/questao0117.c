/*
Questao0117 - v0.0. - 15/03/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

#include <stdio.h>//para entradas e saidas
#include <math.h>

int main(){
	/* PROGRAMA PARA LER OS LADOS DE UM RETANGULO E MOSTRAR A AREA SEIS VEZES MAIOR*/
	
	// definir variavel
	double lado = 0.0;
	double volume = 0.0;
	//IDENTIFICAR
	printf ( "Questao_07 - Volume do Cubo\n" );
	//ler dado
	printf ( "\nDigite uma medida qualquer: " );
	scanf ( "%lf", &lado );
    getchar();
	//calcular volume do cubo com lado 5 vezes maior
	volume = pow((lado*5.0),3);
	// mostrar volume
	printf("Volume do Cubo com lado 5 vezes maior: %.2lf", volume);
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	return 0;
	
}
