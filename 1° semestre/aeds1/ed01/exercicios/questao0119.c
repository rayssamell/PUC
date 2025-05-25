/*
Questao0118 - v0.0. - 15/03/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

#include<stdio.h>
#include<math.h>

int main(){
	//PROGRAMA PARA CALCULAR A AREA DE UM SEMICIRCULO COM UM SEXTO DO RAIO
	// definir variaveis
	double raio = 0.0, n_raio = 0.0, area = 0.0;
	//identidficar
	printf("Questao_09 - Calcular Area de um Semicirculo\n");
	// ler dados
	printf("Digite uma medida: ");
	scanf("%lf", &raio);
	getchar();
	//calcular 1/6 do raio e area
	n_raio = raio/6.0;
	area = (M_PI *  pow(n_raio,2))/2.0;
	//mostrar area
	printf("Area do semicirculo com 1/6 do lado: %.2lf", area);
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	return 0;
}
