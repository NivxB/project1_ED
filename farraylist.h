//farraylist.h
#ifndef FARRAYLIST_H
#define FARRAYLIST_H

#include "tdalist.h"
#include "object.h"
#include "dlcursorlist.h" 
#include "varraylist.h"
#include "slinkedlist.h"    //Lista Enlazada Sencilla
#include "linkedlist.h"         //Lista Doblemente Enlazada

class FArrayList:public TDAList{
    Object** data;
    int capacity;
public:
    FArrayList();
	FArrayList(int);
	virtual ~FArrayList();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(int)const ;
    virtual Object* remove(int);
    virtual bool erase(int) ;
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void reset() ;
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isFull()const ;
    virtual void clear();
    virtual bool isEmpty()const;
    TDAList* toDLCursorList()const;
    TDAList* toVArrayList()const;
    TDAList* toSLinkedList()const;
    TDAList* toLinkedList()const;
};


#endif