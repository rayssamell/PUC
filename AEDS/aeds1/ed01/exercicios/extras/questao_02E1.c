/*
Questao0118 - v0.0. - 15/03/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

#include<stdio.h>
#include<math.h>

int main(){
	/* PROGRAMA PARA MOSTRAR O RAIO DE 5/8 DO VOLUME DA ESFERA E A AREA DA SUPERFICIE*/

	// definir variaveis
	double area = 0.0, volume = 0.0, raio = 0.0, n_volume = 0.0;
	//identificar
	printf("Questao_02E1 - Raio da Esfera e Area da Superficie\n");
	//ler dados
	printf("Digite uma medida: ");
	scanf("%lf", &volume);
	getchar();
	//calcular 5/8 do volume 
	n_volume = (5*volume)/8;
	raio = cbrt((3 * n_volume) / (4.0 * M_PI));
	area = 4.0 * M_PI * (pow(raio,2));
	//mostrar raio
	printf("1/7 do Raio da Circunferencia: %.2lf\n", raio);
	//mostrar area
	printf("Area da Superficie: %.2lf", area);
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	return 0;
	
}
