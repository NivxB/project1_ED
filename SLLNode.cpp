#include "SLLNode.h"
#include "object.h"
#include <iostream>
using namespace std;

SLLNode::SLLNode(){
	next=NULL;
	data=NULL;
}
SLLNode::SLLNode(Object* dato){
	data=dato;
}
SLLNode::SLLNode(Object* dato,SLLNode* nodo){
	data=dato;
	next=nodo;
}
SLLNode::~SLLNode(){
	if(data)
		delete data;
	if(next)
		delete next;
}
void SLLNode::print()const{
    data->print();
}
// Método Accesor de Next
SLLNode* SLLNode::getNext()const{
    return next;
}
// Método Accesor de Prev

void SLLNode::setNext(SLLNode* aNext){
    next = aNext;
}

// Método Accesor de Data
Object* SLLNode::getData()const{
    return data;
}
// Método Mutador de Data
void SLLNode::setData(Object* dato){
    data = dato;
}