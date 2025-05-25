/*
Exemplo0206 - v0.0. - 16 / 03 / 2024
Author: Rayssa Mell de Souza Silva
*/
// dependencias
#include "io.h" // bibliotecas e outras definicoes

/**
  Method_01.
 */
void method_01 ( void )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// identificar
	IO_id ( "\nMethod_01 - Programa - v0.0" );
// ler do teclado
	x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
	if ( x == 0 )
	{
		IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
	}
	if ( x != 0 )
	{
		IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
	} // end if
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/*
Method_02.
*/
void method_02 ( void )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// identificar
	IO_id ("\nMethod_02 - Programa - v0.0" );
// ler do teclado
	x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
	if ( x == 0 )
	{
		IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
	}
	else // equivalente a "caso diferente do já' testado"
	{
		IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
	} // end if
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/*
Method_03.
*/
void method_03 ( void )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// identificar
	IO_id ( "\nMethod_03 - Programa - v0.0" );
// ler do teclado
	x = IO_readint ( "Entrar com um valor inteiro: " );
// testar valor
	if ( x == 0 )
	{
		IO_printf ( "%s (%d)\n", "Valor igual a zero", x );
	}
	else
	{
		IO_printf ( "%s (%d)\n", "Valor diferente de zero ", x );
		if ( x > 0 )
		{
			IO_printf ( "%s (%d)\n", "Valor maior que zero", x );
		}
		else
		{
			IO_printf ( "%s (%d)\n", "Valor menor que zero", x );
		} // end if
	} // end if
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/*
Method_04.
*/
void method_04 ( void )
{
// definir dado
	double x = 0.0; // definir variavel com valor inicial
// identificar
	IO_id ( "\nEXEMPLO0204 - Programa - v0.0" );
// ler do teclado
	x = IO_readdouble ( "Entrar com um valor real: " );
// testar valor
	if ( 1.0 <= x && x <= 10.0 )
	{
		IO_printf ( "%s (%lf)\n", "Valor dentro do intervalo [1:10] ", x );
	}
	else
	{
		IO_printf ( "%s (%lf)\n", "Valor fora do intervalo [1:10] ", x );
		if ( x < 1.0 )
		{
			IO_printf ( "%s (%lf)\n", "Valor abaixo do intervalo [1:10] ", x );
		}
		else
		{
			IO_printf ( "%s (%lf)\n", "Valor acima do intervalo [1:10]", x );
		} // end if
	} // end if
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/*
Method_05.
*/
void method_05 ( void )
{
// definir dado
	char x = '_'; // definir variavel com valor inicial
// identificar
	IO_id ( "\nMethod_05 - Programa - v0.0" );
// ler do teclado
	x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
	if ( ('a' <= x) && (x <= 'z') )
	{
		IO_printf ( "%s (%c)\n", "Letra minuscula", x );
	}
	else
	{
		IO_printf ( "%s (%c)\n", "Valor diferente de minuscula", x );
		if ( ('A' <= x) && (x <= 'Z') )
		{
			IO_printf ( "%s (%c)\n", "Letra maiuscula", x );
		}
		else
		{
			if ( ('0' <= x) && (x <= '9') )
			{
				IO_printf ( "%s (%c)\n", "Algarismo", x );
			}
			else
			{
				IO_printf ( "%s (%c)\n", "Valor diferente de algarismo", x );
			} // end if
		} // end if
	} // end if
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/*
Method_06.
*/
void method_06 ( void )
{
// definir dado
	char x = '_'; // definir variavel com valor inicial
// identificar
	IO_id ( "\nMethod_06 - Programa - v0.0" );
// ler do teclado
	x = IO_readchar ( "Entrar com um caractere: " );
// testar valor
	if ( ( 'a' <= x && x <= 'z' ) || // minuscula OU
		( 'A' <= x && x <= 'Z' ) ) // maiuscula
	{
		IO_printf ( "%s (%c)\n", "Letra", x );
	}
	else
	{
		IO_printf ( "%s (%c)\n", "Valor diferente de letra", x );
	} // end if
// encerrar
	IO_pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

int main ( void )
{
// definir dado
	int opcao = 0;
// identificar
	printf ( "%s\n", "Exemplo0206 - Programa = v0.0" );
	printf ( "%s\n", "Autor: Rayssa Mell de Souza Silva" );
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
		printf ( "\n%s" , "4 - Method_04" );
		printf ( "\n%s" , "5 - Method_05" );
		printf ( "\n%s" , "6 - Method_06" );
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
			case 0: /* nao fazer nada */ break;
			case 1: method_01 ( ); break;
			case 2: method_02 ( ); break;
			case 3: method_03 ( ); break;
			case 4: method_04 ( ); break;
			case 5: method_05 ( ); break;
			case 6: method_06 ( ); break;
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

---------------------------------------------- Saidas
Opcao = 6
Method_06 - Programa - v0.0
Autor: ________________________

Entrar com um caractere: f
Letra (f)

Apertar ENTER para continuar
---------------------------------------------- previsao de testes
a.) [B] - letra (B)
b.) [g] - letra (g)
c.) [5] - diferente de letra
---------------------------------------------- historico
Versao Data Modificacao
0.1 16/03 esboco
0.2 16/03 
0.3 16/03 
0.4 16/03 
0.5 16/03 
0.6 16/03 
---------------------------------------------- testes
Versao Teste
0.0 00. ( OK ) identificacao de programa
0.0 01. ( OK ) identificacao de programa
0.0 02. ( OK ) identificacao de programa
0.0 03. ( OK ) identificacao de programa
0.0 04. ( OK ) identificacao de programa
0.0 05. ( OK ) identificacao de programa
0.0 06. ( OK ) identificacao de programa
*/
