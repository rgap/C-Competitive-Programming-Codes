#include "stdafx.h"
#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <queue>
#include <list>
using namespace std;

int main(){
	vector<int>v(2,200);//o list
	deque<int>deq(3,100);
	list<int>l(6,300);
	l.push_back(9);
	v.push_back(9);
	////////////////____STACK____////////////////////
	stack<int>s;//vacia
	stack<int>sd(deq);//sd=deq
	stack<int,vector<int>>sv1;//pila vacia usando vector?¿?
	stack<int,vector<int>>sv(v);//sd=v
	cout<<sd.size();//#elem
	sd.top()-=5;
	sv.push(1);
	while(!sv.empty()){//recorre eliminando
		cout<<sv.top()<<endl;
		sv.pop();
	}
	////////////////____QUEUE____////////////////////
	queue<int>q;//vacia
	queue<int>second(deq);
	queue<int,list<int>>ql1;
  	queue<int,list<int>>ql(l);

	cout<<ql.size();
	cout<<endl<<ql.front()<<"  "<<ql.back();

	ql.push(1);
	while(!ql.empty()){//recorre eliminando
		cout<<ql.front()<<endl;
		ql.pop();
	}
	////////////////____priority_queue____////////////////////
	int a[]= {10,60,50,20};
	priority_queue<int>pq1;//vacia    top es el menor
	priority_queue<int,vector<int>,greater<int>>pq(a,a+4);//greater - de menor a mayor -->top es el menor
														  //less - de mayor a menor  -->top es el mayor
	cout<<pq.size();
	pq.push(35);
	cout<<endl<<pq.top();//primer elemento - menor
	while(!pq.empty()){//recorre eliminando
		cout<<pq.top()<<endl;
		pq.pop();
	}
	return 0;
}
