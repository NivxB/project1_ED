//farraylist.cpp
#include "farraylist.h"
#include <iostream>

FArrayList::FArrayList(int cap){
	capacity=cap;
	data = new Object*[cap];
}

FArrayList::~FArrayList(){
	delete[] data;
}

bool FArrayList::insert(Object* e, int p){

	if(size()!=capacity){
		if(p<=size()&&p>=0){
			for(int i=size()-1;i>=p;i--){
				data[i+1]=data[i];
			}
			data[p]=e;
			getSize++;
			return true;
		}else{
			std::cerr<<"La posición no existe."<<std::endl;
			return false;
		}
	}else{
		std::cerr<<"La lista está llena."<<std::endl;
		return false;	
	}
	

}


bool FArrayList::isFull()const{
	if(size()==capacity)
		return true;

	return false;
}


Object* FArrayList::remove(int p){
	if(p>=0||p<=size()){
		if(data[p]){
			Object* temp = data[p];

			for(int i=p;i<size()-1;i++){
				data[i]=data[i+1];
			}
			getSize--;
			return temp;
		}else{
			std::cerr<<"No hay datos en la posición"<<std::endl;
		}

	}else{
		std::cerr<<"La posición no existe."<<std::endl;
	}
}


	int FArrayList::indexOf(Object* o)const{
		for(int i=0;i<=size();i++){
			if(data[i]->equals(o))
				return i;
		}
		return -1;
	}

    Object* FArrayList::get(int p)const{
    	return data[p];
    }

	bool FArrayList::erase(int p){
		if(p>=0||p<=size()){
		if(data[p]){

			for(int i=p;i<size()-1;i++){
				data[i]=data[i+1];
			}
			getSize--;
			return true;
		}else{
			std::cerr<<"No hay datos en la posición"<<std::endl;
			return false;
		}

	}else{
		std::cerr<<"La posición no existe."<<std::endl;
		return false;
	}
	}

    int FArrayList::prev(int p) const{
    	return 0;
    }

    int FArrayList::next(int p) const{
    	return 0;
    }

    void FArrayList::reset(){
			delete[] data;
    }

    Object* FArrayList::first()const{
    	Object* temp = data[0];
    	return temp;
    }

    Object* FArrayList::last()const{
    	Object* temp = data[getSize];
    	return temp;
    }

    void FArrayList::print()const{

    }

    bool FArrayList::isEmpty()const{
    	if(getSize==0)
    		return true;
    	return false;
    }

	void FArrayList::clear(){
		getSize=0;
	}