#include "object.h"
#include "tdalist.h"
#include "dllnode.h"
#include "linkedlist.h"
// Para tener la definici�n del NULL sin declarar m�s identificadores
// innecesarios
#include <stddef.h>
#include <iostream>
using namespace std;
// Constructor por defecto de LinkedList
LinkedList::LinkedList(){
    head = NULL;
}
// Super Destructor de LinkedList, n�tese que llamar� al destructor
// de la clase DLLNode, que liberar� todos los nodos siguientes...
LinkedList::~LinkedList(){
    if (head)
        delete head;
}
/* 
* Inserci�n en la lista
* En esta operaci�n se consideran cuatro casos generales de inserci�n:
* (A) La Lista est� Vac�a
* (B) Se desea Insertar antes de head (pos = 0)
* (C) Se desea Insertar en Medio de la Lista
* (D) Se desea Insertar al Final (pos = getSize)
*/
bool LinkedList::insert(Object* data, int pos) {
    // Si se desa meter en una posici�n inv�lida
    if (pos < 0 || pos > getSize)
        return false; // Fracaso en esta Operaci�n
    
    // Creaci�n del Nodo que insertaremos en la lista
    DLLNode* neo = new DLLNode(data);
    
    if (!head) // La lista est� vac�a
        head = neo;
    else { // La Lista tiene elementos
        if (pos == 0){ // Desea insertar al principio de la lista
            // Enlace de neo a la lista
            head->setPrev(neo);
            neo->setNext(head);
            // Actualizar la cabeza
            head = neo;
        }else if (pos > 0 && pos < getSize){ // Desea Insertar en medio
            DLLNode* tmp = head;
            // Recorrer hasta la posici�n anterior a la que deseamos insertar
            for (int i=1; i<pos; i++)
               tmp = tmp->getNext();
            // Enlazar el Nodo neo
            neo->setPrev(tmp);
            neo->setNext(tmp->getNext());
            tmp->getNext()->setPrev(neo);
            tmp->setNext(neo);
        }else { // Desea insertar al final
            DLLNode* tmp = head;
            // Recorrer la Lista hasta el final
            for (int i=1; i<pos; i++)
               tmp = tmp->getNext();
            // Enlazar el Nodo neo
            tmp->setNext(neo);
            neo->setPrev(tmp);        
        }    
    }
    // Incremento del tama�o
    getSize++;
    // �xito en la operaci�n
    return true;
}
/*
* B�squeda del �ndice (posici�n) de un objeto
* Para que esta operaci�n tenga �xito es necesario que los objetos que sean
* insertados en la lista tengan bien definido el m�todo equals, pues es este
* m�todo el que determinar� la igualdad de un objeto con otro.
*/
int LinkedList::indexOf(Object* other)const {
    DLLNode* tmp = head;
    for (int i=0; i < getSize; i++){
        // Compara cada uno de los elementos con el par�metro
        if (tmp->getData()->equals(other))
                return i;
        tmp = tmp->getNext();
    }    
    // En el caso de no encontrarlo
    return -1;
}
// Consigue el elemento index de la lista, si index es una posici�n v�lida
Object* LinkedList::get(int index)const {
    if (index < 0 || index >= getSize)
        return NULL;
    DLLNode* tmp = head;
    for (int i=0; i < index; i++)
        tmp = tmp->getNext();
    return tmp->getData();
}
/*
* Borra un elemento de la lista, dada la posici�n del mismo. Se consideran
* tres casos:
* (A) El Elemento es la Cabeza
* (B) El Elemento es el �ltimo
* (C) El Elemento est� en Medio
* Es importante recalcar que para borrar un elemento es necesario primero
* desenlazarlo de la lista y luego liberar su memoria, pues en caso contrario
* liberar�amos todos los elementos siguiente a este elemento.
*/
Object* LinkedList::remove(int pos) {
    // Si es una posici�n Inv�lida
    if (pos < 0 || pos >= getSize)
        return NULL; // Indicar fracaso en la operaci�n
    DLLNode* tmp;
    Object* tmpData;
    if (pos == 0){ // Desea Borrar la Cabeza
        // Desenlazar
        tmpData = head->getData();
        tmp = head->getNext(); 
        head->setData(NULL);
        tmp->setPrev(NULL);
        head->setNext(NULL);
        // Liberar Memoria
        delete head;
        // Actualizar head
        head = tmp;
    }else if (pos == getSize - 1){ // Desea Borrar el �ltimo
        // Recorrer hasta el final
        tmp = head;
        for (int i=1; i<pos; i++)
           tmp = tmp->getNext();
        tmpData = tmp->getNext()->getData();
        // Desenlazar
        DLLNode* toErase = tmp->getNext();   
        tmp->setNext(NULL);
        toErase->setPrev(NULL);
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
        DLLNode* toErase = tmp->getNext();
        tmp->setNext(toErase->getNext());
        toErase->getNext()->setPrev(tmp);
        toErase->setNext(NULL);
        toErase->setPrev(NULL);
        toErase->setData(NULL);
        // Liberar Memoria
        delete toErase;        
    }
    getSize--; // Disminuir Tama�o
    return tmpData; // Indicar �xito
}
// Retorna el anterior a la posici�n pos
// Implementado de la manera m�s sencilla, pues podr�a haberse usado
// DLLNode*
int LinkedList::prev(int pos) const {
    return pos - 1;
}
// Retorna el siguiente a la posici�n pos
// Implementado de la manera m�s sencilla, pues podr�a haberse usado
// DLLNode*
int LinkedList::next(int pos) const {
    return pos + 1;
}
// Elimina todos los elementos de la lista, coloca getSize en cero, y la cabeza
// en NULL, o sea que hace un poco m�s que el destructor.
void LinkedList::clear() {
    if (head)
        delete head;
    head = NULL;
    getSize = 0;
}
// Retorna el primer elemento de la lista, si es que hay alguno
Object* LinkedList::first()const {
    if (head)
        return head->getData();
    return NULL;
}
// Retorna el �ltimo elemento de la lista, si es que hay alguno
Object* LinkedList::last()const {
    if (!head)
        return NULL;
    DLLNode* tmp = head;
    for (int i=0; i < getSize -1; i++)
        tmp = tmp->getNext();
    return tmp->getData();
}
// Imprime cada uno de los elementos que hay en la lista, llamando al m�todo
// print de cada nodo.
void LinkedList::print()const {
    DLLNode* tmp = head;
    for (int i=0; i < getSize; i++){
        tmp->print();
        tmp = tmp->getNext();
    }    
}
// Retorna si la lista est� llena, como nunca es as�, retorna false siempre.
bool LinkedList::isFull()const {
    return false;
}

    TDAList* LinkedList::toDLCursorList()const{
    TDAList* retVal = new DLCursorList();
    DLLNode* temp = head;
    for (int i = 0; i<getSize ; i++){
        retVal->insert(temp->getData(),i);
        temp = temp->getNext();
    }
    return retVal;
}

TDAList* LinkedList::toVArrayList()const{
    TDAList* retVal = new VArrayList(getSize);
    DLLNode* temp = head;
    for (int i = 0; i<getSize ; i++){
        retVal->insert(temp->getData(),i);
        temp = temp->getNext();
    }
    return retVal;
}
TDAList* LinkedList::toSLinkedList()const{
    TDAList* retVal = new SLinkedList();
    DLLNode* temp = head;
    for (int i = 0; i<getSize ; i++){
        retVal->insert(temp->getData(),i);
        temp = temp->getNext();
    }
    return retVal;
}

TDAList* LinkedList::toFArrayList()const{
    TDAList* retVal = new FArrayList(getSize);
    DLLNode* temp = head;
    for (int i = 0; i<getSize ; i++){
        retVal->insert(temp->getData(),i);
        temp = temp->getNext();
    }
    return retVal;
}