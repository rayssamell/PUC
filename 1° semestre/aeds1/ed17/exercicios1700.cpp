/*
Exercícios - v0.0. - 28 / 06 / 2024
Aluna: Rayssa Mell de Souza Silva
Matrícula: 860210
*/

// ----------------------------------------------- preparacao
// dependências
#include <iostream>
#include "pilha.hpp"
#include <cstdlib>
// ----------------------------------------------- definicoes globais
using namespace std;
// ----------------------------------------------- metodos
/**
  Method_00 - nao faz nada.
 */
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )

/**
  Method_01 - Funcao para acrescentar valor no topo de uma pilha
 */
void method_01 ( )
{
	// Identificar
	cout << "\nMethod_01 - v0.0\n" << std::endl;
	
	//definir dados
	int value = 0;
	
	//definir tamanho
	ref_intStack stack = new intStack(5);
	
	//preencher stack
	stack->set(0, 1);
	stack->set(1, 2);
	stack->set(2, 3);
	stack->set(3, 4);
	stack->set(4, 5);
	
	//ler dado
	cout << endl << "Digite um valor para inserir: ";
	cin >> value;
	
	stack->intStack_push(value); 
	stack->print();
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02 - Funcao para remover valor no topo de uma pilha
 */
void method_02 ( )
{
	// Identificar
	cout << "\nMethod_02 - v0.0\n" << std::endl;
	
	//definir tamanho
	ref_intStack stack = new intStack(5);
	
	//preencher stack
	stack->set(0, 1);
	stack->set(1, 2);
	stack->set(2, 3);
	stack->set(3, 4);
	stack->set(4, 5);
	
	//chamar funcao para remover topo da pilha
	stack->intStack_pop();
	stack->print();
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03 - Funcao para duplicar valor no topo de uma pilha
 */
void method_03 ( )
{
	// Identificar
	cout << "\nMethod_03 - v0.0\n" << std::endl;
	
	//definir tamanho
	ref_intStack stack = new intStack(5);
	
	//preencher stack
	stack->set(0, 1);
	stack->set(1, 2);
	stack->set(2, 3);
	stack->set(3, 4);
	stack->set(4, 5);
	
	//chamar funcao para duplicar topo da pilha
	stack->intStack_dup();
	stack->print();
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04 - Funcao para trocar a ordem dos valores no topo de uma pilha
 */
void method_04 ( )
{
	// Identificar
	cout << "\nMethod_04 - v0.0\n" << std::endl;
	
	//definir tamanho
	ref_intStack stack = new intStack(5);
	
	//preencher stack
	stack->set(0, 1);
	stack->set(1, 2);
	stack->set(2, 3);
	stack->set(3, 4);
	stack->set(4, 5);
	
	//chamar funcao para trocar topo
	stack->intStack_swap();
	stack->print();
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05 - Funcao para inverter a ordem dos valores em uma pilha (LIFO)
 */
void method_05 ( )
{
	// Identificar
	cout << "\nMethod_05 - v0.0\n" << std::endl;
	
	//definir tamanho
	ref_intStack stack = new intStack(5);
	
	//preencher stack
	stack->set(0, 1);
	stack->set(1, 2);
	stack->set(2, 3);
	stack->set(3, 4);
	stack->set(4, 5);
	
	//chamar funcao para trocar topo
	stack->intStack_invert();
	stack->print();
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/* FILA */

/**
  Method_06 - Funcao para acrescentar valor no topo de uma fila
 */
void method_06 ( )
{
	// Identificar
	cout << "\nMethod_06 - v0.0\n" << endl;
	
	//definir dados
	int value = 0;
	
	//definir tamanho
	ref_intQueue fila = new_intQueue(5);
	
	//preencher stack
	set(fila, 0, 1);
	set(fila, 1, 2);
	set(fila, 2, 3);
	set(fila, 3, 4);
	set(fila, 4, 5);
	
	//ler dado
	cout << endl << "Digite um valor para inserir: ";
	cin >> value;
	
	fila = intQueue_push(fila, value); 
	print(fila);
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07 - Funcao para remover valor do início de uma fila (FIFO)
 */
void method_07 ( )
{
	// Identificar
	cout << "\nMethod_07 - v0.0\n" << endl;
	
	//definir tamanho
	ref_intQueue fila = new_intQueue(5);
	
	//preencher stack
	set(fila, 0, 1);
	set(fila, 1, 2);
	set(fila, 2, 3);
	set(fila, 3, 4);
	set(fila, 4, 5);
	
	fila = intQueue_pop(fila); 
	print(fila);
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_07 ( )

/**
  Method_08 - Funcao para comparar filas de inteiros
 */
void method_08 ( )
{
	// Identificar
	cout << "\nMethod_08 - v0.0\n" << endl;
	
	//definir tamanho
	ref_intQueue p = new_intQueue(5);
	ref_intQueue q = new_intQueue(5);
	
	//preencher fila p 
	set(p, 0, 1);
	set(p, 1, 2);
	set(p, 2, 3);
	set(p, 3, 4);
	set(p, 4, 5);
	
	//preencher fila q 
	set(q, 0, 2);
	set(q, 1, 4);
	set(q, 2, 6);
	set(q, 3, 8);
	set(q, 4, 10);
	
	int compare = intQueue_compare(p, q); 
	cout << endl << "Resultado =  " << compare << endl;
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_08 ( )

/**
  Method_09 - Funcao para juntar filas de inteiros
 */
void method_09 ( )
{
	// Identificar
	cout << "\nMethod_09 - v0.0\n" << endl;
	
	//definir tamanho
	ref_intQueue p = new_intQueue(5);
	ref_intQueue q = new_intQueue(5);
	
	//preencher fila p 
	set(p, 0, 1);
	set(p, 1, 2);
	set(p, 2, 3);
	set(p, 3, 4);
	set(p, 4, 5);
	
	//preencher fila q 
	set(q, 0, 4);
	set(q, 1, 6);
	set(q, 2, 8);
	set(q, 3, 10);
	set(q, 4, 12);
	
	ref_intQueue r = intQueue_join(p, q); 
	print(r);
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_09 ( )

/**
  Method_10 - Funcao para procurar valor em fila
 */
void method_10 ( )
{
	// Identificar
	cout << "\nMethod_10 - v0.0\n" << endl;
	
	//definir tamanho
	ref_intQueue p = new_intQueue(5);
	int value = 0;
	
	//preencher fila p 
	set(p, 0, 1);
	set(p, 1, 2);
	set(p, 2, 3);
	set(p, 3, 4);
	set(p, 4, 5);
	
	//ler dado
	cout << endl << "Digite um valor para inserir: ";
	cin >> value;
	
	bool r = intQueue_search(p, value); 
	
	if(r){
		cout << "Valor Encontrado." << endl;
	}else{
		cout << "Valor nao Encontrado." << endl;
	}
	
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_10 ( )

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
		case 0:
			method_00 ( );
			break;
		case 1:
			method_01 ( );
			break;
		case 2:
			method_02 ( );
			break;
		case 3:
			method_03 ( );
			break;
		case 4:
			method_04 ( );
			break;
		case 5:
			method_05 ( );
			break;
		case 6:
			method_06 ( );
			break;
		case 7:
			method_07 ( );
			break;
		case 8:
			method_08 ( );
			break;
		case 9:
			method_09 ( );
			break;
		case 10:
			method_10 ( );
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
