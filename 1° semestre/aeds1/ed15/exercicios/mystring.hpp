/*
MyString.hpp - v0.0. - 14/06/2024
Author: Rayssa Mell de Souza Silva - 860210
*/

// ----------------------------------------------- definicoes globais

#include "Erro.hpp"
#ifndef _MYSTRING_H_
#define _MYSTRING_H_

// dependencias
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <string.h>

// using declarations
using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::string;
using std::ofstream;
using std::ifstream;

// outras dependencias
void pause ( std::string text )
{
	string dummy;
	cin.clear ( );
	cout << endl << text;
	cin.ignore( );
	getline(cin, dummy);
	cout << endl << endl;
} // end pause ( )

// ---------------------------------------------- definicao de classe
/**
 * Classe para tratar documentacao, derivada da classe Erro.
 */

class MyString : public Erro {
	/**
	 * atributos privados.
	 */
private:
	
	/**
	 * definicoes publicas.
	 */
public:
	/**
	 * Destrutor.
	 */
	~MyString( )
	{ }
	
	/**
	 * Construtor padrao.
	 */
	MyString ( ){
		setErro ( 0 ); // nenhum erro, ainda
	}// end construtor
	

	/* Funcao para retornar o tamanho da string */
	int str_len(char *s){
		int length = 0;
		while(*(s+length)){ 
			length = length + 1;
		}
		
		return(length);	
	} 
	
	/* Funcao para copiar de uma string para outra */
	char* str_cpy(char *s1, char *s2){
		while(*s2){
			*s1 = *s2;
			s2++;
			s1++;
			
		}
		*s1 = '\0';
		return s1;
	}
	
	/* Funcao para concatenar strings */
	char* str_cat(char *s1, char *s2){
		int length1 = str_len(s1);
		int length2 = str_len(s2);
		
		char *str = (char*)malloc((length1+length2+1)*sizeof(char));
		
		str_cpy(str, s1);
		
		str_cpy(str + length1, s2);
		
		return(str);
		
	}
	
	/**
	  Funcao para acrescentar caractere ao final
	  de uma cadeia de caracteres, por meio de apontador.
	  @return apontador para a cadeia atualizada
	  @param s - apontador para cadeia de caracteres
	  @param c - caractere a ser inserido
	 */

	char *str_push_back(char *s, char c){
		//tamanho de s 
		int length = str_len(s);
		
		if(length > 0 && s){
			//anda com s ate o final e coloca o c
			*(s+length) = c;
			//acescenta o \0 no tamanho+1
			*(s+length+1) = '\0';
		}
		//retorna s
		return (s);
	}
	
	/**
	  Funcao para remover caractere do final
	  de uma cadeia de caracteres, por meio de apontador.
	  @return apontador para a cadeia atualizada
	  @param s - apontador para cadeia de caracteres
	 */
	char* str_pop_back(char *s){
		//chama a funcao para pegar a ultima posicao 
		int length = strlen(s)-1;
		if(length > 0 && s){
			// coloca no ultimo o \n
			*(s+length) = '\0';
		}
		return (s);
	}
	
	/**
	  Funcao para acrescentar caractere ao início
	  de uma cadeia de caracteres, por meio de apontador.
	  @return apontador para a cadeia atualizada
	  @param c - caractere a ser inserido
	  @param s - apontador para cadeia de caracteres
	 */
	char* str_push_front ( char c, char *s ){
		char *new_str = (char*)malloc(2 * sizeof(char));
		if(new_str && s){
			new_str[0] = c;
			new_str[1] = '\0';
		
			s = str_cat(new_str, s);
		}
		return (s);
	}
	
	/**
	  Funcao para remover caractere do início
	  de uma cadeia de caracteres, por meio de apontador.
	  @return apontador para a cadeia atualizada
	  @param s - apontador para cadeia de caracteres
	 */
	char* str_pop_front ( char *s ){
		char *str = s;
		//int length = str_len(s);
		while(str_len(str)){
			*str = *(s+1);
			str++;
		}
		return(s);
	}
	
	/**
	  Funcao para inserir caractere no meio (aproximadamente)
	  de uma cadeia de caracteres, por meio de apontador,
	  se houver pelo menos dois caracteres.
	  @return apontador para a cadeia atualizada
	  @param s - apontador para cadeia de caracteres
	  @param c - caractere a ser inserido
	 */
	char* str_push_mid ( char *s, char c ){
		int length = str_len(s);
		
		int meio =  length / 2;
		for(int i = length - 1; i >= meio; i = i - 1){
			*(s + i + 1) = *(s + i);
		}
		*(s+meio) = c;
		*(s+length+1) = '\0';
		
		return(s);
	}
	
