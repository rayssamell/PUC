/*
Exercicios 1200 - v0.0. - 23/05/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

// dependencias
#include <iostream> // std::cin, std::cout, std:endl
#include <limits> // std::numeric_limits
#include <string> // para cadeias de caracteres
// ----------------------------------------------- definicoes globais
void pause ( std::string text ) {
	std::string dummy;
	std::cin.clear ( );
	std::cout << std::endl << text;
	std::cin.ignore( );
	std::getline(std::cin, dummy);
	std::cout << std::endl << std::endl;
} // end pause ( )

// ----------------------------------------------- classes / pacotes
#include "mymatrix.hpp"
using namespace std;

/**
  Method_01 - Gerar valores em Intervalo
 */

void method_01 ( ) {
	//identificar
	cout << "Method_01 - Gerar valores para Matriz de intervalo." << endl;
	// definir dados
	int inferior = 0, superior = 0;
	//quantidade de valores a partir de linhas e colunas
	int m = 0, n = 0;
	// ler dados
	cout << endl << "Digite a quantidade de linhas: ";
	cin >> m;
	getchar();
	cout << endl << "Digite a quantidade de colunas: ";
	cin >> n;
	getchar();
	cout << endl << "Digite um valor de 1 a 100 para o intervalo inferior: ";
	cin >> inferior;
	getchar();
	cout << endl << "Digite um valor de 1 a 100 para o intervalo superior: ";
	cin >> superior;
	getchar();

	if ( m > 0 && n > 0 && inferior >= 1 && superior <= 100 && inferior < superior) {
		Matrix <int> int_matrix ( m, n, 0 );
		// Gerar valores aleatorios dentro do intervalo
		int_matrix.randomIntGenerate(inferior, superior);

		// Mostrar os dados da matriz
		cout << endl << "Matriz gerada:" << endl;
		int_matrix.print();
		int_matrix.fprint("DADOS.TXT");
	} else {
		cout << "Entrada inválida." << endl;
	}
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02.
 */
void method_02 ( ) {
	// identificar
	cout << endl << "Method_02 - Escalar uma matriz e multiplicar por constante." << endl;
	// definir dados
	Matrix<int> matrix1 (3, 3, 0);
	matrix1.fread("DADOS.TXT");
	int constante = 0;
	// ler dados
	cout << endl << "Digite um valor: ";
	cin >> constante;
	getchar();
	//chamar funcao e criar nova matriz
	Matrix<int> matrix2 = matrix1.scalar(constante);
// mostrar dados
	cout << endl << "Matriz Original:" << endl;
	matrix1.print ( );
	cout << endl << "Nova Matriz: " << endl;
	matrix2.print();
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03.
 */
void method_03 ( ) {
	// identificar
	cout << endl << "Method_03 - Matriz Identidade." << endl;
	// definir dados
	Matrix <int> matrix ( 3, 3, 0 );
	// ler dados
	matrix.fread("DADOS1.TXT");
	bool teste = matrix.identidade();
	if (teste) {
		cout << endl << "A Matriz e' identidade" << endl;
	} else {
		cout << endl << "A Matriz nao e' identidade" << endl;
	}
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04.
 */
void method_04 (void) {
	//identificar
	cout << endl << "Method_04 - Igualdade de Matrizes" << endl;
	// definir dados
	Matrix <int> matrix1 ( 3, 3, 0 );
	Matrix <int> matrix2 ( 3, 3, 0);
	// ler dados
	matrix1.fread ( "DADOS1.TXT" );
	matrix2.fread ( "DADOS2.TXT" );
	bool teste = (matrix1 == matrix2);
	if (teste) {
		cout << endl << "As matrizes sao iguais." << endl;
	} else {
		cout << endl << "As matrizes sao diferentes." << endl;
	}
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05.
 */
void method_05 ( ) {
	// identificar
	cout << endl << "Method_05 - Soma de Matrizes." << endl;
	// definir dados
	Matrix <int> matrix1 ( 3, 3, 0 );
	Matrix <int> matrix2 ( 3, 3, 0 );
	// ler dados de arquivos
	matrix1.fread ( "DADOS.TXT" );
	matrix2.fread ( "DADOS1.TXT");
	//nova matriz soma
	Matrix <int> soma = matrix1.add(matrix2);
	// mostrar resultado
	matrix1.print();
	matrix2.print();
	cout << endl << "Resultado da soma = " << endl;
	soma.print ( );
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Method_06.
 */
void method_06 ( ) {
// identificar
	cout << endl << "Method_06 - v0.0" << endl;
	// definir dados
	Matrix <int> matrix1 ( 3, 3, 0 );
	// ler dados
	matrix1.fread ( "DADOS.TXT" );
	// mostrar dados
	cout << "\nMatrix_1\n";
	matrix1.print ( );
	//chamar funcao
	matrix1.addRows(0, 1, (-1));
	//mostrar dados
	cout << "\nMatrix_1 apos operacao: \n";
	matrix1.print ( );
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07.
 */
void method_07 ( ) {
	// identificar
	cout << endl << "Method_07 - v0.0" << endl;
	// definir dados
	Matrix <int> matrix1 ( 3, 3, 0 );
	// ler dados
	matrix1.fread ( "DADOS.TXT" );
	// mostrar dados
	cout << "\nMatrix_1\n";
	matrix1.print ( );
	//chamar funcao
	matrix1.subtractRows(0, 1, (2));
	//mostrar dados
	cout << "\nMatrix_1 - apos operacao:\n";
	matrix1.print ( );
// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
  Method_08.
 */
void method_08 ( ) {
	// identificar
	cout << endl << "Method_08 - Buscar valor em linha." << endl;
	// definir dados
	Matrix <int> matrix1 ( 3, 3, 0 );
	int procurado = 0;
	// ler dados
	cout << endl << "Digite um valor para procurar: ";
	cin >> procurado;
	getchar();
	//ler arquivo
	matrix1.fread ( "DADOS.TXT" );
	//chamar funcao para buscar valor
	int teste = matrix1.searchRows(procurado);
	if (teste != -1) {
		cout << "\nO valor " << procurado << " foi encontrado na linha " << teste << endl;
	} else {
		cout << "\nO valor " << procurado << " nao foi encontrado na matriz." << endl;
	}
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
  Method_09.
 */
void method_09 ( ) {
	// identificar
	cout << endl << "Method_09 - Buscar valor em coluna." << endl;
	// definir dados
	Matrix <int> matrix1 ( 3, 3, 0 );
	int procurado = 0;
	// ler dados
	cout << endl << "Digite um valor para procurar: ";
	cin >> procurado;
	getchar();
	//ler arquivo
	matrix1.fread ( "DADOS.TXT" );
	//chamar funcao para buscar valor
	int teste = matrix1.searchColumns(procurado);

	if (teste != -1) {
		cout << "\nO valor " << procurado << " foi encontrado na coluna " << teste << endl;
	} else {
		cout << "\nO valor " << procurado << " nao foi encontrado na matriz." << endl;
	}
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
  Method_10.
 */
void method_10 ( ) {
	// identificar
	cout << endl << "Method_10 - Matriz Transposta." << endl;
	// definir dado
	Matrix <int> matrix1 ( 3, 3, 0 );
	//ler arquivo
	matrix1.fread ( "DADOS.TXT" );
	//mostrar matriz original
	cout << endl << "Matriz Original: " << endl;
	matrix1.print();
	//chamar funcao para matriz transposta
	Matrix<int> matrizTransposta = matrix1.transpose();
	//mostrar matriz transposta
	cout << endl << "Matriz Transposta: " << endl;
	matrizTransposta.print();
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

/// EXTRAS

/**
 Method_11.
 */
void method_11(void) {
	// identificar
	cout << endl << "Method_11 - 12E1" << endl;
	// definir dado
	Matrix <int> matrix1 ( 3, 3, 0 );
	//ler arquivo
	matrix1.fread ( "DADOS.TXT" );
	//chamar funcao para vereficar caracteristica
	bool teste = matrix1.testarMatrix();
	if(teste){
		cout << endl << "A matriz apresenta a caracteristica. " << endl;
	}else{
		cout << endl << "A matriz nao apresenta a caracteristica. " << endl;
	}
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}

/**
 Method_12.
*/
void method_12(void) {
	// identificar
	cout << endl << "Method_12 - 12E2 " << endl;
	// definir dado
	Matrix <int> matrix ( 2, 2, 0 );
	matrix.novaMatrix();
	matrix.print();
	cout << endl;
	Matrix <int> matrix2 ( 3, 3, 0);
	matrix2.novaMatrix();
	matrix2.print();
	cout << endl;
	Matrix <int> matrix3 ( 4, 4, 0);
	matrix3.novaMatrix();
	matrix3.print();
	cout << endl;
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}

// ----------------------------------------------- acao principal


int main ( int argc, char** argv ) {
// definir dado
	int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
	do {
		// identificar
		cout << "EXERCICIOS 1200 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << " 0 - parar " << endl;
		cout << " Method_01 " << endl;
		cout << " Method_02 " << endl;
		cout << " Method_03 " << endl;
		cout << " Method_04 " << endl;
		cout << " Method_05 " << endl;
		cout << " Method_06 " << endl;
		cout << " Method_07 " << endl;
		cout << " Method_08 " << endl;
		cout << " Method_09 " << endl;
		cout << " Method_10 " << endl;
		cout << " Method_11 " << endl;
		cout << " Method_12 " << endl;

		// ler do teclado
		cout << endl << "Entrar com uma opcao: ";
		cin >> x;
		// escolher acao
		switch ( x ) {
			case  1:
				method_01 ( );
				break;
			case  2:
				method_02 ( );
				break;
			case  3:
				method_03 ( );
				break;
			case  4:
				method_04 ( );
				break;
			case  5:
				method_05 ( );
				break;
			case  6:
				method_06 ( );
				break;
			case  7:
				method_07 ( );
				break;
			case  8:
				method_08 ( );
				break;
			case  9:
				method_09 ( );
				break;
			case 10:
				method_10 ( );
				break;
			case 11:
				method_11 ( );
				break;
			case 12:
				method_12 ( );
				break;
			default:
				cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	} while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )
