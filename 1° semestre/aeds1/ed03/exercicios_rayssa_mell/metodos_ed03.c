/*
Exercicios - v0.0. - 11/03/2024
Author: Rayssa Mell de Souza Silva - 860210
*/
// dependencias
#include<stdio.h>
#include<string.h>
#include "io.h"

/*
Method_01
*/
void method_01(void){
// identificar
	printf ( "%s\n", "\nMethod_01- Mostrar letras maiusculas" );
	// definir tipo de dado 
	chars palavra = IO_new_chars(STR_SIZE);
	// ler dado
	printf("\nDigite uma palavra: ");
	scanf("%[^\n]", palavra);
	getchar();//limpar
	// contar quantas letras tem a palavra
	int tamanho = strlen(palavra);
	printf("\nLetras maiusculas na palavra: ");
	for(int i = 0; i < tamanho; i = i +1 ){
		// 65 para A | 90 para Z
		if((int)palavra[i] >= 65 && (int)palavra[i] <= 90){
			printf("%c ",  palavra[i]);
		}
	}
	printf("\n");
	printf("\nAperte ENTER para continuar\n");
	getchar();
}// end method_01

/*
Method_02
*/
void method_02(void){
// identificar
	printf ( "%s\n", "\nMethod_02- Mostrar letras maiusculas e contar" );
	// definir tipo de dado 
	char palavra [50];
	int qtd = 0;
	// ler dado
	printf("\nDigite uma palavra: ");
	scanf("%[^\n]", palavra);
	getchar();//limpar
	// contar quantas letras tem a palavra
	int tamanho = strlen(palavra);
	printf("\nLetras maiusculas na palavra: ");
	for(int i = 0; i < tamanho; i++){
		// 65 para A | 90 para Z
		if((int)palavra[i] >= 65 && (int)palavra[i] <= 90){
			printf("%c ",  palavra[i]);
			qtd += 1;
		}
	}
	printf("\nQuantidade de letras maiusculas: %d \n",qtd);
	
	printf("\nAperte ENTER para continuar\n");
	getchar();
}// end method_02

/*
Method_03
*/
void method_03(void){
// identificar
	printf ( "%s\n", "\nMethod_03- Mostrar letras maiusculas do fim para o inicio e contar" );
	// definir tipo de dado 
	char palavra [50];
	int qtd = 0;
	int i = 0;
	// ler dado
	printf("\nDigite uma palavra: ");
	scanf("%[^\n]", palavra);
	getchar();
	getchar();//limpar
	// contar quantas letras tem a palavra
	int tamanho = strlen ( palavra ) - 1;
	printf("\nLetras maiusculas na palavra: ");
	for(i = tamanho; i >= 0; i = i - 1){
		// 65 para A | 90 para Z
		if((int)palavra[i] >= 65 && (int)palavra[i] <= 90){
			printf("%c ",  palavra[i]);
			qtd += 1;
		}
	}
	printf("\nQuantidade de letras maiusculas: %d\n",qtd);

	printf("\nAperte ENTER para continuar\n");
	getchar();
}// end method_03

/*
Method_04
*/
void method_04(void){
	// identificar
	printf("\n%s\n", "Method_04- Contar e Mostrar letras maiuscula e minusculas");
	// definir tipo de dados
	char palavra [50];
	int qtd = 0;
	// ler dados
	printf("Digite uma palavra: ");
	scanf("%[^\n]", palavra);
	getchar();
	int tamanho = strlen ( palavra );
	for(int i = 0; i < tamanho; i++){
		if (((int)palavra[i] >= 65 && (int)palavra[i] <= 90) || ((int)palavra[i] >= 97 && (int)palavra[i] <= 121))
		{
			printf("%c ",  palavra[i]);
			qtd = qtd + 1;
		}
	}
	printf("\nQuantidade de letras maiusculas e minusculas: %d\n",qtd);
	printf("\nAperte ENTER para continuar\n");
	getchar();
}//end method_04

/* Method_05*/
void method_05(){
	//identificar
	IO_id("\nMethod_05- Contar e mostrar todos os digitos.");
	//definir variaveis
	chars digitos = IO_new_chars(STR_SIZE);
	int quant = 0;	
	//ler dados
	printf("Digite uma cadeia de caracteres: ");
	scanf("%[^\n]", digitos);	
	getchar();
	//testar dados
	printf("\nDigitos: ");
	for(int i = strlen(digitos)-1; digitos[i] != '\0'; i = i - 1){
		if(digitos[i] >= '0' && digitos[i] <= '9'){
			printf("%c", digitos[i]);
			quant = quant + 1;
			}
	}
	printf("\nQuantidade: %d\n",quant);
	printf("\nAperte ENTER para continuar\n");
	getchar();
}//end method_05

