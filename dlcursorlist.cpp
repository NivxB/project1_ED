#include "dlcursorlist.h"
#include <iostream>
using namespace std;

DLCursorList::DLCursorList(){
	data = new Row[1];
	head = -1;
	grow = 1;
	ActualSize = 1;
}

DLCursorList::DLCursorList(int S){
	data = new Row[S];
	head = -1;
	grow = 1;
	ActualSize = S;
}

DLCursorList::DLCursorList(int S,int G){
	data = new Row[S];
	head = -1;
	grow = G;
	ActualSize = S;
}

DLCursorList::DLCursorList(int S,double G){
	data = new Row[S];
	head = -1;
	grow = G;
	ActualSize = S;
}

DLCursorList::~DLCursorList(){
	delete data;
}

bool DLCursorList::insert(Object* E, int P){
	if (P < 0 || P>getSize)
		return false;
	if (!data)
		return false;
	//cout << "ANTES AUMENTO" << endl;
	if (getSize == ActualSize){
		Row* tmp;
		if (grow<0){
			int NewS = ActualSize * grow;
			ActualSize += NewS;
			tmp =  new Row[ActualSize];
			for (int i = 0; i<getSize;i++)
				tmp[i] = data[i];
		}else{
			ActualSize += grow;
			tmp =  new Row[ActualSize];
			for (int i = 0; i<getSize;i++)
				tmp[i] = data[i];
		}
		delete data;
		data = tmp;                            
	}
	//cout << "DESPUES AUMENTO" << endl;
	Row NewR;
	if (head == -1 && P == 0){
		NewR.prev = -1;
		NewR.next = -1;
		NewR.data = E;
		head = 0;
		data[head] = NewR;
	}else if(P == 0 && head != -1){
		NewR.prev = -1;
		NewR.next = head;
		NewR.data = E;
		int P = nextSlot();
		data[head].prev = P;
		data[P] = NewR;
	}else if(P<=getSize){
		int temp = head;
		//cout <<"ANTES SLOT" << endl;
		int S = nextSlot();
		//cout <<"DESPUES SLOT" << endl;	
		for (int i = 1 ; i<S ; i++)
			temp = data[temp].next;
		NewR.prev = temp;
		NewR.data = E;
		NewR.next = data[temp].next;
		if (data[temp].next != -1)
			data[data[temp].next].prev = P;
		data[temp].next = P;
		data[S] = NewR;
	}
	getSize++;
	return true;
}

int DLCursorList::indexOf(Object* E)const{
	int temp = head;
	for (int i = 0; i<getSize;i++){
		if (data[temp].data->equals(E))
			return i;
		temp = data[temp].next;
	}

	return -1;
}

Object* DLCursorList::get(int P)const{
	if (P<0 || P>getSize)
		return NULL;
	int temp = head;

	for (int i = 0; i<P;i++)
		temp = data[temp].next;

	return data[temp].data;
}

Object* DLCursorList::remove(int P){
	if (P<0 || P>getSize)
		return NULL;

	Object* tmpdata = NULL;
	if (head == -1 && P == 0){
		tmpdata = data[head].data;
		data[head].data = NULL;
		head = -1;
	}else if(P == 0 && head != -1){
		tmpdata = data[head].data;
		data[head].data = NULL;
		head = data[head].next;

	}else if(P<getSize){
		int temp = head;
		for (int i = 1 ; i<P ; i++)
			temp = data[temp].next;
		int N = data[temp].next;
		tmpdata = data[N].data;
		data[N].data = NULL;

		data[temp].next = data[N].next;
		if (data[temp].next != -1)
			data[data[temp].next].prev = temp;
	}
	getSize--;
	return tmpdata;
}

int DLCursorList::prev(int P)const{
	int temp = head;
	for (int i = 0 ; i<P ; i++)
		temp = data[temp].next;
	return data[temp].prev;
}

int DLCursorList::next(int P)const{
	int temp = head;
	for (int i = 0 ; i<P ; i++)
		temp = data[temp].next;
	return data[temp].next;
}

void DLCursorList::clear(){ 
	delete data;
	data = new Row[getSize];	
	getSize = 0;
}

Object* DLCursorList::first()const{
	if (head == -1)
		return NULL;

	return data[head].data;
}

Object* DLCursorList::last()const{
	int temp = head;
	for (int i = 0 ; i<getSize ; i++)
		temp = data[temp].next;

	return data[temp].data;
}

void DLCursorList::print()const{
	int temp = head;
	for (int i = 0;i<getSize;i++){
		data[temp].data -> print();
		temp = data[temp].next;
	}
}

bool DLCursorList::isEmpty()const{
	if (head == -1)
		return true;

	return false;
}

bool DLCursorList::isFull()const{
	return false;
}

int DLCursorList::getCapacity()const{
	return -1;
}

int DLCursorList::nextSlot()const{
	for (int i = 0 ; i < getSize ; i++){
		if (data[i].data == NULL)
			return i;
	}
	return getSize;
}

TDAList* DLCursorList::toVArrayList()const{
	TDAList* retVal = new VArrayList(getSize,5);
	int temp = head;
	for (int i = 0; i<getSize ; i++){
		retVal->insert(data[temp].data,i);
		temp = data[temp].next;
	}
	return retVal;
}

TDAList* DLCursorList::toFArrayList()const{
	TDAList* retVal = new FArrayList(getSize);
	int temp = head;
	for (int i = 0; i<getSize ; i++){
		retVal->insert(data[temp].data,i);
		temp = data[temp].next;
	}
	return retVal;
}
TDAList* DLCursorList::toSLinkedList()const{
	TDAList* retVal = new SLinkedList();
	int temp = head;
	for (int i = 0; i<getSize ; i++){
		retVal->insert(data[temp].data,i);
		temp = data[temp].next;
	}
	return retVal;
}

TDAList* DLCursorList::toLinkedList()const{
	TDAList* retVal = new LinkedList();
	int temp = head;
	for (int i = 0; i<getSize ; i++){
		retVal->insert(data[temp].data,i);
		temp = data[temp].next;
	}
	return retVal;
}