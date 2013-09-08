#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

bool EsPar (int i) {
  return ((i%2)==0);
}


struct myclass {
  bool operator() (int i,int j) { return (i<j);}
} myobject;

int main ()
{
  int myin[] = { 19, 20, 35 ,30 };int * p;
  p = find(myin,myin+4,30);
  cout <<*p;//posicion de 30
  vector<int> myvec (myin,myin+4);  vector<int>::iterator it0;
  it0 = find (myvec.begin(), myvec.end(), 30);
  cout<< *it0;//posicion de 30
  it0 = find_if (myvec.begin(), myvec.end(), EsPar);
  cout << "valor par " << *it0 << endl;
  //////////////////////////////////////////////
  int c=(int) count (myin, myin+8, 10);//# de veces que aparece 10
  c = (int) count (myvec.begin(), myvec.end(), 20);//# de veces que aparece 20

  ////////////////////////////////////////////
  int myints[] = {32,71,12,45,26,80,53,33};
  vector<int> myvector (myints, myints+8);// 32 71 12 45 26 80 53 33
  vector<int>::iterator it;
  // comparador por defecto < , creciente hasta el 4 elem
  sort (myvector.begin(), myvector.begin()+4);//(12 32 45 71)26 80 53 33
  sort (myvector.begin()+4, myvector.end(), myfunction); //usa func,12 32 45 71(26 33 53 80)
  sort (myvector.begin(), myvector.end(), myobject);//obj, (12 26 32 33 45 53 71 80)

  //////////////////////////////////////////////////
  int first[] = {5,10,15,20,25};
  int second[] = {50,40,30,20,10};
  vector<int> v(10);
  sort (first,first+5);
  sort (second,second+5);
  merge (first,first+5,second,second+5,v.begin());//ordena y combina
  /////////////////////////////////
   //para char, int , double
  min(1.2,2.24);//minimo
  max(1.2,2.24);
  int ff= *max_element (v.begin(), v.end());//max elem de vector
  *min_element (v.begin(), v.end());//* contenido de iterador
  *min_element(first,first+5);//para array


  return 0;
}
