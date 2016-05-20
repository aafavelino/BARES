/*!
 *  @file stackar.h
 *  @brief Corpo da classe StackAr
 *
 *  Arquivo com o corpo da classe StackAr
 */

#ifndef _STACKAR_H 
#define _STACKAR_H

#include <iostream>       // std::cerr
#include <stdexcept>      // std::length_error
#include "AbsStack.h" // Inclui a interface abstrata da pilha.

/**
 * @brief Classe StackAr
 *
 * Implementação e assinatura das funções da classe QueueAr
 */
template <class Object>
class StackAr : public AbsStack<Object>{
public:
    /**
     * @brief Construtor StackAr
     * @param _size 
     *
     * Seta as Variáveis da classe e tem tamanho padrão 10
     */
	StackAr(const int &_size = 10);
    /**
     * @brief Destrutor da classe QueueAr
     * Destroi a Pilha
     */
	~StackAr();
    /**
     * @brief Insere elementos na pilha
     * @param x Recebe o elemento a ser adicionado
     * @return void
     */
	void push( const Object &x);
    /**
     * @brief Remove o elemento no topo da pilha
     * @return void
     */
	Object pop();
    /**
     * @brief Retorna o elemento no topo da pilha
     * @return Elemento no topo da pilha
     */
	Object top() const;
    /**
     * @brief Pega o  tamanho da capacidade da pilha
     * @return O tamanho da capacidade da pilha
     */
	Object getCapacidade() const;
    /**
     * @brief Verifica se a pilha está vazia { }
     * @return True se a pilha estiver vazia e False caso haja elementos
     */
	inline bool isEmpty()const
	{
		return topo == 0;
	}
    /**
     * @brief Apaga toda a pilha
     * @return void
     */
	inline void makeEmpty(){topo = 0;}
	void print()
	{
		for (int i = 0; i < topo; ++i)
		{
			std::cout << vetor[i] << " ";
		}
	}
private:
	Object *vetor; //!< Vetor no qual será usado como pilha
	int topo; //!< Topo da pilha
	int capacidade; //!< Capacidade da pilha

    /**
     * @brief Realoca o tamanho da pilha de acordo com a necessidade de alocação
     * @return void
     */    
	void resize(){
	 	capacidade = 2*capacidade +1;
         	Object *pt = new Object[capacidade];
         	for ( auto i(0); i< capacidade ; i++){
            		pt[i] = vetor[i];
         	}
         	delete [] vetor; 
         	vetor = pt;
	}

    /**
     * @brief Sobrecarga do operador << para a pilha
     * @param op std::ostream
     * @param objeto Objeto da classe QueueAr
     * @return std::ostream op
     */	
		inline friend
		std::ostream &operator <<(std::ostream &op,const StackAr &objeto){
			op<<"[ ";
			for(int i = 0;i < objeto.capacidade; i++)
				op << objeto.vetor[i]<< " ";
			op<<" ]"<<std::endl;
			return op;
		}

};
#include "stackar.inl"

#endif