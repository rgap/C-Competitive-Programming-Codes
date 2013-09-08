#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>//stringstream

using namespace std;

int main ()
{
	char c='a';
	c-='a'-'A';//MINUSC -> MAYUS
	c+='a'-'A';//MAYUS -> MINUSC

    //CHAR - STRING
    char a='c';
    string str; str=a;

    //STRING - CHAR
    string str1="d";
    char c;
    c=str1[0];

    //CHAR - CHAR*
    char b= 'k';
    char* charr=new char[0];
    charr[0]=b;

    //CHAR* - CHAR
    char*charr1="s";
    char r;
    r=charr1[0];

    //CHAR[] - CHAR*
    char arra[100] = "Hola";
	char * pp;
	pp=arra;

	//CHAR* - CHAR[]?????
	//CHAR[] - STRING
	char array1[]="cadeaf";
    string string1(array1);

    //STRING - CHAR[]???????
    //STRING - CHAR*
    char *cstr;
    string str2=" ...cCad enaaA a aa ";
    cstr = new char [str2.size()+1];
    strcpy (cstr, str2.c_str());
    delete[] cstr;

    //CHAR* - STRING
    char* ch = " cs..tring cadena ";
    string str3;
    str3 =ch;

    ////////////////////////////////////
    //CHAR/ASCCI - INT
    int  asciiVal; int num;
    char  letter = '!';
    asciiVal = (int)letter; //char a decimal para ascci
    num=letter-'0';//char a int

    //INT - CHAR/ASCCI
    int di=33;
    char asc=(char)di;
    /////
    int digito=9;
    asc='0'+digito;


    //INT - CHAR[]/CHAR*
    char stri [33];
    int i;
    //itoa (i,stri,10); //base 10  //WINDOWS
    //LINUX --- http://www.jb.man.ac.uk/~slowe/cpp/itoa.html

    //CHAR[] - INT
    char st[]="1214";
    int k = atoi(st);

    //CHAR* - INT
    char*bud="41512";
    int f=atoi(bud);


    //STRING - INT
    string foo = "123";
    int j = atoi(foo.c_str());

    //INT - STRING
    int g = 24125;
    string s; stringstream out;
    out << g; s = out.str();

    return 0;
}
