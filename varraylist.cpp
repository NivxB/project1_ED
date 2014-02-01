//VArraylist.cpp
#include "varraylist.h"
#include <iostream>

VArrayList::VArrayList(){
	data = new Object*[1];
	getSize=0;
	capacity=0;
	i_delta=0;
	d_delta=0;

}

VArrayList::VArrayList(int size){
	data = new Object*[size];
	getSize=0;
	capacity=size;
	i_delta=0;
	d_delta=0;
	
}

VArrayList::VArrayList(int size, int delta){
	data = new Object*[size];
	getSize=0;
	capacity=size;
	i_delta=delta;
	d_delta=0;
	
}

VArrayList::VArrayList(int size, double delta){
	data = new Object*[size];
	getSize=0;
	capacity=size;
	i_delta=0;
	d_delta=delta;
}

VArrayList::~VArrayList(){

}

bool VArrayList::insert(Object* e, int p){
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
		if(i_delta!=0){
			capacity+=i_delta;
			Object** temp = new Object*[capacity];
			for(int i=0;i<=size();i++){
				temp[i]=data[i];
			}
			data = temp;
			for(int i=size()-1;i>=p;i--){
				data[i+1]=data[i];
			}
			data[p]=e;
			getSize++;
			return true;
		}else if(d_delta!=0){
			capacity=capacity+(capacity*i_delta);
			Object** temp = new Object*[capacity];
			for(int i=0;i<=size();i++){
				temp[i]=data[i];
			}
			data = temp;
			for(int i=size()-1;i>=p;i--){
				data[i+1]=data[i];
			}
			data[p]=e;
			getSize++;
			return true;

		}else{
			capacity++;
			Object** temp = new Object*[capacity];
			for(int i=0;i<=size();i++){
				temp[i]=data[i];
			}
			data = temp;
			for(int i=size()-1;i>=p;i--){
				data[i+1]=data[i];
			}
			data[p]=e;
			getSize++;
			return true;
		}
	}
}

bool VArrayList::isFull()const{
	if(size()==capacity)
		return true;

	return false;
}


Object* VArrayList::remove(int p){
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


	int VArrayList::indexOf(Object* o)const{
		for(int i=0;i<=size();i++){
			if(data[i]->equals(o))
				return i;
		}
		return -1;
	}

    Object* VArrayList::get(int p)const{
    	return data[p];
    }

	bool VArrayList::erase(int p){
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

    int VArrayList::prev(int p) const{
    	return 0;
    }

    int VArrayList::next(int p) const{
    	return 0;
    }

    void VArrayList::reset(){
			delete[] data;
    }

    Object* VArrayList::first()const{
    	Object* temp = data[0];
    	return temp;
    }

    Object* VArrayList::last()const{
    	Object* temp = data[getSize];
    	return temp;
    }

    void VArrayList::print()const{

    }

    bool VArrayList::isEmpty()const{
    	if(getSize==0)
    		return true;
    	return false;
    }

	void VArrayList::clear(){
		getSize=0;
	}