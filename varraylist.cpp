//varraylist.cpp
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
	if(p>=0){
		if(p<=getSize){
			if(getSize!=capacity){
				if(p==0){
					for(int i=0;i<=getSize;i++){
						data[i+1]=data[i];
					}
					data[0]=e;
					getSize++;
				}else if (p==getSize){
					data[p]=e;
					getSize++;
				}else{

				}
			}else{
				capacity+=i_delta
				if(i_delta!=0){
					if(p==0){
					for(int i=0;i<=getSize;i++){
						data[i+1]=data[i];
					}
					data[0]=e;
					getSize++;
					}else if (p==getSize){
					data[p]=e;
					getSize++;
					}else{

					}
				}else if(d_delta!=0){

				}else{

				}
			}
		}else{
			std::cerr<<"La posición no es válida"<<std::endl;
		}
	}else{
		std::cerr<<"La posición no existe"<<std::endl;
	}
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

bool VArrayList::isFull()const{
	if(size()==capacity)
		return true;

	return false;
}



	int VArrayList::indexOf(Object* o)const{
		return 0;
	}
    Object* VArrayList::get(int p)const{

    }
	bool VArrayList::erase(int p){
		return true;
	}
    int VArrayList::prev(int p) const{
    	return 0;
    }
    int VArrayList::next(int p) const{
    	return 0;
    }
    void VArrayList::reset(){

    }
    Object* VArrayList::first()const{
    	Object* temp = new Object();
    	return temp;
    }
    Object* VArrayList::last()const{
    	Object* temp = new Object();
    	return temp;
    }
    void VArrayList::print()const{

    }
    bool VArrayList::isEmpty()const{
    	return true;
    }
	void VArrayList::clear()const{

	}