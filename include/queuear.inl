/*!
 *  @file queuear.inl
 *  @brief Implementação da classe QueueAr
 *
 *  Arquivo com a construção das funções da classe QueueAr
 */

    
#include "queuear.h"

template <class Object>
	QueueAr<Object>::QueueAr(const int _size):guarda(-1), retaguarda(-1), capacidade(_size){
		vetor = new Object[capacidade];
	}

template <class Object>
	QueueAr<Object>::~QueueAr(){
			delete [] vetor;
	}

template <class Object>
	void QueueAr<Object>::enqueue(const Object &_value){
        if((retaguarda + 1)%capacidade == guarda)
        {
            resize();
        }
        if(guarda == -1)
        {
            guarda = 0;
        }
        retaguarda = (retaguarda + 1)%capacidade;
        vetor[retaguarda] = _value;
	} 

template <class Object>
	Object QueueAr<Object>::dequeue( ){
		Object aux = vetor[guarda];
		if (guarda == retaguarda)
		{
			guarda = retaguarda = -1;
		}
		else
		{
		guarda = (guarda+1)%capacidade;
		}
		return  aux;
	}

template <class Object>
	Object QueueAr<Object>::getFront( ) const{
		return vetor[guarda];
	}

template <class Object>
	Object QueueAr<Object>::getBack( ) const{
		return vetor[retaguarda];
	}

template <class Object>
	bool QueueAr<Object>::isEmpty( ) const{
		return guarda == -1;
	}


template <class Object>
	void QueueAr<Object>::makeEmpty( ){
		guarda = retaguarda = -1;
	}




