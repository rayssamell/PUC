/*
Questao0118 - v0.0. - 15/03/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

#include<stdio.h>
#include<math.h>

int main(){
	//PROGRAMA PARA CALCULAR O VOLUME DE UMA ESFERA COM 3/4 DO RAIO 

	//definir variaveis
	double raio = 0.0, n_raio = 0.0, volume = 0.0;
	// identificar
	printf("Questao_09 - Calcular Area de uma Esfera\n");
	// ler dados
	printf("Digite uma medida: ");
	scanf("%lf", &raio);
	getchar();
    // calcular 3/4 do raio e volume
	n_raio = (raio * 3.0)/4.0;
	volume = (pow(n_raio,3)*M_PI*4)/3.0;
	// mostrar volume
	printf("Volume da esfera com 3/4 do raio: %.2lf",volume);
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	return 0;
}
