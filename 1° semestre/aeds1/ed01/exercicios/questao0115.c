/*Rayssa Mell de Souza Silva - 860210 - ED01*/
#include <stdio.h> // para entradas e saídas
#include <stdlib.h> // para outras funcoes de uso geral
#include <math.h>

int main ( )
{
	/* PROGRAMA PARA LER A BASE E A ALTURA DE UM TRIANGULO E MOSTAR A AREA COM O DOBRO DA ALTURA*/
	
	// definir variavel:
	double area = 0.0;
	double base = 0.0,altura = 0.0;
	
	//IDENTIFICAR
	printf ( "Questao_05 - Area do Triangulo\n" );
	// ler dados
	printf("Digite uma medida: ");
	scanf("%lf", &base);
	printf("Digite uma medida: ");
	scanf("%lf", &altura);
	// calcular a area seis vezes maior 
	//area = base * (altura*2) / 2;
	area = base * altura; 
	// mostrar area
	printf ( "\nArea do triangulo com o dobro da altura= %.2lf", area );
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
	return ( EXIT_SUCCESS );
} // fim do programa
