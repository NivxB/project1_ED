#ifndef SLLNODE_H
#define SLLNODE_H
#include "object.h"


class SLLNode
{
	Object* data;
	SLLNode* next;
public:
	SLLNode();
    SLLNode(Object*);
    SLLNode(Object*, SLLNode*);
    ~SLLNode();
    void print()const;
    SLLNode* getNext()const;
    void setNext(SLLNode*);
    Object* getData()const;
    void setData(Object*);
};
#endif