	/**
	  Funcao para remover caractere do meio (aproximadamente)
	  de uma cadeia de caracteres, por meio de apontador.
	  Se houver ao menos dois caracteres, remover o primeiro.
	  @return apontador para a cadeia atualizada
	  @param s - apontador para cadeia de caracteres
	 */
	char* str_pop_mid ( char *s ){
		int length = str_len(s);
		
		if (length == 0) {
			setErro(1);
		}else{
			int meio =  length / 2; 
				for (int i = meio; i <= length; i = i + 1) {
					if (length % 2 == 0) {
						*(s+i-1) = *(s+i);
					}
					else{
						*(s+i) = *(s+i+1);
					}
				}
				*(s+length) = '\0';
		}
		return(s);
	}
	
	/**
	  Funcao para inserir caractere em certa posição válida
	  de uma cadeia de caracteres, por meio de apontador.
	  @return apontador para a cadeia atualizada
	  @param s - apontador para cadeia de caracteres
	  @param c - caractere a ser inserido
	  @param index - posicao onde inserir
	 */
	char* str_insert ( char *s, char c, int index ){
		int length = str_len(s);
		
		if(index < 0 || index > length){
			setErro(2);
		}else{
			for (int i = length; i >= index; i = i - 1) {
				*(s+i+1) = *(s+i);
			}
			*(s+index) = c;
			
			*(s+length+1) = '\0';
			}
		
		return (s);
	}
	
	/**
	  Funcao para remover caractere de certa posição válida
	  de uma cadeia de caracteres, por meio de apontador.
	  @return apontador para a cadeia atualizada
	  @param s - apontador para cadeia de caracteres
	  @param index - posicao de onde remover
	 */
	char* str_remove ( char *s, int index ){
		int length = str_len(s);
		
		if(index < 0 || index > length){
			setErro(2);
		}else{
			for (int i = index; i <= length; i = i + 1) {
				*(s+i) = *(s+i+1);
			}
			
			*(s+length) = '\0';
		}
		return (s);
	}
	
	/**
	  Funcao para procurar pela primeira ocorrencia de certo símbolo
	  em uma cadeia de caracteres, por meio de apontador.
	  @return apontador para a primeira ocorrência; NULL, caso contrario
	  @param s - apontador para cadeia de caracteres
	  @param c - caractere a ser procurado
	 */
	char* str_chr ( char *s, char c ){
		int length = str_len(s);
		
		if(length == 0){
			setErro(1);
			return NULL;
		}else{
			for (int i = 0; i < length; i = i + 1) {
				if (*(s + i) == c) {
					return (s + i); 
				}
			}
		}
		return NULL;
	}
	
	/**
	  Funcao para separar caracteres ate' a ocorrencia de delimitador
	  em uma cadeia de caracteres, por meio de apontador.
	  @return apontador para caracteres; NULL, caso contrario
	  @param s - apontador para cadeia de caracteres
	  @param delimiter - caractere a ser procurado
	 */
	char* str_tok ( char *s, char delimiter ){
		int length = str_len(s);
		
		if(length == 0){
			setErro(1);
			return NULL;
		}else{
			for (int i = 0; i < length;  i = i + 1) {
				if (*(s + i) == delimiter) {
					*(s+i) = '\0';
					return (s); 
				}
			}
		}
		return NULL;
	}
	
	/**
	  Funcao para procurar por certo prefixo
	  em cadeia de caracteres, por meio de apontador.
	  @return apontador para a primeira ocorrência; NULL, caso contrario
	  @param prefix - prefixo a ser procurado
	  @param s - apontador para cadeia de caracteres
	 */
	char* str_prefix ( char *prefix, char *s ){
		int p_length = str_len(prefix);
		int s_length = str_len(s);
		
		if (s_length < p_length) {
			setErro(3);
			return NULL;
		}
		
		for (int i = 0; i < p_length;  i = i + 1) {
			if (*(s + i) != *(prefix + i)) {
				return NULL;
				setErro(4);
			}
		}
		
		return s + p_length;
	}
	
	/**
	  Funcao para procurar por certo sufixo
	  em cadeia de caracteres, por meio de apontador.
	  @return apontador para a primeira ocorrência; NULL, caso contrario
	  @param s - apontador para cadeia de caracteres
	  @param sufix - sufixo a ser procurado
	 */
	char* str_suffix(char *suffix, char *s) {
		int len_s = str_len(s); 
		int len_suffix = str_len(suffix); 
		
		if (len_s < len_suffix) {
			setErro(3);
			return NULL;
		}else{
		    for (int i = 0; i < len_suffix; i = i + 1) {
				if (*(s + len_s - i) != *(suffix + len_suffix - i)) {
					return NULL;
					setErro(5);
				}
			}
		}
		return s + (len_s - len_suffix);
	}

	
};//end class()

using ref_MyString = MyString*;

#endif //end _MYSTRING_H_
