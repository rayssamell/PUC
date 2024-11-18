/*
pilha.hpp - v0.0. - 28/06/2024
*/

// ----------------------------------------------- definicoes globais
#ifndef _PILHA_HPP_
#define _PILHA_HPP_

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

// classe para lidar com pilha
class intStack {
	
private:
	int length; //tamanho 
	int capacity; //capacidade maxima
	int *data; //dados
public:
	//construtor
	intStack (int n){
		// definir valores iniciais
		length = 0;
		data = nullptr;
		// reservar area
		if ( n > 0)
		{
			//tamanho fixo
			length = n;
			capacity = n + 3;
			// dados tem espaco para capacidade total
			data = new int [ capacity ];
		}
	} //end construtor ( )
	
	
	// metodo set para colocar valor em posicao
	void set(int position, int value){
		if (0 <= position && position < length) {
			data[position] = value;
		}
	} // end set ( )
	
	// metodo get para pegar a posicao de certo dado
	int get (int position){
		if (0 <= position && position < length) {
			return(data[position]);
		} else {
			return 0;
		}
	} // end get ( )
	
	//verificar se a pilha esta vazia
	bool isEmpty( ){
		return(this->length == 0);
	}
	
	//verificar se a pilha esta cheia
	bool isCheia( ){
		return(this->length == capacity);
	}
	
	
	//metodo para imprimir na tela o stack
	void print ( ) {
		cout << endl;
		for ( int x = 0; x < length; x=x+1 )
		{
			cout << setw( 3 ) << x << " : "
			<< setw( 9 ) << data[x]
			<< endl;
		} // end for
		cout << endl;
	} // end print ()
	
	/**
	  Funcao para acrescentar valor no topo de uma pilha (LIFO)
	  montada em um arranjo, por meio de apontador.
	  @return apontador para pilha atualizada
	  @param stack - apontador para pilha
	  @param value - valor a ser inserido
	 */
	void intStack_push ( int value ){
		// testa se a pilha esta cheia
		if(isCheia()){
			cout << "Erro: pilha cheia." << endl;	
		}
		//colocar o valor no topo da pilha
		data[length] = value;
		//aumenta o tamanho
		length ++;
		
	} //end intStack_push ( )
	
	/**
	  Funcao para remover valor do topo de uma pilha (LIFO)
	  montada em um arranjo, por meio de apontador.
	  @return apontador para pilha atualizada
	  @param stack - apontador para pilha
	 */
	int * intStack_pop() {
		if (isEmpty()) 
			cout << "Erro: pilha vazia." << endl;
		else 
			length--; 
		
		return (data);
	} // end intStack_pop ( )
	
	/**
	  Funcao para duplicar valor no topo de uma pilha (LIFO)
	  montada em um arranjo, por meio de apontador.
	  @return apontador para pilha atualizada
	  @param stack - apontador para pilha
	 */
	int * intStack_dup(){
		//verificar se a pilha esta cheia
		if(isCheia()){
			cout << "Pilha Cheia." << endl;
		} else{
			// coloca na ultima posicao o tamanho - 1
			data[length] = data[length-1];
			//aumenta tamanho
			length++;
		}
		return(data);
	} //end intStack_dup ( )
	
	/**
	  Funcao para trocar a ordem dos valores no topo de uma pilha (LIFO)
	  montada em um arranjo, por meio de apontador, se houver pelo menos dois valores.
	  @return apontador para pilha atualizada
	  @param stack - apontador para pilha
	 */
	int * intStack_swap ( ){
		if(isEmpty() || length <= 2){
			cout << "Pilha Vazia" << endl;
		}else{
			//guarda o valor do topo da pilha
			int temp = get(length - 1);
			// coloca o valor do segundo no topo
			set(length - 1, get(length - 2));  
			//coloca o valor guardado no temp (topo) no segundo
			set(length - 2, temp);
		}
		return(data);
	} //end intStack_swap ( )
	
	/**
	  Funcao para inverter a ordem dos valores em uma pilha (LIFO)
	  montada em um arranjo, por meio de apontador, se houver pelo menos dois valores.
	  @return apontador para pilha atualizada
	  @param stack - apontador para pilha
	 */
	int * intStack_invert ( ){
		if(isEmpty() || length < 2){
			cout << "Pilha Vazia" << endl;
		} else{
			for(int i = 0; i < length; i = i + 1){
				set(i, length-i);
			}
		}
		return (data);
	}// end intStack_invert
};
using ref_intStack = intStack*;

/* FILA */

typedef struct s_intQueue { 
	int length; 
	int *data;
	int capacity;
} intQueue;

typedef intQueue* ref_intQueue;

// alocacao de espaco
ref_intQueue new_intQueue ( int n )
{
	ref_intQueue tmp = (ref_intQueue)malloc(sizeof(intQueue));
	//verificar se a alaocacao deu certo
	if(tmp == nullptr){
		cout << "ERRO: falta espaco" << endl;
	} else {
		tmp->length = 0;
		tmp->data = nullptr;
		tmp->capacity = 10;
		if(n > 0){
			tmp->length = n;
			tmp->data = (int *)malloc(tmp->capacity*sizeof(int));
			//verificar se a alocacao foi bem sucedida
			if(tmp->data == nullptr){
				cout << "Falta espaco para os dados" << endl;
				free(tmp);
				return nullptr;
			}
		}
	}
	return(tmp);	
} 

