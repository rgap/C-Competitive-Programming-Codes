#include <iostream>
#include <vector>

using namespace std;

int main ()
{
  unsigned int i;
  vector<int> first;// vacio
  vector<int> f(100);//vacio de tamaño 100
  vector<int> second (4,100);                       // tamaño 4 con valores 100
  vector<int> third (second.begin(),second.end());  // iterating copiado de second
  vector<int> fourth (third); fourth=third;         //copia de third
  int myints[] = {16,2,77,29};
  vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );//fifth = myints
  for (i=0; i < fifth.size(); i++)//contenido
    cout << " " << fifth[i];
  fifth=vector<int>();//borra contenido
  cout <<fifth.size();//tamaño 0

  vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);//llena
  vector<int>::iterator it;//iterador de vector
  for ( it=myvector.begin() ; it < myvector.end(); it++ )//contenido
    cout << " " << *it;//1 2 3 4 5
  vector<int>::reverse_iterator rit;
  for ( rit=myvector.rbegin() ; rit < myvector.rend(); ++rit )
    cout << " " << *rit;//5 4 3 2 1
  size_t s = myvector.size();//5
  size_t s1 = myvector.capacity();//8
  size_t s2 =myvector.max_size();//tamaño maximo
  ////////////////////////////////////////////////////
  myvector.resize(2);//reduce tamaño a 2
  myvector.resize(8,100);//tam 8,, llena de 100 de 2 hasta 8
  myvector.resize(12);//tamaño 12,, llena con 0 de 8 hasta 12

  bool d=myvector.empty();//0= no vacio
  first.reserve(s); //http://www.cplusplus.com/reference/stl/vector/reserve/
  ////////////////////////////
  for (int i=0; i<myvector.size(); i++)//llena
    myvector.at(i)=i;
  for (int i=0; i<myvector.size(); i++)//contenido
    cout << " " << myvector.at(i);
  myvector.front();//primer elem
  myvector.back();//ultimo elem

  vector<int> v;
  v.assign (7,100); //7 veces 100
  vector<int>::iterator it1;
  it1=myvector.begin()+1;
  v.assign (it1+3,myvector.end()-1); //v contiene del 4 al penultimo elem

  int myints1[] = {1776,7,4};
  v.assign (myints1,myints1+3);//desde array
  /////////////////////////////////////////////////
  v.push_back (212);//añade al final de vector
  v.pop_back();//elimina el utlimo elem de vector
  //////////////////////////////////////////
  it=myvector.begin()+8;
  it = myvector.insert ( it , 200 );//en la posicion 3 inserta 200
  myvector.insert (it,2,300);//en la posicion 2 inserta 300 2 veces sin eliminar nada

  it = myvector.begin();
  vector<int> anothervector (2,400);
  myvector.insert (it,anothervector.begin(),anothervector.end());//cont de anothervector a myvector desde inicio
  //sin eliminar nada

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);//lo mismo que el anterior pero para array

  vector<unsigned int> myvector1;
  for (i=1; i<=10; i++) myvector1.push_back(i);
  myvector1.erase (myvector1.begin()+5);//borra el elem 6
  myvector1.erase (myvector1.begin(),myvector1.begin()+3);//borra los primeros 3 elem

  second.swap(myvector);//second= myvector y myvector=second

  myvector.clear();//vector vacio
  cout<<endl;
  ///////////////////////////////////////////////////
  //get_allocator()
  int * p;
  p=myvector.get_allocator().allocate(5);//reserva memoria para p usando la funcion del vector
  for (int i=0; i<5; i++) p[i]=i;
  for (int i=0; i<5; i++) cout << " " << p[i];
  myvector.get_allocator().deallocate(p,5);

  return 0;
}
