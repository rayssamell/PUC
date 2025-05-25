/*
Questao0118 - v0.0. - 15/03/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

#include<stdio.h>
#include<math.h>

int main(){
	/* PROGRAMA PARA MOSTRAR 1/7 DO RAIO DE UMA CIRCUNFERENCIA.*/
	// definir variaveis
	double area = 0.0, raio = 0.0;
	//identificar
	printf("Questao_01E1 - Raio Setimo de uma Circunferencia\n");
	//ler dados
	printf("Digite uma medida: ");
	scanf("%lf", &area);
	getchar();
	//calcular raio setimo
	// a = pi* r²
	raio = (sqrt(area/M_PI))/7;
	//mostrar raio
	printf("1/7 do Raio da Circunferencia: %lf", raio);
	printf ( "\nPRESSIONAR <Enter> PARA TERMINAR." );
	return 0;
	
}
