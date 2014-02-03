//slinkedlist.h
#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H
#include "object.h"
#include "tdalist.h"
#include "SLLNode.h"
class SLinkedList:public TDAList{
	protected:
        SLLNode* head;
    public:
	   SLinkedList();
       ~SLinkedList();
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
};
#endif