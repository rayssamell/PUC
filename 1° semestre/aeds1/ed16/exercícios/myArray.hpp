/*
mySrray.hpp - v0.0. - 20/06/2024
*/

// ----------------------------------------------- definicoes globais
#ifndef _MYARRAY_HPP_
#define _MYARRAY_HPP_

// dependencias
#include <iostream>
using std::cin ; // para entrada
using std::cout; // para saida
using std::endl; // para mudar de linha
#include <iomanip>
using std::setw; // para definir espacamento
#include <string>
using std::string; // para cadeia de caracteres
#include <fstream>
using std::ofstream; // para gravar arquivo
using std::ifstream ; // para ler arquivo

void pause ( std::string text )
{
	string dummy;
	cin.clear ( );
	cout << endl << text;
	cin.ignore( );
	getline(cin, dummy);
	cout << endl << endl;
} // end pause ( )

class int_Array{
private:
	int *data;
	int length;
	int capacity;
	
public:
	/**
	 * Destrutor.
	 */
	~int_Array ( ) 
	{ }
	/**
	 * Construtor padrao.
	 */
	int_Array ( int n )
	{
		// definir valores iniciais
		length = 0;
		capacity = 10;
		data = nullptr;
		// reservar area
		if ( n > 0 && n <= capacity)
		{
			length = n;
			data = new int [ length ];
		}
	} // end constructor

	//metodo setArray para colocar valor em posicao
	void setArray ( int position, int value )
	{
		if ( 0 <= position && position < length )
		{
			*(data + position) = value;
		} // end if
	} // end setArray ( )
	
	//metodo getArray para pegar a posicao
	int getArray(int position) {
		if (0 <= position && position < length) {
			return *(data + position);  
		} else {
			return -1;  
		}
	} //end getArray ( )
	
	//metodo para mostrar arranjo
	void print ( ) {
		cout << endl;
		for ( int x = 0; x < length; x=x+1 )
		{
			cout << setw( 3 ) << x << " : "
			<< setw( 9 ) << *(data + x)
			<< endl;
		} // end for
		cout << endl;
	} // end print ()
	
	//funcao para pegar tamanho do arranjo
	const int getLength(){
		return ( length );
	} // end getLength ( )
	
	/**
	  Funcao para acrescentar valor ao final
	  de um arranjo, por meio de apontador.
	  @return apontador para arranjo atualizado
	  @param array - apontador para arranjo
	  @param value - valor a ser inserido
	 */
	int *array_push_back(int value){
		//se length existe e se ha dados no arranjo
		if(length && data){
			length++; //aumenta length
			//length menor que a capacidade total
			if(length < capacity){
				//coloca o valor na posicao length - 1
				setArray(length-1, value);
			}
			else{
				cout << "Tamanho maior que a capacidade permitida";
				//implementar tratamento de erro
			}
		}else{
			cout << "Tamanho ou Dados invalidos";	
		}
		//retorna os dados
		return (data);
	}
	
	/**
	  Funcao para remover valor do final
	  de um arranjo, por meio de apontador.
	  @return apontador para arranjo atualizado
	  @param array - apontador para arranjo
	 */
	
	int * array_pop_back(){
		//length maior que 0 e e' menor que capacity e data existe
		if(length > 0 && length <= capacity && data){
			length--;
		}else{
			cout << "Tamanho ou Dados invalidos";		
		}
		return (data);
	}
	
	/**
	  Funcao para acrescentar valor ao início
	  de um arranjo, por meio de apontador.
	  @return apontador para arranjo atualizado
	  @param array - apontador para arranjo
	  @param value - valor a ser inserido
	 */
	
	
	int* array_push_front ( int value){
		
		if(length > 0 && data != NULL){
		
			++length;
			
			for (int i = length - 1; i >= 0; --i) {
				setArray(i + 1, getArray(i));
			}
			
			setArray(*data-1, value);
		}
		return(data);	
	}
	
	/**
	  Funcao para remover valor do início
	  de um arranjo, por meio de apontador.
	  @return apontador para arranjo atualizado
	  @param array - apontador para arranjo
	 */
	int* array_pop_front ( int_Array *array ){
		
		if (data != nullptr && length > 0) {
			for (int i = 0; i < length-1; ++i) {
				setArray(i, getArray(i+1));
			}
			--length;
		}
		
		return(data);
	}
	
	/**
	  Funcao para acrescentar valor no meio (aproximadamente)
	  de um arranjo, por meio de apontador.
	  @return apontador para arranjo atualizado
	  @param array - apontador para arranjo
	  @param value - valor a ser inserido
	 */
	int* array_push_mid (int value ){
		
		if(length > 0 && data){
			int meio =  length / 2;
			length++;
			for (int i = length - 1; i >= meio; i = i - 1) {
				setArray(i + 1, getArray(i));
			}
			setArray(meio, value);
		}
		return (data);
	}
	
	/**
	  Funcao para remover valor do meio (aproximadamente)
	  de um arranjo, por meio de apontador.
	  @return apontador para arranjo atualizado
	  @param array - apontador para arranjo
	 */
	int* array_pop_mid ( int_Array *array ){
		int meio =  length / 2; 
		for (int i = meio; i < length; i = i + 1) {
			setArray(i, getArray(i+1));	
		}
		length--;
		
		return(data);
	}

	
};
using ref_intArray = int_Array*;

