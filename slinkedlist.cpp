#include "slinkedlist.h"
#include "object.h"
#include "tdalist.h"
#include "SLLNode.h"
#include <stddef.h>
#include <iostream>
#include <cstdlib>

using namespace std;

SLinkedList::SLinkedList(){
	head=NULL;
}

SLinkedList::~SLinkedList(){
	if(head)
		delete head;
}

bool SLinkedList::insert(Object* data, int pos) {
    if(pos<0||pos>getSize)
    	return false;
    SLLNode* neo = new SLLNode(data);
    
    if(!head){
    	head=neo;
    }else{
    	if(pos==0){
    		neo->setNext(head);
    		head->setNext(neo->getNext());
    		head=neo;
    	}else{
    		if(pos>0&&pos<getSize){
    			SLLNode* tmp = head;

    			for(int i=1;i<pos;i++){
    				tmp=tmp->getNext();
    			}
    			neo->setNext(tmp->getNext());
    			tmp->setNext(neo);

    		}else{
    			SLLNode* tmp=head;

    			for(int i=1;i<pos;i++){
    				tmp=tmp->getNext();
    			}

    			tmp->setNext(neo);
    		}
    	}

    }
    getSize++;
    return true;
}

int SLinkedList::indexOf(Object* other)const{
	SLLNode* tmp = head;
	for(int i=0;i<getSize;i++){
		if(tmp->getData()->equals(other)){
				return i;
		}
		tmp=tmp->getNext();
	}
	return -1;
}

Object* SLinkedList::get(int index)const{
	if(index<0||index>=getSize)
		return NULL;
	SLLNode* tmp=head;
	for(int i=0;i<index;i++)
		tmp=tmp->getNext();
	return tmp->getData();
}


Object* SLinkedList::remove(int pos){
    // Si es una posición Inválida
    if (pos < 0 || pos >= getSize)
        return NULL; // Indicar fracaso en la operación
    SLLNode* tmp;
    Object* tmpData;
    if (pos == 0){ // Desea Borrar la Cabeza
        // Desenlazar
        tmpData = head->getData();
        tmp = head->getNext(); 
        head->setData(NULL);
        head->setNext(NULL);
        // Liberar Memoria
        delete head;
        // Actualizar head
        head = tmp;
    }else if (pos == getSize - 1){ // Desea Borrar el último
        // Recorrer hasta el final
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->getNext();
        tmpData = tmp->getNext()->getData();
        // Desenlazar
        SLLNode* toErase = tmp->getNext();   
        tmp->setNext(NULL);
        toErase->setData(NULL);
        
        // Liberar Memoria
        delete toErase; 
        
    }else { // Desea Borrar de enmedio
        // Recorrer hasta el nodo anterior al que se desea borrar
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->getNext();
        // Desenlazar
        tmpData = tmp->getNext()->getData();
        SLLNode* toErase = tmp->getNext();
        tmp->setNext(toErase->getNext());
       toErase->setNext(NULL);
        toErase->setData(NULL);
        // Liberar Memoria
        delete toErase;        
    }
    getSize--; // Disminuir Tamaño
    return tmpData; // Indicar Éxito
}

// Retorna el siguiente a la posición pos
// Implementado de la manera más sencilla, pues podría haberse usado
// DLLNode*
int SLinkedList::prev(int pos) const{
	return pos-1;
}
int SLinkedList::next(int pos) const {
    return pos + 1;
}
// Elimina todos los elementos de la lista, coloca getgetSize en cero, y la cabeza
// en NULL, o sea que hace un poco más que el destructor.

// Retorna el primer elemento de la lista, si es que hay alguno
Object* SLinkedList::first()const {
    if (head)
        return head->getData();
    return NULL;
}
// Retorna el último elemento de la lista, si es que hay alguno
Object* SLinkedList::last()const {
    if (!head)
        return NULL;
    SLLNode* tmp = head;
    for (int i=0; i < getSize-1; i++)
        tmp = tmp->getNext();
    return tmp->getData();
}
// Imprime cada uno de los elementos que hay en la lista, llamando al método
// print de cada nodo.
void SLinkedList::print()const {
    SLLNode* tmp = head;
    for (int i=0; i < getSize; i++){
        tmp->print();
        tmp = tmp->getNext();
    }
}
// Retorna si la lista está llena, como nunca es así, retorna false siempre.
bool SLinkedList::isFull()const {
    return false;
}
bool SLinkedList::isEmpty()const {
    if(!head){
    	return true;
    }else{
    	return false;
    }

}

void SLinkedList::clear(){
	if (head)
        delete head;
    head = NULL;
    getSize = 0;
}
