//varraylist.h
#ifndef VARRAYLIST_H
#define VARRAYLIST_H

#include "tdalist.h"
#include "object.h"
#include "dlcursorlist.h" 
#include "farraylist.h"     //Arreglos de tamaño fijo
#include "slinkedlist.h"    //Lista Enlazada Sencilla
#include "linkedlist.h"         //Lista Doblemente Enlazada

class VArrayList:public TDAList{
int capacity;
Object** data;
int i_delta;
double d_delta;
public:
	VArrayList();//100% dinámica
	VArrayList(int);//cap inicial
	VArrayList(int, int);//cap, delta
	VArrayList(int, double);//cap, delta porcentaje
    virtual ~VArrayList();
    virtual bool insert(Object*, int);
    virtual int indexOf(Object*)const;
    virtual Object* get(int)const;
    virtual Object* remove(int);
    virtual bool erase(int);
    virtual int prev(int) const;
    virtual int next(int) const;
    virtual void reset();
    virtual Object* first()const;
    virtual Object* last()const;
    virtual void print()const;
    virtual bool isEmpty()const;
    virtual bool isFull()const;
    virtual void clear();
    TDAList* toDLCursorList()const;
    TDAList* toFArrayList()const;
    TDAList* toSLinkedList()const;
    TDAList* toLinkedList()const;


};

#endif