/* Struct */
typedef struct s_intArray { 
	int length; 
	int *data; 
	
} intArray;

typedef intArray* ref_int_Array;

void setArray(ref_int_Array array, int position, int value) {
	if (0 <= position && position < array->length) {
		array->data[position] = value;
	}
}

int getArray(ref_int_Array array, int position) {
	if (0 <= position && position < array->length) {
		return array->data[position];
	} else {
		return -1;
	}
}

/**
  Funcao para comparar arranjos de inteiros
  por meio de apontadores.
  @return zero , se forem iguais;
  negativo, se o valor da diferenca for menor e estiver no primeiro arranjo
  positivo , se o valor da diferenca for maior e estiver no primeiro arranjo
  @param p - apontador para inicio do primeiro arranjo
  @param q - apontador para inicio do segundo arranjo
 */
int intArray_cmp ( ref_int_Array p, ref_int_Array q ){
	// verificar se os arranjos sao validos
	if (p == nullptr || q == nullptr) {
		return 0;
	}else{
		// comparar os comprimentos dos arranjos
		if (p->length != q->length) {
			return p->length - q->length; 
		}
		else{
			// comparar elemento por elemento
			for (int i = 0; i < p->length; i = i + 1) {
				if (getArray(p,i) != getArray(q,i)) {
					return getArray(p,i) - getArray(p,i); 
				}
			}
		}
	}
	return 0; 
}

/**
  Funcao para juntar arranjos de inteiros
  por meio de apontadores.
  @return apontador para inicio do arranjo com a uniao
  @param p - apontador para inicio do primeiro arranjo
  @param q - apontador para inicio do segundo arranjo
 */
ref_int_Array intArray_cat ( ref_int_Array p, ref_int_Array q ){
	
	if (p == nullptr || q == nullptr) {
		return p;
	}else{
		ref_int_Array r = new intArray;
		r->length = p->length + q->length;
		r->data = new int[r->length];
		
		if(r != nullptr){
			for (int i = 0; i < p->length; i = i + 1) {
				setArray(r, i, getArray(p, i));
			}
				
			for (int i = 0; i < q->length; i = i + 1) {
				setArray(r, p->length + i, getArray(q, i));
			}
				
		}
		return r;
	}
}

/**
  Funcao para procurar pela primeira ocorrencia de valor em arranjo
  por meio de apontador.
  @return apontador para a primeira ocorrência; nullptr, caso contrario
  @param a - apontador para arranjo de inteiros
  @param x - valor ser procurado
 */
ref_int_Array intArray_seek ( ref_int_Array a, int x ){
	if (a && a->length > 0){
		for (int i = 0; i < a->length; i = i + 1) {
			if (getArray(a, i) == x) {
				setArray(a, *a->data, i);
				return a;
			}
		}
	}
	return nullptr; 
}

/**
  Funcao para separar sequencia de valores em arranjo
  por meio de apontador.
  @return apontador para inicio da sequencia de inteiros; nullptr, caso contrario
  @param a - apontador para arranjo de inteiros
  @param start - posicao inicial
  @param size - quantidade de dados
 */
ref_int_Array intArray_sub ( ref_int_Array a, int start, int size ){
	if (a == nullptr || start < 0 || size > a->length ) {
		return nullptr; 
	} else {
		for (int i = 0; i < size; i = i + 1) {
			setArray(a, i, getArray(a, start + i));
		}
		
		return a;
	}
}

/**
  Funcao para intercalar arranjos de inteiros
  por meio de apontadores.
  @return apontador para inicio do arranjo com a uniao
  @param p - apontador para inicio do primeiro arranjo
  @param q - apontador para inicio do segundo arranjo
 */
ref_int_Array intArray_merge ( ref_int_Array p, ref_int_Array q ){
	
	if (p == nullptr) {
		return p;
	}
	else if(q == nullptr){
		return q;
	}else{
		ref_int_Array r = new intArray;
		r->length = p->length + q->length;
		r->data = new int[r->length];
		
		for (int i = 0; i < p->length; ++i) {
			setArray(r, i, getArray(p, i));
		}
		
		// Copiar elementos de q para r
		for (int i = 0; i < q->length; ++i) {
			setArray(r, p->length + i, getArray(q, i));	
		}

		return r;
	}
}
	
/**
	Funcao para intercalar arranjos de inteiros em ordem crescente
	por meio de apontadores.
	@return apontador para inicio do arranjo com a uniao
	@param p - apontador para inicio do primeiro arranjo
	@param q - apontador para inicio do segundo arranjo
*/
ref_int_Array intArray_mergeUp ( ref_int_Array p, ref_int_Array q ){
	if (p == nullptr) {
		return p;
	}
	else if(q == nullptr){
		return q;
	}else{
		//chamar funcao para juntar os arranjos
		ref_int_Array r = intArray_merge(p, q);
		// ordenar array r em ordem crescente
		for (int i = 1; i < r->length; i = i+1) {
			int k = getArray(r, i);
			int j = i - 1;
			while (j >= 0 && getArray(r, j) > k) {
				setArray(r, j + 1, getArray(r, j));
				--j;
			}
			setArray(r, j + 1, k);
		}
		return r;	
	}
}

#endif // _MYARRAY_H_

