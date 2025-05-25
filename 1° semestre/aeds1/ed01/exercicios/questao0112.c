/*Rayssa Mell de Souza Silva - 860210 - ED01*/

#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
#include "io.h"
#include <math.h>

int main ( )
{
/* PROGRAMA PARA LER O LADO DE UM QUADRADO E MOSTAR A AREA E O PERIMETRO DE UM QUADRADO 
COM A METADE DO LADO*/
	
	// definir variavel:
	int perimetro = 0, lado = 0;
	double area = 0.0;
	//IDENTIFICAR
	printf ( "Questao_02 - Area de um quadrado com metade do valor do lado" );
	// ler dado
	lado = readint("\nDigite um valor inteiro:  ");
	// calcular a metade do lado e a area do novo lado
	area = pow((lado/2.0),2.0);
	// calcular metade do lado e perimetro do novo lado
	perimetro = (lado/2)*4;
	// mostrar area
	printf ( "\nArea do quadrado com metade do lado = %.2lf", area );
	//mostrar perimetro
	printf ( "\nPerimetro do quadrado com metade do lado = %i", perimetro );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
	return ( EXIT_SUCCESS );
} // fim do programa
