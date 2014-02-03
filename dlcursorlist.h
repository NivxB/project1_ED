#ifndef DLCURSORLIST_H
#define DLCURSORLIST_H

#include "tdalist.h"
#include "varraylist.h" 	//Arreglos de tamaño variable
#include "farraylist.h" 	//Arreglos de tamaño fijo
#include "slinkedlist.h" 	//Lista Enlazada Sencilla
#include "linkedlist.h"         //Lista Doblemente Enlazada
#include "object.h"

class DLCursorList : public TDAList
{
		struct Row{
			int prev,next;
			Object* data;
		};
		double grow;
		int ActualSize;
		Row* data; 
		int head;
	public:
		DLCursorList();
		DLCursorList(int);
		DLCursorList(int,int);
		DLCursorList(int,double);
		virtual ~DLCursorList();
		virtual bool insert(Object*, int);
		virtual int indexOf(Object*)const;
		virtual Object* get(int)const;
		virtual Object* remove(int);
		virtual int prev(int) const;
		virtual int next(int) const;
		virtual void clear();
		virtual Object* first()const;
		virtual Object* last()const;
		virtual void print()const;
		virtual bool isEmpty()const;
		virtual bool isFull()const;	
		TDAList* toVArrayList()const;
		TDAList* toFArrayList()const;
		TDAList* toSLinkedList()const;
		TDAList* toLinkedList()const;
		int getCapacity()const;
		int nextSlot()const;
};

#endif