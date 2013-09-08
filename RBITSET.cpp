#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main(){
	//contiene elementos que son 0 o 1
	bitset<10>first1;//vacio
  	bitset<10>second1(11);//valor 11 en binario desde el inicio
  	bitset<10>third("01011");//valor 11010 desde el inicio

	bitset<4>first ("1001");
	bitset<4>second ("0011");

	cout<<(first^=second)<<endl;          // 1010 (XOR,assign)
	cout<<(first&=second)<<endl;          // 0010 (AND,assign)
	cout<<(first|=second)<<endl;          // 0011 (OR,assign)
	cout<<(first<<=2)<<endl;              // 1100 (SHL,assign)
	cout<<(first>>=1)<<endl;              // 0110 (SHR,assign)
	cout<<(~second)<<endl;                // 1100 (NOT)
	cout<<(second<<1)<<endl;              // 0110 (SHL)
	cout<<(second>>1)<<endl;              // 0001 (SHR)
	cout<<(first==second)<<endl;          // false (0110==0011)
	cout<<(first!=second)<<endl;          // true  (0110!=0011)
	cout<<(first&second)<<endl;           // 0010
	cout<<(first|second)<<endl;           // 0111
	cout<<(first^second)<<endl;           // 0101
	////////////////////////////////////////////////
	first[0]=1;       // 1110
    first[3]=first[1];
	//////////////////////////////////
	bitset<4> mybits;
  	cout<<mybits.set()<<endl;       // 1111
  	cout<<mybits.set(2,0)<<endl;    // 1011
  	cout<<mybits.set(2)<<endl;      // 1111
	//////////////////////////////////////////

	bitset<4>mybits1("1011");
  	cout<<mybits1.reset(1)<<endl;    // 1001
  	cout<<mybits1.reset()<<endl;    // 0000

	bitset<4> mybits2("0001");
  	cout<<mybits2.flip(2)<<endl;     // 0101
  	cout<<mybits2.flip()<<endl;      // 1010

	/////////////////////FALTAAAAAAAAAAAAAA
	return 0;
}

