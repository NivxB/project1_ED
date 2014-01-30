//farraylist.h
#ifndef FARRAYLIST_H
#define FARRAYLIST_H

class FArrayList{
	FArrayList();
	virtual ~FArrayList();
    virtual bool insert(Object*, int) ;
    virtual int indexOf(Object*)const ;
    virtual Object* get(unsigned)const ;
    virtual bool erase(unsigned) ;
    virtual int prev(int) const ;
    virtual int next(int) const ;
    virtual void reset() ;
    virtual Object* first()const ;
    virtual Object* last()const ;
    virtual void print()const ;
    virtual bool isFull()const ;
};


#endif