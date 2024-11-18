#include<stdio.h>
#include "io.h"

/*Method_01*/
void method_01()
{
	IO_id("Method_01 - Quantidade de valores dentro e fora do intervalo");
	//definir variaveis
	double x = 0.0,y = 0.0,z = 0.0;
	int n = 0, quant_d = 0, quant_f = 0, c = 0;
	//ler dados
	x = IO_readdouble("\nDigite um valor para definir um intervalo: "); getchar();
	y = IO_readdouble("\nDigite outro valor pra definir um intervalo: "); getchar();
	n = IO_readint("\nEntre com uma quantidade: "); getchar();
	
	//repeticao
	c = 1;
	while(c <= n ){
		z = IO_readdouble("\nDigite um valor: "); getchar();
		
		if((z >= x) && (z <= y)){
			quant_d = quant_d +1;
//            printf("Dentro do intervalo: %d", quant_d);
		}
		else{
			if(!((z>=x) && (z<=y))){
				quant_f = quant_f + 1;
//                printf("Fora do Intervalo: %d", quant_f);
			}
		}
		c = c + 1;
		
	}
	printf("\nDentro do intervalo: %d", quant_d);
	printf("\nFora do Intervalo: %d", quant_f);
	
	printf("\n");
	printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
	getchar( );
	
}//end method_01

/*Method_02*/
bool isMaiscula ( char x )
{
// definir dado local
	bool result = false;
// testar a condicao
	if ('A' <= x && x <= 'Z' )
	{
		result = true;
	} // end if
	return ( result );
} // end isMaiscula

void method_02(void){
	//identificar
	IO_id("Method_02 -  Contar e mostrar a quantidade de letras maiusculas maiores que L");
	//definir variaveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int contador = 0;
	int tamanho = 0;
	// ler dados
	caracteres = IO_readstring("Digite uma cadeia de caracteres: ");
	getchar();
	tamanho = strlen(caracteres);
	printf("Maiusculas e maiores que L: ");
	for(int i = 0; i < tamanho; i = i + 1){
		if(caracteres[i] > 'L'){
			if ( isMaiscula ( caracteres[i] ) )
			{
				printf("%c", caracteres[i]);
				contador = contador + 1;
			} // end if
		} // end for
		}
	// mostrar a quantidade de maisculas e maiores que L
	IO_printf ( "\n%s%d\n", "Quantidade: ", contador);
	printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
	getchar( );
}//end method_02

/*Method_03*/
int isMaiusculas(chars caracteres){
	int contador = 0;
	for(int i = 0; i < strlen(caracteres); i = i + 1){
		if (caracteres[i] >= 'A' && caracteres[i] <= 'Z') {
			if (caracteres[i] > 'L') {
				contador = contador + 1;
			}
		}
	}
	return (contador);
}//end is maiscula

void method_03(void){
	//identificar
	IO_id("Method_03 -  Contar e mostrar a quantidade de letras maiusculas maiores que L");
	//definir variaveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int quant = 0;
	// ler dados
	caracteres = IO_readstring("Digite uma cadeia de caracteres: ");
	getchar();
	//chama a funcao
	quant = isMaiusculas(caracteres);
	// mostrar a quantidade de maisculas e maiores que L
	printf("Quantidade de letras maiúsculas maiores que 'L': %d\n", quant);
	
	printf ( "\n%s\n\n", "Apertar ENTER para continuar." );
	getchar( );
}//end method_03

/*Method_04*/
bool isMaior(char str){
	// testar a condicao
	bool result = false;
	
	if ( str >= 'A' && str <= 'Z') {
		if (str > 'L') {
			result = true;
		}
	}
	return ( result );
}

void method_04(void){
	//identificar
	IO_id("Method_04 -  Contar e mostrar a quantidade de letras maiores que L e l");
	//definir variaveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int tamanho = 0, i = 0;
	// ler cadeia de caracteres
	caracteres = IO_readstring("Digite uma cadeia de caracteres: ");
	getchar();
	// ver o tamanho da cadeia
	tamanho = strlen ( caracteres );
	printf("Maiusculas e maiores que L: ");
	while(i < tamanho){
		if ( isMaior (caracteres[i])  ){
			printf("%c ", caracteres[i]);
		}
	    i = i + 1;
	}
	printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
	getchar( );
}//end method_04

/*Method_05*/
int isMenor(chars str){
	int contador = 0;
	//testar a condicao
	//enquanto str for menor que \0 
	while (*str != '\0') {
		if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
			if ((*str >= 'A' && *str < 'L') || (*str >= 'a' && *str < 'l' )) {
				contador = contador + 1;
			}
		}
		str = str + 1;
	}
	return (contador);
}

void method_05(void){
	//identificar
	IO_id("Method_05 - Contar a quantidade de letras menores que L e l");
	//definir variaveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int quant = 0;
	// ler dados
	caracteres = IO_readstring("Digite uma cadeia de caracteres: ");
	getchar();
	// contar as letras menores que L e l
	quant = isMenor(caracteres);
	// mostrar a quantidade
	printf("Quantidade de letras minusculas menores que L e l: %d\n", quant);
	printf("\nApertar ENTER para terminar.\n");
	getchar();
}//end method_05