/*Method_06*/
void method_06(void){
	//identificar
	IO_id("\nMethod_06 - Contar e mostrar tudo o que nao for digito e tambem nao for letra.\n");
	//definir variaveis
	chars caractere = IO_new_chars(STR_SIZE);
	int quant = 0;
	//ler dados
	printf("Digite uma cadeia de caracteres: ");
	scanf("%[^\n]", caractere); getchar();
	printf("\n");
	//testar dados 
	printf("Caractere: ");
	for(int i = 0; caractere[i] != '\0'; i = i +1){
		if (!(((int)caractere[i] >= 65 && (int)caractere[i] <= 90) || ((int)caractere[i] >= 97 && (int)caractere[i] <= 121))){
			if(!((int)caractere[i] >= '0' && (int)caractere[i] <= '9')){
				printf("%c", caractere[i]);
				quant = quant + 1;
			}
		}
	}
	printf("\nQuantidade de caractere que nao eh digito ou letra: %d",quant);
	printf("\n");
	printf("\nAperte ENTER para continuar\n");
	getchar();
}//end method_06

/*Method_07*/
void method_07(){
	//identificar
	IO_id("\nMethod_07 - Mostrar os multiplos de 6 que pertencam ao intervalo\n");
	//definir variaveis
	int a = 0, b = 0, quant = 0;
	int n = 0, x = 0, c = 0;
	//ler dados 
	a = IO_readint("Digite o intervalo inferior: ");
	b = IO_readint("Digite o intervalo superior: ");
	n = IO_readint("Digite a quantidade: ");
	//testar dados
	c = 1;
	while(c <= n){
		x = IO_readint("\nDigite um valor: ");
		if(x >= a && x <= b){
			if(x % 6 == 0){
				printf("\nDentro do intervalo [%d:%d] e multiplo de 6: %d \n", a,b,x);
				quant = quant + 1;
			}
		}
		c = c + 1;
	}
	printf("\nQuantidade dos valores que estao dentro do intervalo e sao multiplos de 6: %d\n", quant);
	printf("\nAperte ENTER para continuar\n");
	getchar();
}//end method_07

/*Method_08*/
void method_08(void){
	//identificar 
	IO_id("\nMethod_08 - Multiplos de 4 que pertencam ao intervalo \n");
	//definir variaveis 
	int a = 0, b = 0, quant = 0;
	int n = 0, x = 0; 
	//ler dados 
	a = IO_readint("Digite o primeiro valor: ");
	b = IO_readint("Digite o segundo valor: ");
	n = IO_readint("Defina a quantidade de valores: ");
	//testar dados
	for(int i = 0; i < n; i = i + 1){
		x = IO_readint("\nDigite um valor: ");
		if( x >= a && x <= b){
			if( (x % 4 == 0) && (!(x % 5 == 0))){
				printf("%d", x);
				quant = quant + 1; 
			}
		}
		else{
			printf("Fora do Intervalo\n");
		}
	}
	printf("\nQuantidade: %d\n", quant);
}//end method_08

/*Method_09*/
void method_09(void){
	//identificar
	IO_id("\nMethod_09 - Contar e mostrar todos os valores pares lidos, pertencentes ao do intervalo\n");
	//definir variaveis
	double a = 0.0, b = 0.0, x = 0.0;
	int n = 0, i = 0, quant = 0;
	//ler dados
	a = IO_readdouble("Digite o primeiro valor: "); getchar();
	b = IO_readdouble("Digite o segundo valor: "); getchar();
	n = IO_readint("Entre com uma quantidade: "); getchar();
	//testar dados
	if(a < b){
		while(i < n){
			x = IO_readdouble("Digite um valor: ");getchar();
			if ( x > a && x < b ){
				if((int)x % 2 == 0){
					printf("%s%lf\n", "Esse numero eh par: ", x);
					printf("\n");
					quant = quant + 1;
				}
			}
		    else{
				printf("Fora do intervalo\n");
			}
			i = i + 1;
		}
	}
	else{
		printf("ERRO: Nao eh possivel definir o intervalo, primeiro valor maior que segundo.");
	}
	printf("\nQuantidade de numeros pares: %d\n", quant);
	printf("\nAperte ENTER para continuar\n");
	getchar();
}//end method_09

/*Method_10*/
void method_10(void){
	//identificar
	IO_id("\nMethod_10 - Contar e mostrar os valores que tenham as partes fracionárias fora do intervalo \n");
	//definir variaveis
	double a = 0.0, b = 0.0, x = 0, f = 0;
	int n = 0, i = 0, quant = 0; 
	//testar dados
	a = IO_readdouble("Digite o primeiro valor entre 0 e 1: "); getchar();
	b = IO_readdouble("Digite o segundo valor entre 0 e 1: "); getchar();
	n = IO_readint("Entre com uma quantidade: "); getchar();
	
	if((a > 0 && a < 1) && (b > 0 && b < 1)){
		while(i < n){
			x = IO_readdouble("Digite um valor: ");getchar();
			f = x - (int)x;
			if (!(f > a && f < b)){
				printf("O valor %.3lf esta fora do Intervalo ]%lf,%lf[ \n",f, a,b);
				printf("\n");
				quant = quant + 1;
			}
			else{
				printf("Dentro do intervalo\n");
				printf("\n");
			}
			i = i + 1;
		}
	}
	else{
		printf("Os valores precisam ser maio que 0 e menor que 1.");
	}
	
	printf("\nQuantidade de numeros fora do intervalo: %d\n", quant);
	printf("\nAperte ENTER para continuar\n");
	getchar();
}//end method_10

