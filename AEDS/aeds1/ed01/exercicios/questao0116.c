/*
Questao0116 - v0.0. - 15/03/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

#include<stdio.h>
#include<math.h>

int main(){
	/* PROGRAMA PARA LER O LADO DE UM TRIANGULO EQUILATERO E DEVOLVER A ALTURA, AREA E PERIMETRO*/
	
	// definir variaveis
	double area = 0.0, perimetro = 0.0;
	double altura= 0.0, lado = 0.0, novo_lado = 0.0;
	// identificar
	printf ( "Questao_04 - Area, Altura e Perimetro do Triangulo Equilatero\n" );
	//ler dado
	printf("Digite uma medida: ");
	scanf("%lf", &lado);
	// calcular o triplo do lado
	novo_lado = lado * 3.0;
	// calcular altura
	altura = (sqrt(3)*novo_lado)/2;
	//calcular area
	area = (pow(novo_lado,2) * sqrt(3))/4.0;
	//calcular perimetro
	perimetro = 3.0 * novo_lado;
	// mostrar altura
	printf ( "\nAltura com o triplo do lado = %.2lf", altura );
	// mostrar area
	printf ( "\nArea com o triplo do lado = %.2lf", area );
	// mostrar perimetro
	printf ( "\nPerimetro com o triplo do lado = %2.lf", perimetro );
	//encerrar
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	getchar( ); // para esperar
	return 0;
	
	
}
