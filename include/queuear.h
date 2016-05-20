/*!
 *  @file queuear.h
 *  @brief Corpo da classe QueueAr
 *
 *  Arquivo com o corpo da classe QueueAr
 */

#ifndef _QUEUEAR_H 
#define _QUEUEAR_H 
#include <iostream>
#include "AbsQueue.h"
	using namespace std;

/**
 * @brief Classe QueueAr
 *
 * Implementação e assinatura das funções da classe QueueAr
 */
template <class Object>
class QueueAr : public AbsQueue<Object>
{
public:
    /**
     * @brief Construtor QueueAr
     * @param _size 
     *
     * Seta as Variáveis da classe e tem tamanho padrão 10
     */
	QueueAr(const int _size = 10);
    /**
     * @brief Destrutor da classe QueueAr
     * Destroi a fila
     */
	~QueueAr();
    /**
     * @brief Insere elementos na fila
     * @param x Recebe o elemento a ser adicionado
     * @return void
     */
	void enqueue( const Object & x ); 
    /**
     * @brief Remove elementos da fila
     * @param x Elemento a ser removido
     * @return void
     */
	Object dequeue( );
    /**
     * @brief Pega o elemento que está na guarda da fila
     * @return Elemento da frente
     */
	Object getFront( ) const;
    /**
     * @brief Pega o elemento que está na retaguarda da fila
     * @return Elemento de trás
     */
    Object getBack( ) const;
    /**
     * @brief Verifica se a fila está vazia { }
     * @return True se a fila estiver vazia ou False se a fila não estiver vazia
     */
	bool isEmpty( ) const; 
    /**
     * @brief Limpa toda a fila
     * @return void
     */    
	void makeEmpty( );

private:
	Object *vetor; //!< Vetor no qual será usado como fila
	int guarda; //!< Guarda do vetor, ou seja, a frente
	int retaguarda; //!< Retaguarda do vetor, ou seja, o último elemento
	int capacidade; //!< Tamanho da fila 
    /**
     * @brief Realoca o tamanho da fila de acordo com a necessidade de alocação
     * @return void
     */    
	void resize(){
    	Object *NewVetor = new Object[2 * capacidade];
    	auto x(0);
    	int slave_guarda = guarda;
        while(slave_guarda != capacidade and retaguarda + 1 != slave_guarda){
        	NewVetor[x] = vetor[slave_guarda];
        	x++;
        	slave_guarda++;
        }
        if (retaguarda < guarda){
            auto y(0);
            for (;y <= retaguarda; y++)
                NewVetor[ x + y ] = vetor[ y ];
            x = x + y;
        }
        guarda = 0;
        retaguarda = x - 1;
    	delete 	[] vetor;
    	vetor = NewVetor;
    	capacidade = 2 * capacidade;
	}

    /**
     * @brief Sobrecarga do operador << para a fila
     * @param op std::ostream
     * @param obj Objeto da classe QueueAr
     * @return std::ostream op
     */
        inline friend
		std::ostream &operator <<(std::ostream &op,const QueueAr &obj){
			for(int i=0;i<obj.capacidade;i++)
				op<<obj.vetor[(obj.guarda+i)%obj.capacidade];

			return op;
		}
	
};

#include "queuear.inl"
#endif