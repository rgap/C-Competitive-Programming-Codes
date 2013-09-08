/*
El preprocesador analiza el fichero fuente antes de la fase de compilación real, y realiza las sustituciones de macros 
y procesa las directivas del preprocesador.
El preprocesador también elimina los comentarios.
Una directiva de preprocesador es una línea cuyo primer carácter es un #.
*/

#include <iostream.h>
#include <conio.h>

#define AA 3

#define BB 5
#undef BB //quitar definicion

#ifndef CC //si no esta definido CC
  #define CC 4
#endif 

#ifdef AA //si esta definido AA
  #define DD 9
#endif

#ifdef ZZ
  #define XX 9
#endif

#if 0 //0 es un condicional
    #define LL 4
#elif AA
    #define LL 5  
#else
    #define LL 6
#endif

/*
#ifndef BFD_HOST_64_BIT
 #error No 64 bit integer type available
#endif //defined (BFD_HOST_64_BIT)
*/

//#line 4 "RESUMEN1.cpp"

#ifdef __DEPRECATED
#warning This file includes at least one deprecated or antiquated header. \
Please consider using one of the 32 headers found in section 17.4.1.2 of the \
C++ standard. Examples include substituting the  header for the  \
header for C++ includes, or  instead of the deprecated header \
. To disable this warning use -Wno-deprecated.
#endif

#pragma pack(1)

struct A {
   int x;
   char a;
   int y;
   char b;
};

#pragma pack()

struct B {
   int x;
   int y;
   char a;
   char b;
};


main(){
       
       cout<<endl<<AA;
       //cout<<BB; error
       cout<<endl<<CC;
       cout<<endl<<DD;
       //cout<<endl<<XX; error
       cout<<endl<<LL;
       
       cout<<endl<<"Tama\xa4o de int: " 
       <<sizeof(int)<<endl;
       cout<<"Tamaño de char: " 
       <<sizeof(char)<<endl;
       cout<<"Tamaño de estructura A: " 
       <<sizeof(A)<<endl;
       cout<<"Tamaño de estructura B: " 
       <<sizeof(B)<<endl;

       getch();
}