// metodo set para colocar valor em posicao
void set(ref_intQueue fila, int position, int value){
	if (0 <= position && position < fila->length) {
		fila->data[position] = value;
	}
} // end set ( )

// metodo get para pegar a posicao de certo dado
int get (ref_intQueue fila, int position){
	if (0 <= position && position < fila->length) {
		return fila->data[position];
	} else {
		return 0;
	}
} // end get ( )

//verificar se a pilha esta vazia
int isEmpty(ref_intQueue fila){
	if(fila == nullptr)
		return 1; // true
	else
		return 0; // false
}

//metodo para imprimir na tela o stack
void print (ref_intQueue fila ) {
	cout << endl;
	for ( int x = 0; x < fila->length; x=x+1 )
	{
		cout << setw( 3 ) << x << " : "
		<< setw( 9 ) << fila->data[x]
		<< endl;
	} // end for
	cout << endl;
} // end print ()

//verificar se a fila esta cheia
int isCheia(ref_intQueue fila){
	//testar se o tamanho e' maior ou igual a capacidade maxima
	if(fila->length == fila->capacity )
		return 1; 
	else
		return 0; //false
}

/**
  Funcao para acrescentar valor no inicip de uma fila (FIFO)
  montada em um arranjo, por meio de apontador.
  @return apontador para fila atualizada
  @param queue - apontador para fila
  @param value - valor a ser inserido
 */
ref_intQueue intQueue_push ( ref_intQueue queue, int value ){
	if(queue->length >= queue->capacity){
		cout << "Fila cheia" << endl;
	}else{
		queue->length++;
		
		for (int i = queue->length - 1; i >= 0; --i) {
			set(queue, i + 1, get(queue, i));
		}
		
		set(queue, *queue->data-1, value);
	}
	
	return(queue);	
} //end intQueue_push ( )

/**
  Funcao para remover valor do início de uma fila (FIFO)
  montada em um arranjo, por meio de apontador.
  @return apontador para fila atualizada
  @param queue - apontador para fila
 */
ref_intQueue intQueue_pop ( ref_intQueue queue ){
	if(isEmpty(queue)){
		cout << "Fila vazia" << endl;
	} else{
		for (int i = 0; i < queue->length-1; ++i) {
			set(queue, i, get(queue, i+1));
		}
		queue->length--;
	}
	return (queue);
} //end intQueue_pop ( )

/**
  Funcao para comparar filas de inteiros
  por meio de apontadores.
  @return zero , se forem iguais;
  negativo, se o valor da diferenca for menor e estiver na primeira fila
  positivo , se o valor da diferenca for maior e estiver na primeira fila
  @param p - apontador para inicio da primeira fila
  @param q - apontador para inicio da segunda fila
 */
int intQueue_compare ( ref_intQueue p, ref_intQueue q ){
	// verificar se os arranjos sao validos
	if (isEmpty(p) || isEmpty(q)) {
		cout << "Filas vazias" << endl;
	}
	// Comparar comprimentos dos arranjos
	if (p->length != q->length) {
		return p->length - q->length; 
	} else {
		// Comparar elemento por elemento
		for (int i = 0; i < p->length; i = i + 1) {
			if (get(p, i) != get(q, i)) {
				return get(p, i) - get(q, i); 
			}
		}
	}
	return 0; // Filas sao iguais
} // end intQueue_compare ( )

/**
  Funcao para juntar filas de inteiros
  por meio de apontadores.
  @return fila resultante da fusão
  @param p - apontador para inicio da primeira fila
  @param q - apontador para inicio da segunda fila
 */
ref_intQueue intQueue_join ( ref_intQueue p, ref_intQueue q ){
	if (isEmpty(p) || isEmpty(q)) {
		return 0;
	} else{
		ref_intQueue r = new_intQueue(p->length+q->length);
		
		if(r && !isEmpty(r)){
			for (int i = 0; i < p->length; i = i + 1) {
				set(r, i, get(p, i));
			}
			
			for (int i = 0; i < q->length; i = i + 1) {
				set(r, p->length + i, get(q, i));
			}
		}
		return r;
	}
}

/**
  Funcao para procurar valor em uma fila (FIFO)
  montada em um arranjo, por meio de apontador.
  @return 1, se encontrar; 0, caso contrário
  @param queue - apontador para fila
  @param value - valor a ser procurado
 */
bool intQueue_search ( ref_intQueue queue, int value ){
	if(isEmpty(queue)){
		return 0;
	}
	for (int i = 0; i < queue->length; i++) {
		if (queue->data[i] == value) {
			return 1; // valor encontrado
		}
	}
	
	return 0; 
}

#endif // _PILHA_H_

