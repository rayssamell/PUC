/*
Exercícios - v0.0. - 26 / 06 / 2024
Aluna: Rayssa Mell de Souza Silva
Matrícula: 860210
*/

// ----------------------------------------------- preparacao
// dependências
#include <iostream>
#include "myArray.hpp"
#include <cstdlib>
// ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos

/* Method_01 - Acrescentar caractere ao final */
void method_01(void) {
	//identificar
	cout << "Method_01" << endl;
	
	//definir dados
	int value = 0;
	int_Array *arranjo = new int_Array(5);
	
	//preencher arranjo
	arranjo->setArray(0,1);
	arranjo->setArray(1,2);
	arranjo->setArray(2,3);
	arranjo->setArray(3,4);
	arranjo->setArray(4,5);
	
	//ler dado
	cout << endl << "Digite um valor para acrescentar: ";
	cin >> value;
	//chama a funcap para colocar valor ao final
	arranjo->array_push_back(value);
	//mostra o arranjo
	cout << endl;
	arranjo->print();
	
	//liberar espaco
	//free(arranjo);
	//encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/* Method_02 - remover valor do final do arranjo */
void method_02(void) {
	//identificar
	cout << "Method_02" << endl;
	
	//definir dados
	int_Array *arranjo = new int_Array(5);
	
	//preencher arranjo
	arranjo->setArray(0,1);
	arranjo->setArray(1,2);
	arranjo->setArray(2,3);
	arranjo->setArray(3,4);
	arranjo->setArray(4,5);
	
	//chama a funcao para remover valor do final
	arranjo->array_pop_back();
	//mostra o arranjo apos remocao
	cout << endl;
	arranjo->print();
	
	//liberar espaco
	//free(arranjo);
	//encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/* Method_03 - Acrescentar caractere no inicio do arranjo */
void method_03(void) {
	//identificar
	cout << "Method_03" << endl;
	
	//definir dados
	int value = 0;
	int_Array *arranjo = new int_Array(5);
	
	//preencher arranjo
	arranjo->setArray(0,1);
	arranjo->setArray(1,2);
	arranjo->setArray(2,3);
	arranjo->setArray(3,4);
	arranjo->setArray(4,5);
	
	//ler dado
	cout << endl << "Digite um valor para acrescentar: ";
	cin >> value;
	//chama a funcap para colocar valor no inicio
	arranjo->array_push_front(value);
	//mostra o arranjo
	cout << endl;
	arranjo->print();
	
	//liberar espaco
	//free(arranjo);
	//encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

// ----------------------------------------------- acao principal
/*
Funcao principal.
@return codigo de encerramento
*/
int main ( int argc, char** argv )
{
// definir dado
	int x = 0; // definir variavel com valor inicial
// repetir até desejar parar
	do
	{
		// identificar
		cout << "EXEMPLO1600 - Programa - v0.0\n " << endl;
		// mostrar opcoes
		cout << "Opcoes " << endl;
		cout << "   0 - parar " << endl;
		cout << "   1         " << endl;
		cout << "   2         " << endl;
		cout << "   3         " << endl;
		cout << "   4         " << endl;
		cout << "   5         " << endl;
		cout << "   6         " << endl;
		cout << "   7         " << endl;
		cout << "   8         " << endl;
		cout << "   9         " << endl;
		cout << "  10         " << endl;
		cout << "  11         " << endl;
		cout << "  12         " << endl;
		// ler do teclado
		cout << endl << "Entrar com uma opcao: ";
		cin >> x;
		// escolher acao
		switch ( x )
		{
		case 1:
			method_01 ( );
			break;
		case 2:
			method_02 ( );
			break;
		case 3:
			method_03();
			break;
		default:
			cout << endl << "ERRO: Valor invalido." << endl;
		} // end switch
	}
	while ( x != 0 );
// encerrar
	pause ( "Apertar ENTER para terminar" );
	return ( 0 );
} // end main ( )
