/*!
 *  @file stackar.inl
 *  @brief Implementação da classe StackAr
 *
 *  Arquivo com a construção das funções da classe StackAr
 */
 
#include <iostream>       
#include <stdexcept>      
#include "stackar.h"	 

template <class Object>
StackAr<Object>::StackAr(const int &_size) : topo(0), capacidade(_size)
{
	vetor = new Object[capacidade];
}

template <class Object>
StackAr<Object>::~StackAr()
{
	delete[] vetor;
}

template <class Object>
Object StackAr<Object>::pop(void){
	Object remover;
	if(isEmpty())
		throw std::length_error("Undeflow");
	else
		remover = vetor[--topo];

	return remover;
}

template <class Object>
void StackAr<Object>::push(const Object &_value)
{
	if (topo == capacidade) // Não há mais espaço
		resize();

	vetor[topo++] = _value;
}

template <class Object>
Object StackAr<Object>::top() const
{
	if(topo == 0)
		throw std::domain_error("Pilha vazia!");
	return vetor[topo-1];
}
template <class Object>
Object StackAr<Object>::getCapacidade() const
{
	return topo;
}




