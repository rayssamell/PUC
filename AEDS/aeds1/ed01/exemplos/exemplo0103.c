/*
Exemplo0103 - v0.0. - 11/03/2024
Author: Rayssa Mell de Souza Silva
*/
// dependencias
#include <stdio.h> // para as entradas e saidas
#include <stdlib.h> // para outras funcoes de uso geral
/**
  Method_01.
 */
void method_01 ( void )
{// definir dado
	int x = 0; // definir variavel com valor inicial
// identificar
	printf ( "\n%s\n", "\nMethod_01 - Programa = v0.0" );
// mostrar valor inicial
	printf ( "\n%s%d\n", "x = ", x );
// OBS.: O formato para int -> %d (ou %i)
	printf ("&%s%p\n" , "x = ", &x );
// OBS.: O formato para endereco -> %p)
// ler do teclado
	printf ( "Entrar com um valor inteiro: " );
	scanf ( "%d", &x );
// OBS.: Necessario indicar o endereco -> &
	getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
	printf ( "%s%i\n", "x = ", x );
// encerrar
	printf ( "\n\nApertar ENTER para continuar." );
	getchar( ); // aguardar por ENTER
} // end method_01 ( )
/**
  Method_02.
 */
void method_02 ( void )
{
// definir dado
	double x = 0.0; // definir variavel com valor inicial
// OBS.: Definir a parte fracionaria e' util
// identificar
	printf ( "\n%s\n", "Method_02 - Programa - v0.0" );
// mostrar valor inicial
	printf ( "\n%s%lf\n", "x = ", x );
// OBS.: O formato para double -> %lf
// ler do teclado
	printf ( "Entrar com um valor real: " );
	scanf ( "%lf", &x );
// OBS.: Necessario indicar o endereco -> &
	getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
	printf ( "%s%lf\n", "x = ", x );
// encerrar
	printf ( "\n\nApertar ENTER para continuar.\n" );
	getchar( ); // aguardar por ENTER
} // end method_02 ( )

/**
  Method_03.
 */
void method_03 ( void )
{
// definir dado
	char x = 'A'; // definir variavel com valor inicial
// OBS.: Indispensavel usar apostrofos
// identificar
	printf ( "\n%s\n", "Method_03 - Programa - v0.0" );
// mostrar valor inicial
	printf ( "\n%s%c\n", "x = ", x );
// OBS.: O formato para char -> %c
// ler do teclado
	printf ( "Entrar com um caractere: " );
	scanf ( "%c", &x );
// OBS.: Necessario indicar o endereco -> &
	getchar ( ); // OBS.: Limpar a entrada de dados
// mostrar valor lido
	printf ( "%s%c\n", "x = ", x );
// encerrar
	printf ( "\n\nApertar ENTER para continuar.\n" );
	getchar( ); // aguardar por ENTER
} // end main( )

int main ( int argc, char* argv [ ] )
{
// definir dado
	int opcao = 0;
// identificar
	printf ( "%s\n", "Exemplo0103 - Programa = v0.0" );
	printf ( "%s\n", " Autor:Rayssa Mell de Souza Silva" );
	printf ( "\n" ); // mudar de linha
// acoes
// repetir
	do
	{
		// para mostrar opcoes
		printf ( "\n%s\n", "Opcoes:" );
		printf ( "\n%s" , "0 - Terminar" );
		printf ( "\n%s" , "1 - Method_01" );
		printf ( "\n%s" , "2 - Method_02" );
		printf ( "\n%s" , "3 - Method_03" );
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
			case 0: // nao fazer nada
			break;
			case 1: // executar method_01
			method_01 ( );
			break;
			case 2: // executar method_02
			method_02 ( );
			break;
			case 3: // executar method_03
			method_03 ( );
			break;
			default: // comportamento padrao
			printf ( "\nERRO: Opcao invalida.\n" );
			break;
		} // end switch
	}
	while ( opcao != 0 );
// encerrar
	printf ( "\n\nApertar ENTER para terminar." );
	getchar( ); // aguardar por ENTER
	return ( 0 ); // voltar ao SO (sem erros)
} // end main ( )
/*
---------------------------------------------- erros
In function 'method_03':
[Aviso]  'return' with a value, in function returning void [-Wreturn-type]
[Nota]  declared here
Solução: retirar return(0) e deixar somente no int main.

---------------------------------------------- Saidas
Opcao = 3
Method_03 - Programa - v0.0

x = A
Entrar com um caractere: G
x = G


Apertar ENTER para continuar.
---------------------------------------------- previsao de testes
a.)x = A
Entrar com um caractere: b
x = b

b.)x = A
Entrar com um caractere: L
x = L
---------------------------------------------- historico
Versao Data Modificacao
0.1 11/03 esboco
0.2 11/03 mudanca de versao
0.3 11/03 mudanca de versao
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
leitura e exibicao de inteiro
0.2 01. ( OK ) identificacao de programa
leitura e exibicao de real
0.3 01. (ERRO)
    0.2 ( OK ) identificacao de programa
*/
