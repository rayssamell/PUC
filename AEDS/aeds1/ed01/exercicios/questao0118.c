/*
Questao0118 - v0.0. - 15/03/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

#include<stdio.h>//para entradas e saida
#include <math.h>

int main(){
	// PROGRAMA PARA CALCULAR O VOLUME DE UM PARALELEPIPEDO COM UM OITAVO DAS MEDIDAS
	
	//definir variaveis
	float altura = 0.0, largura = 0.0, comprimento = 0.0;
	float volume = 0.0;
	// identificar
	printf("Questao_08 - Volume do Paralelepipedo\n" );
	// ler dados
	printf("Digite a primeira medida: ");
	scanf("%f", &altura);
	
	printf("Digite a segunda medida: ");
	scanf("%f", &largura);
	
	printf("Digite a terceira medida: ");
	scanf("%f", &comprimento);
	getchar();
	//calcular 1/8 de cada medida e o volume 
	volume = (altura/8)*(comprimento/8)*(largura/8);
	// mostrar volume
	printf("Volume de um paralelepipedo com 1/8 das medidas inseridas: %.2f", volume);
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	return 0;
}
