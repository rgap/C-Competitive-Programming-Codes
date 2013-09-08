#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct classcomp{
	bool operator() (const string& lhs, const string& rhs) const{
		return lhs>rhs;
	}
};

struct cmp_str{
   bool operator()(char const *a, char const *b) {
      return strcmp(a,b)<0;
   }
};

int main(){
	map<char,int>first;
	map<char,int>::iterator it,itlow,itup;
	map<char,int>::reverse_iterator rit;
	pair<map<string,int,classcomp>::iterator,bool> ret;
	map<string,int,classcomp>::iterator its;
	map<char,int>::key_compare mycomp;
	pair<map<string,int,classcomp>::iterator,map<string,int,classcomp>::iterator> ret0;

	//ordena de menor a mayor por defecto
	first['a']=10;
  	first['c']=50;
  	first['z']=30;
  	first['b']=90;

	map<char,int>second(first.begin(),first.end());//second=first
	map<char,int>third(second);//third=second

	map<char,int,classcomp>fourth;

	first=second; 
	for(it=second.begin();it!=second.end();it++)//imprimr
		cout<<(*it).first<<" => "<<(*it).second<<endl;
	for(rit=second.rbegin();rit!=second.rend();rit++)//imprimr
		cout<<rit->first<<" => "<<rit->second<<endl;

	cout<<second.empty()<<second.size()<<second.max_size();
	//////////////////////////////////////////////////////////

	map<string,int,classcomp> mymap;//de mayor a menor segun las palabras
	mymap["aaaa"]=52;
  	mymap["palabra"]=12;
	mymap["cccc"]=mymap["aaaa"];
	mymap["aaaa"]=2;//no acepta mas del primer elemento, esto le cambia el valor
	mymap["bbbb"]=24;
	///////////////////////////////////
	mymap.insert(pair<string,int>("llll",100));//inserta
	mymap.insert(pair<string,int>("aaaa",1)); //no acepta mas del primer elem y no cambia el valor

	ret=mymap.insert(pair<string,int>("uuuu",500));//inserta si es q no existe, si existe no cambia su valor
	if (ret.second==false){
    	cout<<"elemento ya existe";
    	cout<<" con un valor de"<<ret.first->second<<endl;
  	}
	//////////////////////////////////////	
	it=first.begin();
  	first.insert(it,pair<char,int>('d',300));//maxima eficiencia la insertar

	map<char,int>anothermap;
	anothermap.insert(first.begin(),first.find('c'));//copia hasta antes de encontrar c

	its=mymap.find("cccc");
  	mymap.erase(its);//elimina
	its=mymap.find("llll");
	mymap.erase(its,mymap.end());//elimina hasta llll

	second.swap(first);
	/////////////////////////////////////////////////////////////

	mycomp=first.key_comp();
	char highest=first.rbegin()->first;
	it=first.begin();
	do{
    	cout<<(*it).first<<" => "<<(*it).second<<endl;
  	}while(mycomp((*it++).first,highest));

	//////////////////////////////////////////////////////////
	pair<char,int> highest1;
	highest1=*first.rbegin();
  	it=first.begin();
  	do{
    	cout<<(*it).first<<" => "<<(*it).second<<endl;
 	}while(first.value_comp()(*it++, highest1));
	/////////////////////////////////////////////////////////
	cout<<mymap.count("aaaa");

	itlow=first.lower_bound ('b');
  	itup=first.upper_bound ('z'); 
  	first.erase(itlow,itup);//elimina en el rango
	////////////////////////////////

	mymap["bbbb"]=24;
	mymap["cccc"]=24;
	mymap["zzzz"]=24;
	ret0=mymap.equal_range("cccc");

	mymap.clear();
	///////////////////////////////______MULTIMAP_______///////////////
	multimap<char,int> first3;//inserta con repeticiones de los primeros elem
	first3.insert(pair<char,int>('a',10));
  	first3.insert(pair<char,int>('b',15));
  	first3.insert(pair<char,int>('b',20));
  	first3.insert(pair<char,int>('c',25));

	return 0;
}
