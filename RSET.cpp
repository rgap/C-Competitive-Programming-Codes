#include "stdafx.h"
#include <iostream>
#include <set>

using namespace std;

struct classcomp{
	bool operator() (const int& lhs, const int& rhs) const{
		return lhs>rhs;
	}
};

int main(){
	int a[]= {20,10,99,30,90,100,50};
	set<int>::iterator it,itlow,itup;
	set<int>::reverse_iterator rit;
	pair<set<int>::iterator,bool> ret;
	set<int>::key_compare mycomp;
	set<int>::value_compare mycomp1;

	pair<set<int>::iterator,set<int>::iterator> ret1;

	set<int>first;
	set<int>second(a,a+7);//de menor a mayr por defecto
	set<int>third(second);
	set<int>fourth(second.begin(),second.end()); 
	set<int,classcomp>fifth;//de mayor a menor

	fifth.insert(2);
	fifth.insert(7);
	fifth.insert(1);

	first=second;
	second=set<int>();//elimina contenido de second

	for(it=first.begin();it!=first.end();it++)//recorre
		cout<<" "<<*it;
	cout<<endl;
	for(rit=first.rbegin();rit!=first.rend();rit++)
    	cout<< " "<<*rit;
	cout<<first.empty()<<first.size()<<first.max_size();

	for(int i=1; i<=5; i++) 
		second.insert(i*10);
	ret = second.insert(20); //20 ya pertenece a second y no inserta
	if (ret.second==false) it=ret.first;

	second.insert (it,25);//inserta 25 en la sgte posicion de it sin borrar nada
	first.insert (a,a+3);//first=a

	it=second.begin();
  	it++; //it apunta al 2do elem
	second.erase(it);
	second.erase(40);

	it=second.find(25);//it= posicion de 25
	second.erase(it,second.end());

	second.swap(first);//cambio de contenidos
	first.clear();
	second.insert(45);
	////////////////////////////////////////////////////////////////////////////////
	mycomp=second.key_comp();//comparador de second
  	it=second.begin();
	cout<<endl;
  	while(mycomp(*it,25)){//recorre desde it hasta que ya no sean menor que 25
    	cout<<" "<<*it;
		*it++;
  	}
	//
	mycomp1=second.value_comp();
	it=second.begin();
	cout<<endl;
	while(mycomp(*it,60)){//recorre desde it hasta que ya no sean menor que 60
    	cout<<" "<<*it;
		*it++;
  	}
	/////////////////////////////////////////////////////////////////////////////

	it=second.find(20);
  	second.erase(it);//elimina
	cout<<second.count(40);//0 o 1 en conjuntos

	ret1=second.equal_range(50);//el valor debe pertenecer al set, sino da 2 valores con rango de 0

	itlow=second.lower_bound(25);
 	itup=second.upper_bound(61);
  	second.erase(itlow,itup);//elimina los elementos entre un rango
	
	///////////////////////////______MULTISET_______///////////////////////////
	int myints[]= {10,20,30,20,20};
	multiset<int>ms(myints,myints+5);//el set pero acepta elementos iguales

	return 0;
}