/* Method_06 */
bool mostrarLetras(char str){
	bool result = false;
	//testar condicao
	if ((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z')) {
		if ((str >= 'A' && str < 'L') || (str >= 'a' && str < 'l' )) {
			result = true;
		}
	}
	return (result);
}

void method_06(void){
	//identificar
	IO_id("\nMethod_05 - Mostrar a quantidade de letras menores que L e l\n");
	//definir variaveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int tamanho = 0; 
	// ler dados 
	caracteres = IO_readstring("Digite uma cadeia de caracteres: ");
	getchar();
	tamanho = strlen(caracteres);
	printf("\n Letras menor que L e l: ");
	for(int i = 0; i < tamanho; i = i + 1){
		if (mostrarLetras (caracteres[i])  ){
			printf("%c ", caracteres[i]);
		}
	}
	printf("\nApertar ENTER para terminar.\n");
	getchar();
}//end method_06

/*Method_07*/
bool isDigit(char str){
	bool result = false;
	if ( str >= '0' && str <= '9' ){
		if(str % 2 == 0){
			result = true;
		}
	} // end if
	return(result);
}

void method_07(void){
	//identificar
	IO_id("\nMethod_07 - Mostrar a quantidade de dígitos pares em uma cadeia de caracteres\n");
	//definir variaveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int quant = 0, tamanho = 0;
	char simbolo = '_';
	//ler dado
	caracteres = IO_readstring("Digite uma cadeia de caracteres: ");
	getchar();
	//verificar tamanho
	tamanho = strlen(caracteres);
	//testar dado
	for(int i = 0; i < tamanho; i = i + 1){
		simbolo = caracteres[i];
		if(isDigit((int)simbolo)){
			quant = quant + 1;
		}
	}
	//mostrar quantidade de pares
	printf("Quantidade de digitos pares: %d", quant);
	
	printf("\n");
	printf ( "\n%s\n\n", "Apertar ENTER para continuar." );
	getchar( );
}//end method_07

/*Method_08*/
bool isnAlphaNum(char str){
	bool result = false;
	if(!((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z'))) {
		if(!(str >= '0' && str <= '9' )){
			result = true;
		}
	}
	return(result);
}//end isnAlphaNum

void method_08(void){
	//identificar 
	IO_id("\nMethod_08 - Mostrar caracteres nao alfanumericos\n");
	//definir variaveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int tamanho = 0; 
	char simbolo = '_';
	//ler dados
	caracteres = IO_readstring("Digite uma cadeia de caracteres: ");
	//verficar tamanho
	tamanho = strlen(caracteres);
	//testar dados
	IO_printf("Caracteres nao alfanumericos: ");
	for(int i = 0; i < tamanho; i = i + 1){
		simbolo = caracteres[i];
		if(isnAlphaNum(simbolo)){
			printf("%c ", simbolo);
		}
	}
	printf("\n");
	printf ( "\n%s\n\n", "Apertar ENTER para continuar." );
	getchar( );
}//end method_08

/*Method_09*/
bool isAlphanum(char str){
	bool result = false;
	if(((str >= 'A' && str <= 'Z') || (str >= 'a' && str <= 'z')) || (str >= '0' && str <= '9' )) {
		result = true;
	}
	return(result);
}

void method_09(void){
	//identificar 
	IO_id("\nMethod_09 - Mostrar caracteres alfanumericos\n");
	//definir variaveis
	chars caracteres = IO_new_chars(STR_SIZE);
	int tamanho = 0;
	char alfanum = '_';
	//ler dados
	caracteres = IO_readstring("Digite uma cadeia de caracteres: ");
	getchar();
	//verificar tamanho
	tamanho = strlen(caracteres);
	//testar condicao
	printf("Caracteres alfanumericos: ");
	for(int i = 0; i < tamanho; i = i + 1){
		alfanum = caracteres[i];
		if(isAlphanum(alfanum)){
			printf("%c ", alfanum);
		}
	}
	printf("\n");
	printf ( "\n%s\n\n", "Apertar ENTER para continuar." );
	getchar( );
}//end method_09

/*Method_10*/

bool contAlphanum(char *str, int *contador){
	bool result = false;

		if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z') || (*str >= '0' && *str <= '9' )){
			*contador = *contador + 1;
			result = true;
		}
		
	return(result);
}

void method_10(void){
	//identificar
	IO_id("\nMethod_10 - Mostrar e contar a quantidade de simbolos alfanumericos\n");
	//definir variaveis
	chars palavra = IO_new_chars(STR_SIZE);
	int quant_p = 0, total = 0;
	int i = 0;
	
	//ler dados
	quant_p = IO_readint("Entre com uma quantidade: "); 
	getchar();
	
	while(i < quant_p){
		palavra = IO_readstring("\nDigite uma palavra: ");
		getchar();
		
		int tamanho = strlen(palavra);
		
		for(int n = 0; n < tamanho; n = n + 1){
			if(contAlphanum(&palavra[n], &total)){
				printf(" %c ", palavra[n]);
			}
		}
		i = i + 1;
	}
	
	printf("\nTotal de simbolos alfanumericos: %d\n", total);	
	
}//end method_10

/* EXTRAS */

/* Method_04E1*/
int Alphanum(char *str){
	int contador = 0;
	
	for (int i = 0; str[i] != '\0'; i = i + 1){
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9') || str[i] == ' ' ){
			contador = contador + 1;
		}
	}
	return(contador);
}

void method_04E1(void){
	//identificar
	IO_id("\nMethod_11 - Mostrar e contar a quantidade de simbolos alfanumericos\n");
	//definir variaveis
	chars palavra = IO_new_chars(STR_SIZE);
	int quant_p = 0, total = 0, quant = 0;
	
	//ler quantidade
	quant_p = IO_readint("Entre com uma quantidade: "); 
	getchar();
	
	for(int i = 0; i < quant_p; i = i +1){
		//ler palavras
		palavra = IO_readln("\nDigite uma palavra: ");
		getchar();
		// Contar simbolos alfanumericos
		quant = Alphanum(palavra);
		// mostrar a palavra com todos os simbolos mas contar somente os alfanumericos
		printf("Palavra: %s - Quantidade de simbolos alfanumericos: %d\n", palavra, quant);
		total += quant; //total = total + quant
	}
	printf("\nTotal de simbolos alfanumericos: %d\n", total);	
	
}//end method_04E1

/*Method_04E2*/
int MenorQuant(char *str) {
	int contador = 0;
	for (int i = 0; i < strlen(str); i = i + 1) {
		contador = contador + 1;
	}
	return contador;
}// end MenorQuant

void method_04E2(void){
	//identificar
	IO_id("\nMethod_12 - Comparar cadeias de caracteres para determinar a menor\n");
	//definir variaveis
	chars str_a = IO_new_chars(STR_SIZE);
	chars str_b = IO_new_chars(STR_SIZE);
	//ler dados
	str_a = IO_readstring("Digite uma cadeia de caracteres: ");
	str_b = IO_readstring("Digite outra cadeia de caracteres: ");
	//chamar funcao para ver qual a menor cadeia
	int digitos_a = MenorQuant(str_a);
	int digitos_b = MenorQuant(str_b);
	//  exibe resultados
	if (digitos_a > digitos_b) {
		printf("A cadeia com a menor quantidade de digitos eh a segunda: %s\n", str_b);
	} else if (digitos_a < digitos_b) {
		printf("A cadeia com a menor quantidade de digitos eh a primeira: %s\n", str_a);
	} else {
		printf("As duas cadeias de caracteres possuem a mesma quantidade de digitos\n");
	}
}//end method_04E2

int main()
{
// definir dados/resultados
	int opcao = 0;
	
// repetir ate' desejar parar
	do
	{
		// identificar
		printf ( "\n" );             // para saltar linha
		printf ( "%s\n", "\nEd04 - v.0.0 - 21/03/2024"       );
		printf ( "%s\n", "Matricula: 860210 Nome: Rayssa Mell de SOuza Silva" );
		
		// mostrar opcoes
		printf ( "%s\n", "\nOpcoes:"         );
		printf ( "%s\n", " 0 - parar"      );
		printf ( "%s\n", " 1 - metodo 01    2 - metodo 02" );
		printf ( "%s\n", " 3 - metodo 03    4 - metodo 04" );
		printf ( "%s\n", " 5 - metodo 05    6 - metodo 06" );
		printf ( "%s\n", " 7 - metodo 07    8 - metodo 08" );
		printf ( "%s\n", " 9 - metodo 09   10 - metodo 10" );
		printf ( "%s\n", " 11 - metodo 11  12 - metodo 12" );
		printf ( "%s\n", "" );        // para saltar linha
		
		// ler opcao
		printf ( "%s", "Qual a sua opcao? " );
		scanf  ( "%d", &opcao ); getchar ( );
		printf ( "\nOpcao: %d\n",  opcao );
		
		// escolher acao
		switch ( opcao )
		{
			case  0:               
			break;
			case  1: method_01 ( ); 
			break;
			case  2: method_02 ( ); 
			break;
			case  3: method_03 ( ); 
			break;
			case  4: method_04 ( ); 
			break;
			case  5: method_05 ( ); 
			break;
			case  6: method_06 ( ); 
			break;
			case  7: method_07 ( ); 
			break;
			case  8: method_08 ( ); 
			break;
			case  9: method_09 ( ); 
			break;
			case  10: method_10 ( ); 
			break;
			case  11: method_04E1 ( ); 
			break;
			case  12: method_04E2 ( ); 
			break;
			default:
			printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
			break;
		} // fim escolher
	}
	while ( opcao != 0 );
	
// encerrar execucao
	printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
	getchar( );
	return (0);
} // end main ( )


