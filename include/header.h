/*!
 *  @file header.h
 *  @brief Corpo da Classe Conjuntura
 *
 *  Arquivo com a classe conjuntura
 */

#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stdlib.h>
#include "queuear.h"
#include "stackar.h"

/**
 * @brief Classe conjuntura
 *
 * Assinaturas das funções e definição da classe conjuntura
 */
class conjuntura
{
public:
	/**
	 * @brief Construtor da classe conjuntura
	 * Cria as conjuturas
	 */
	conjuntura();
	/**
	 * @brief Destrutor da classe conjuntura
	 * Destroi as conjuturas
	 */
	~conjuntura();
	/**
	 * @brief Colhe a precedencia dos operadores
     * @param op Operador string usado para verificação de precedência
	 * @return Um inteiro equivalente a sua precedencia
	 * Precedencia 	Operadores
	 *		1		   -(un)
	 *		2			ˆ
	 *		3			* / %
	 *		4			+ -
	 *		5			()
	 */
	int get_precedencia(std::string op)const;

a
	bool eh_operador(std::string op)const;
	/**
	 * @brief Verifica se é o valor é um operador antes da sequencia seguinte
     * @param op Operador char usado para verificação
	 * @return true ou false
	 */
	bool eh_operador_antes(char op)const;
	/**
	 * @brief Verifica se é o valor é um operador completamente
     * @param op Operador char usado para verificação
	 * @return true ou false
	 */
	bool eh_operador_completa(char op)const;
	/**
	 * @brief Verifica se é o valor é um dígito
     * @param op Operador char usado para verificação
	 * @return true ou false
	 */
	bool eh_digito(char op)const;

	/**
	 * @brief Avalia a expressão afim de realizar os cálculos e obter o resultado
	 * @return inteiro
	 */
	int avalPosFixa();
	/**
	 * @brief Converte a expressão infixa para expressão pósfixa
	 * @return void
	 */
	void Infx2Posfx();
	/**
	 * @brief Tokeniza o arquivo
     * @param aux Recebe um vetor char do arquivo via getline.
     * @param t Tamanho da string.
	 * @return True caso a expressão seja correta e False caso contrário
	 */
	bool token(const char * aux, int t);

	
private:
	QueueAr<std::string> *fila_infixa; //!< Expressão infixa
	QueueAr<std::string> *fila_posfixa; //!< Expressão pósfixa
	int resultado; //!< Resultado da expressão pósfixa
};

#include "header.inl"

#endif /* HEADER_H */