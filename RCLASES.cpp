
#include <iostream.h>
#include <conio.h>
#include <vector>
#include <algorithm>

class A{
       int p;
       private:
              int m1;//datos miembro
              int m2;
              int m3; 
              char *cad; 
              int *punt;
       public:
              int q;
              //A(int x=0,int y=0,int z=10):m1(x),m2(y),m3(z){} --> a
              A(const char *c) {
                    cad = new char[strlen(c)+1];// Reserva memoria para cadena
                    strcpy(cad, c);             // Almacena la cadena
              }
              A(int pu){
                    punt=&pu;
              }
              A(int x,int y,int z=10):m1(x),m2(y),m3(z){}
              A(const A &c) : m1(c.m1), m2(c.m2),m3(c.m3) {} //constructor copia
              A() : m1(0),m2(1),m3(2){}//inicializador en linea
              ~A(){
                   delete[] cad;
                   delete punt;
              };
              int suma(int x,int y);   //funciones miembro
              void setMiembros(int x,int y,int z){m1=x;m2=y;m3=z;}//guarda
              void lee(int &x,int &y, int &z){
                   x=m1;
                   y=m2;
                   z=m3;
              }
              /*
              void lee(int x, int y, int z){
                   this->m1 = x;
                   this->m2 = y;
                   this->m3 = z;
              }
              */
              
              void setm1(int x){m1=x;}
              int set1m1(int x){return (m1=x);};
              
              int getm1(){return m1;}
              
              void imprimir(){
                   cout<<endl<<m1<<" "<<m2<<" "<<m3<<endl;
              }
       protected:
};

int A::suma(int x,int y){
    return (x+y);
}


main(){
    A a(30,20), b, c;
    A copia=a;//A copia(a);
    //A copia=14; --> a
    
    c=b;
    //cout<<a.p; //p es privado
    a.q=NULL;
    cout<<a.q;
    
    a.imprimir();
    b.imprimir();
    c.imprimir();
    
    a.setm1(100);
    a.imprimir();
    a.set1m1(200);
    a.imprimir();
    
    int p,q,r;
    a.lee(p,q,r);
    cout<<endl<<p<<" "<<q<<" "<<r<<endl;
    
    
    getch();
}