/* TAREFAS EXTRAS*/

void method_03E1(void){
	//identificar
	IO_id("\nMethod_03E1\n");
	//definir variaveis
	chars caractere = IO_new_chars(STR_SIZE);
	int quant = 0;
	//ler dados
	caractere = IO_readln("Digite uma cadeia de caracteres: ");
	getchar();
	//testar dados 
	printf("%s", "Caractere: ");
	for(int i = 0; caractere[i] != '\0'; i = i +1){
		if (!(((int)caractere[i] >= 65 && (int)caractere[i] <= 90) || ((int)caractere[i] >= 97 && (int)caractere[i] <= 121))){
			if(!((int)caractere[i] >= '0' && (int)caractere[i] <= '9')){
				printf("%c", caractere[i]);
				quant = quant + 1;
			}
		}
	}
	printf("\nQuantidade de caractere nao digito ou letra: %d",quant);
	printf("\n");
	printf("\nAperte ENTER para continuar\n");
	getchar();
}//end method_03E1

/*Method_03E2*/
void method_03E2(void){
	// identificar
	IO_id("\nMétodo_03E2\n");
	// definir variáveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int i = 0;
	// ler dados
	printf("Digite uma cadeia de caracteres: ");
	scanf("%[^\n]", caracteres);
	getchar(); 
	// Testar dados
	int tamanho = strlen(caracteres);
	while(i < tamanho){
		if (((int)caracteres[i] >= 65 && (int)caracteres[i] <= 90) || ((int)caracteres[i] >= 97 && (int)caracteres[i] <= 122)){
			i = i + 1;
		} 
		else {
			printf("A sequencia contem caracteres que nao sao letras\n");
			printf("\nAperte ENTER para continuar\n");
			getchar(); 
		}
	}
	printf("A sequencia contem apenas letras\n");
	
	printf("\nAperte ENTER para continuar\n");
	getchar();
}

int main(){
	//definir dado
	int opcao = 0;
	//identificar
	printf ( "%s\n", "Exercicios - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
	// acoes
	// repetir
	do{
		//para mostrar opcoes
		printf("\n%s\n", "Opcoes: ");
		printf("\n%s", "0 - Terminar");
		printf ( "\n%s" , "1 - Method_01    2 - Method_02" );
		printf ( "\n%s" , "3 - Method_03    4 - Method_04" );
		printf ( "\n%s" , "5 - Method_05    6 - Method_06" );
		printf ( "\n%s" , "7 - Method_07    8 - Method_08" );
		printf ( "\n%s" , "9 - Method_09    10 - Method_10" );
		printf ( "\n%s" , "11 - Method_11   12 - Method_12" );
		printf ( "\n" );
		// ler a opcao do teclado
		printf ( "\n%s", "Opcao = " );
		scanf ( "%d", &opcao );
		getchar( ); // para limpar a entrada de dados
		// para mostrar a opcao lida
		printf ( "\n%s%d", "Opcao = ", opcao );
		// escolher acao dependente da opcao
		switch ( opcao )
		{
			case 0: //nao fazer nada
			break;
			case 1: // executar method_01
			method_01 ( );
			break;
		    case 2: //executar Method_02
			method_02 ( );
			break;
			case 3: //executar Method_03
			method_03 ( );
			break;
			case 4: //executar Method_03
			method_04 ( );
			break;
			case 5: //executar Method_05
			method_05 ( );
			break;
			case 6: //executar Method_06
			method_06 ( );
			break;
			case 7: //executar Method_07
			method_07 ( );
			break;
			case 8: //executar Method_08
			method_08 ( );
			break;
			case 9: //executar Method_09
			method_09 ( );
			break;
			case 10: //executar Method_10
			method_10 ( );
			break;
			case 11: //executar Method_03E1
			method_03E1 ( );
			break;
			case 12: //executar Method_03E2
			method_03E2 ( );
			break;
			default: // comportamento padrao
			printf ( "\nERRO: Opcao invalida.\n" );
			break;
		} // end switch
	}while(opcao != 0);
	// encerrar
	printf ( "\n\nApertar ENTER para terminar." );
	getchar( ); // aguardar por ENTER
	return ( 0 ); 	
}
