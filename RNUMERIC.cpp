#include "stdafx.h"
#include <iostream>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

int myfunction(int x, int y){
	return x+2*y;
}
struct myclass{
	int operator()(int x, int y){return x+3*y;}
}myobject;

int myop (int x, int y) {return x+y;}

int myaccumulator (int x, int y) {return x-y;}
int myproduct (int x, int y) {return x+y;}


int main(){
	int first[]={1,2,3,4,5};
  	int second[]={10,20,30,40,50};
  	int results[5];
  	transform(first,first+5,second,results,plus<int>());//suma los elementos segun su posicion y los almacena en results
	///////////////////////////////
	int init=100;
	int numbers[]={10,20,30}; int ac;
	ac=accumulate(numbers,numbers+3,init);//suma elementos del arreglo desde un valor inicial init
	ac=accumulate(numbers,numbers+3,init,minus<int>());//resta
	ac=accumulate(numbers,numbers+3,init,myfunction);//funcion
	ac=accumulate(numbers,numbers+3,init,myobject);
	////////////////////////////////////////////////
	int val[] = {1,2,3,5,9,11,12};
  	int result[7];
  	adjacent_difference(val,val+7,result);//cada dos elem adyacentes los resta y almacena en result
	adjacent_difference(val,val+7,result,multiplies<int>());//multiplica
	adjacent_difference(val,val+7,result,myop);
	/////////////////////////////////////////////////
	int init = 100,p;
  	int series1[] = {10,20,30};
  	int series2[] = {1,2,3};
	p=inner_product(series1,series1+3,series2,init);//multiplica cada elemento correspondiente de series1 y 2
	p=inner_product(series1,series1+3,series2,init,minus<int>(),divides<int>());
	p=inner_product(series1,series1+3,series2,init,myaccumulator,myproduct);
	////////////////////////////////////////////////
	int val[] = {1,2,3,4,5};
	int result[5];
	partial_sum (val, val+5, result);//suma acumulando y cada acumulado se inserta en result
	partial_sum (val, val+5, result, multiplies<int>());
	partial_sum (val, val+5, result, myop);

	return 0;
}
