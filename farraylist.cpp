//farraylist.cpp
#include "farraylist.h"
#include <iostream>

bool FArrayList::insert(Object e, int p){

	if(size()!=capacity){
		if(p<=size()&&p>=0){
			for(int i=size()-1;i>=p;i--){
				data[i+1]=data[i];
			}
			data[p]=e;
			setSize(size()+1);
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

bool FArrayList::remove(int p){

	if(p<0||p>size()){

		for(int i=p;i<size()-1;i++){
			data[i]=data[i+1];
		}
		setSize(size()-1);
		return true;

	}else{
		std::cerr<<"La posición no existe."<<std::endl;
		return false;
	}


}

bool FArrayList::isFull(){
	if(size()==capacity)
		return true;

	return false;
}