/*
Exercícios - v0.0. - 20 / 06 / 2024
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
/**
  Method_00 - nao faz nada.
 */
void method_00 ( )
{
// nao faz nada
} // end method_00 ( )

/**
  Method_01 - Funcao para acrescentar valor ao final de um arranjo
 */
void method_01 ( )
{
	//definir dados
	int value = 0;
	//preencher arranjo
	int_Array *arranjo = new int_Array(5);
	
	arranjo->setArray ( 0, 1 );
	arranjo->setArray ( 1, 2 );
	arranjo->setArray ( 2, 3 );
	arranjo->setArray ( 3, 4 );
	arranjo->setArray ( 4, 5 );
	
	// Identificar
	cout << "\nMethod_01 - v0.0\n" << std::endl;
	
	cout << endl << "Digite um valor para inserir: ";
	cin >> value;
	
	arranjo->array_push_back(value); 
	arranjo->print();
	
//	free(arranjo);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_01 ( )

/**
  Method_02 - Funcao para remover valor ao final de um arranjo
 */
void method_02 ( )
{
	//preencher arranjo
	int_Array *arranjo = new int_Array(5);
	
	arranjo->setArray ( 0, 1 );
	arranjo->setArray ( 1, 2 );
	arranjo->setArray ( 2, 3 );
	arranjo->setArray ( 3, 4 );
	arranjo->setArray ( 4, 5 );
	
	// Identificar
	cout << "\nMethod_02 - v0.0\n" << std::endl;
	
	arranjo->array_pop_back(arranjo); 
	arranjo->print();
	
//	free(arranjo);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_02 ( )

/**
  Method_03 - Funcao para acrescentar valor no inicio de um arranjo
 */
void method_03 ( )
{
	//definir dados
	int value = 0;
	//preencher arranjo
	int_Array *arranjo = new int_Array(5);
	
	arranjo->setArray ( 0, 1 );
	arranjo->setArray ( 1, 2 );
	arranjo->setArray ( 2, 3 );
	arranjo->setArray ( 3, 4 );
	arranjo->setArray ( 4, 5 );
	
	// Identificar
	cout << "\nMethod_03 - v0.0\n" << std::endl;
	
	cout << endl << "Digite um valor para inserir: ";
	cin >> value;
	
	arranjo->array_push_front(value); 
	arranjo->print();
	
//	free(arranjo);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_03 ( )

/**
  Method_04 - Funcao para remover valor no inicio de um arranjo
 */
void method_04 ( )
{
	//preencher arranjo
	int_Array *arranjo = new int_Array(5);
	
	arranjo->setArray ( 0, 1 );
	arranjo->setArray ( 1, 2 );
	arranjo->setArray ( 2, 3 );
	arranjo->setArray ( 3, 4 );
	arranjo->setArray ( 4, 5 );
	
	// Identificar
	cout << "\nMethod_04 - v0.0\n" << std::endl;
	
	arranjo->array_pop_front(arranjo); 
	arranjo->print();
	
	//free(arranjo);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_04 ( )

/**
  Method_05 - Funcao para iniserir valor no meio de um arranjo
 */
void method_05 ( )
{
	//definir dados
	int value = 0;
	//preencher arranjo
	int_Array *arranjo = new int_Array(5);
	
	arranjo->setArray ( 0, 1 );
	arranjo->setArray ( 1, 2 );
	arranjo->setArray ( 2, 3 );
	arranjo->setArray ( 3, 4 );
	arranjo->setArray ( 4, 5 );
	// Identificar
	cout << "\nMethod_05 - v0.0\n" << std::endl;
	
	cout << endl << "Digite um valor para inserir: ";
	cin >> value;
	
	arranjo->array_push_mid(value); 
	arranjo->print();
	
	//free(arranjo);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_05 ( )

/**
  Method_06 - Funcao para remover valor do meio de um arranjo
 */
void method_06 ( )
{
	//preencher arranjo
	int_Array *arranjo = new int_Array(5);
	
	arranjo->setArray ( 0, 1 );
	arranjo->setArray ( 1, 2 );
	arranjo->setArray ( 2, 3 );
	arranjo->setArray ( 3, 4 );
	arranjo->setArray ( 4, 5 );
	
	// Identificar
	cout << "\nMethod_06 - v0.0\n" << std::endl;
	
	arranjo->array_pop_mid(arranjo); 
	arranjo->print();
	
	//free(arranjo);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
} // end method_06 ( )

/**
  Method_07 - Funcao para comparar arranjos de inteiros
 */
void method_07(void){
	//definir dados
	ref_int_Array p = new intArray;
	ref_int_Array q = new intArray;
	
	// Identificar
	cout << "\nMethod_07 - v0.0\n" << std::endl;
	
	//preencher arranjos
	p->length = 5;
	p->data = new int[p->length];
	for (int i = 0; i < p->length; i = i + 1) {
		p->data[i] = i + 1; 
	}
	
	q->length = 5;
	q->data = new int[q->length];
	for (int i = 0; i < q->length; i = i + 1) {
		q->data[i] = i + 1;
	}
	cout << "Arranjo p:" << endl;
	for (int i = 0; i < p->length; ++i) {
		cout << p->data[i] << " " << endl;
	}
	cout << endl;
	
	cout << "Arranjo q:" << endl;
	for (int i = 0; i < q->length; ++i) {
		cout << q->data[i] << " " << endl;
	}
	cout << endl;
	cout << "Comparando arranjos p e q:" << std::endl;
	int result = intArray_cmp(p, q);
	if (result == 0) {
		cout << "Os arranjos sao iguais." << std::endl;
	} else if (result < 0) {
		cout << "O arranjo p e' menor." << std::endl;
	} else {
		cout << "O arranjo p e' maior." << std::endl;
	}
	//liberar espaco
	//free(p);
//	free(q);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_07 ( )

/**
  Method_08 - Funcao para juntar arranjos de inteiros
 */
void method_08(void){
	//definir dados
	ref_int_Array p = new intArray;
	ref_int_Array q = new intArray;
	
	// Identificar
	cout << "\nMethod_08 - v0.0\n" << std::endl;
	
	// Preencher arranjos
	p->length = 5;
	p->data = new int[p->length];
	for (int i = 0; i < p->length; ++i) {
		p->data[i] = i + 1;
	}
	
	q->length = 5;
	q->data = new int[q->length];
	for (int i = 0; i < q->length; ++i) {
		q->data[i] = i * 2;
	}
	
	// Chamar intArray_cat para concatenar p e q
	ref_int_Array result = intArray_cat(p, q);
	
	// Verificar o resultado
	if (result == nullptr) {
		cout << "Tamanhos Incompatíveis." << endl;
	} else {
		cout << "Novo Arranjo:" << endl;
		for (int i = 0; i < result->length; ++i) {
			cout << *(result->data + i) << " " << endl;
		}
		cout << endl;;
	}
	//liberar espaco
//	free(p);
//	free(q);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}// end method_08 ( )

/**
  Method_09 - Funcao para procurar pela primeira ocorrencia de valor em arranjo
*/
void method_09(void){
	//definir dados
	ref_int_Array a = new intArray;
	int x = 0;
	// Identificar
	cout << "\nMethod_09 - v0.0\n" << std::endl;
	
	// Preencher arranjos
	a->length = 10;
	a->data = new int[a->length];
	for (int i = 0; i < a->length; ++i) {
		a->data[i] = i + 1;
	}
	
	cout << "Digite um valor para procurar: ";
	cin >> x; getchar();
	
	a = intArray_seek(a, x);
	if (a != nullptr) {
		cout << endl << "Elemento " << x << " encontrado no array." << endl;
	} else {
		cout << endl << "Elemento " << x << " nao encontrado no array." << endl;
	}
	//liberar espaco
//	free(a);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_09 ( )

/**
  Method_10 - Funcao para separar sequencia de valores em arranjo
 */
void method_10(void){
	//definir dados
	ref_int_Array a = new intArray;
	int start = 0, size = 0;
	// Identificar
	cout << "\nMethod_10 - v0.0\n" << std::endl;
	
	// Preencher arranjos
	a->length = 10;
	a->data = new int[a->length]{1,2,3,4,5,6,7,8,9,10};
	
	cout << "Digite a posicao inicial: ";
	cin >> start; getchar();
	
	cout << endl << "Digite o tamanho: ";
	cin >> size;
	
	a = intArray_sub(a, start, size);
	if (a && size <= a->length) {
		cout << "Subsequencia encontrada:" << endl;
		for (int i = 0; i < size; ++i) {
			cout << endl << a->data[i] << " ";
		}
		cout << endl;
	} else {
		cout << "Nao foi possivel encontrar a subsequencia." << endl;
	}
	//liberar espaco
//	free(a);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}//end method_10 ( )

/* ---- EXTRAS ---- */
/**
  Method_11 - Funcao para intercalar arranjos de inteiros
 */
void method_11(void){
	//definir dados
	ref_int_Array p = new intArray;
	ref_int_Array q = new intArray;
	
	// Identificar
	cout << "\nMethod_11 - v0.0\n" << std::endl;
	
	// Preencher arranjos
	p->length = 3;
	p->data = new int[p->length]{1,3,5};

	q->length = 5;
	q->data = new int[q->length]{2,4,6,8,10};
	
	// Chamar intArray_merge para intercalar p e q
	ref_int_Array r = intArray_merge(p, q);

	// Verificar o resultado
	if (r) {
		cout << "Novo Arranjo:" << endl;
		for (int i = 0; i < r->length; i++) {
			cout << r->data[i] << " " << endl;
		}
		cout << endl;;
	}
	//liberar espaco
//	free(p);
//	free(q);
//	free(r);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}// end method_11 ( )

/**
  Method_12 - Funcao para intercalar arranjos de inteiros em ordem crescente
 */
void method_12(void){
	//definir dados
	ref_int_Array p = new intArray;
	ref_int_Array q = new intArray;
	
	// Identificar
	cout << "\nMethod_12 - v0.0\n" << std::endl;
	
	// Preencher arranjos
	p->length = 3;
	p->data = new int[p->length]{1,5,3};
	
	q->length = 3;
	q->data = new int[q->length]{4,2,6};
	
	// Chamar intArray_merge para intercalar p e q
	ref_int_Array r = intArray_mergeUp(p, q);
	
	// Verificar o resultado
	if (r == nullptr) {
		cout << "Sem dados nos arranjos." << endl;
	} else {
		cout << "Arranjo em ordem crescente:" << endl;
		for (int i = 0; i < r->length; i++) {
			cout << getArray(r,i) << " " << endl;
		}
		cout << endl;;
	}
	//liberar espaco
//	free(p);
//	free(q);
//	free(r);
	// encerrar
	pause ( "Apertar ENTER para continuar" );
}// end method_12 ( )

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
			method_03();
			break;
		case 4:
			method_04();
			break;
		case 5:
			method_05();
			break;
		case 6:
			method_06();
			break;
		case 7:
			method_07();
			break;
		case 8:
			method_08();
			break;
		case 9:
			method_09();
			break;
		case 10:
			method_10();
			break;
		case 11:
			method_11();
			break;
		case 12:
			method_12();
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
