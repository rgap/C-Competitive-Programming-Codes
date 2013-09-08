#include <iostream>
#include <string>//viene sin este include

#include <cstring>//cstring --- char*... strcpy, strcmp....
using namespace std;

int main ()
{
  string s0 ("STR INGSTRi ING");
  string s1;//pueden compararse != == <= >= < >
  string s2 (s0);//s2=s0
  string s3 (s0, 8, 3);//s0 desde 8 primeros caracteres hasta los 3 siguientes //TRi
  string s4 ("A character sequence", 6);//6 primeras letras de la cadena
  string s5 ("Another character sequence");//c5=cadena
  string s6 (10, 'x');//xxxxxxxxxx
  string s7a (2,33);//2 veces
  string s7b (s0.begin(), s0.begin()+7);//s0 desde inicio hasta inicio+7 //STR ING

  string str1, str2, str3;
  str1 = "AB: ";// c-string
  str2 = 'C';//char
  str3 = str1 + str2;//concatena //AB: C

  string str ("Test string");
  string::iterator it;
  for ( it=str.begin() ; it < str.end(); it++ )
    cout << *it;
  string::reverse_iterator rit;
  for ( rit=str.rbegin() ; rit < str.rend(); rit++ )
    cout << *rit;//gnirts tseT
  int l=str.size(); l=str.length();//11
  int l1= str.capacity(); //>= al # de elem
  l1=str.max_size(); //# maximo de elem

  size_t sz;
  string str4 ("I like to code in C");
  str4.resize (str4.size()+2,'+');//I like to code in C++
  str4.resize (14);//I like to code

  string str6; str6.reserve(sz);
  //http://www.cplusplus.com/reference/string/string/reserve/

  str.clear();//string str vacio,, para asignacion en bucles
  cout<<str.empty();// 1,,,str vacio

  for (int i=0; i < str4.length(); i++){
    cout << str4[i]; cout<< str4.at(i);//cada caracter
  }
  str4+="++"; str4+='2';//concatenar string o char

  str2="Writing ";
  str3="print 10 and then 5 more";

  ////////////////////////////////////////////////////////
  str.append(str2);                       // str="Writing "
  str.append(str3,6,3);                   // "10 "
  cout<<endl<<"-----------> "<<str<<endl;
  str.append("dots are cool",5);          // "dots "
  str.append("here: ");                   // "here: "
  str.append(10,'.');                     // ".........."
  str.append(str3.begin()+8,str3.end());  // " and then 5 more"
  str.append<int>(5,0x2E);                // "....."

  string str8; string base="The quick brown fox jumps over a lazy dog.";
  str8.assign(base);//str8=base;
  str8.assign(base,10,9);// "brown fox"
  str8.assign("pangrams are cool",7);// "pangram"
  str8.assign("c-string");// "c-string"
  str8.assign(10,'*');// "**********"
  str8.assign<int>(10,0x2D);// "----------"
  str8.assign(base.begin()+16,base.end()-12);// "fox jumps over"
  /////////////////////////////////////////////////////////////
  str2.push_back('d');//añade d al final,,, solo char
  /////////////////////////////////////////////////////////////
  str.clear(); str="to be question";
  str2.clear(); str2="the ";
  str3.clear(); str3="or not to be";
  string::iterator it1;//sin los parentesis
  str.insert(6,str2);                 // to be (the )question
  str.insert(6,str3,3,4);             // to be (not )the question
  str.insert(10,"that is cool",8);    // to be not (that is )the question
  str.insert(10,"to be ");            // to be not (to be )that is the question
  str.insert(15,1,':');               // to be not to be(:) that is the question
  it1 = str.insert(str.begin()+5,','); // to be(,) not to be: that is the question
  str.insert (str.end(),3,'.');       // to be, not to be: that is the question(...)
  str.insert (it1+2,str3.begin(),str3.begin()+3); // (or )

  str.clear(); str="This is an example phrase."; string::iterator it2;
  str.erase (10,8);// "This is an phrase."
  it2=str.begin()+9; str.erase (it2);// "This is a phrase."
  str.erase (str.begin()+5, str.end()-7);// "This phrase."

  //////////////////////////////////////////////////////
  base.clear();base="this is a test string.";
  str2.clear();str2="n example";
  str3.clear();str3="sample phrase";
  str4.clear();str4="useful.";

  // Using positions:                 0123456789*123456789*12345
  str=base;                // "this is a test string."
  str.replace(9,5,str2);          // "this is an example string."
  str.replace(19,6,str3,7,6);     // "this is an example phrase."
  str.replace(8,10,"just all",6); // "this is just a phrase."
  str.replace(8,6,"a short");     // "this is a short phrase."
  str.replace(22,1,3,'!');        // "this is a short phrase!!!"

  // Using iterators:                      0123456789*123456789*
  it = str.begin();   //  ^
  str.replace(it,str.end()-3,str3);    // "sample phrase!!!"
  str.replace(it,it+6,"replace it",7); // "replace phrase!!!"
  it+=8;                               //          ^
  str.replace(it,it+6,"is cool");      // "replace is cool!!!"
  str.replace(it+4,str.end()-4,4,'o'); // "replace is cooool!!!"
  it+=3;                               //             ^
  str.replace(it,str.end(),str4.begin(),str4.end());// "replace is useful."
  ///////////////////////////////////////////////////
  size_t length; char buffer[20];
  string str9 ("Test string...");
  length=str9.copy(buffer,6,5);
  buffer[length]='\0';//buffer="string"
  ////////////////////////////////////////////////
  string s ("cad1");
  string t ("cad2");
  s.swap (t); //s=t , t=s
  ///////////////////////////////////////////////
  /////////////////////////////////////////////////
  //de  STRING a CHAR*
  char * cstr, *p;

  str.clear(); str="Please split this phrase into tokens";
  cstr = new char [str.size()+1];
  strcpy (cstr, str.c_str());
  delete[] cstr;

  ////////////////////////////////////////////////////
  //de  CHAR* a string
  char* a = "Fish"; string b;
  b =a;//b= "Fish"

  ///////////////////////////////////////////////////
  //compara STRING con CHAR*
  str.clear(); str = "Test string"; char* cstr1 = "Test string";
  if ( str.length() == strlen (cstr1)){
    cout << "str = cstr1";
    length = str.length();
    if ( memcmp (cstr1, str.data(), length ) == 0 )
      cout << "str != cstr1\n";
  }
  //////////////////////////////////////////////////
  str.get_allocator();//Returns the allocator object used to constuct the object.
  ///////////////////////////////////////////////////
  str.clear(); str="There are two needles in this haystack with needles.";
  str2.clear();str2 ="needle"; size_t found;
  found=str.find(str2);//encuentra la primera ocurrencia
  if (found!=string::npos)
    cout << "first 'needle' found at: " << int(found) << endl;//first 'needle' found at: 14
  found=str.find("needles are small",found+1,6);
  if (found!=string::npos)
    cout << "second 'needle' found at: " << int(found) << endl;//second 'needle' found at: 44
  found=str.find("haystack");
  if (found!=string::npos)
    cout << "'haystack' also found at: " << int(found) << endl;//'haystack' also found at: 30
  found=str.find('.');
  if (found!=string::npos)
    cout << "Period found at: " << int(found) << endl;//Period found at: 51
  str.replace(str.find(str2),str2.length(),"preposition");//str= There are two prepositions in this haystack with needles.
  /////////////////////////////////////////////////////////////
  str.clear(); str="The sixth sick sheik's sixth sheep's sick.";
  string key ("sixth"); size_t found0;
  found0=str.rfind(key);//encuentra la ultima ocurrencia
  if (found0!=string::npos)
    str.replace (found0,key.length(),"seventh");//str= The sixth sick sheik's seventh sheep's sick.
  ////////////////////////////////////////////////////////////
  str.clear(); str ="Replace the vowels in this sentence by asterisks."; size_t found1;
  found1=str.find_first_of("aeiou");//found1 guarda todas las posisiones en una cadena
  while (found1!=string::npos){//nesesita el bucle
    str[found1]='*';
    found1=str.find_first_of("aeiou",found1+1);
  }//str= R*pl*c* th* v*w*ls *n th*s s*nt*nc* by *st*r*sks.
  /////////////////////////////////////////////////////////////
  str2.clear(); str1="/usr/bin/man"; str2.clear(); str1 ="c:\\windows\\winhelp.exe";
  found=str1.find_last_of("/\\");
  cout << " folder: " << str1.substr(0,found) << endl;//c:\windows
  cout << " file: " << str1.substr(found+1) << endl;//winhelp.exe

  //////////////////////////////////////////////////////////////
  str="abcd...sfa2   "; found=str.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");
  if (found!=string::npos){
    cout << "First non-alphabetic character is " << str[found];//.
    cout << " at position " << int(found) << endl;//4
  }
  ///////////////////////////////////////////////////
  string whitespaces (" \t\f\v\n\r");//espacios
  found=str.find_last_not_of(whitespaces);//para eliminar espacios
  if (found!=string::npos)
    str.erase(found+1);
  else
    str.clear();            // str is all whitespace
  cout << '"' << str << '"' << endl;//"abcd...sfa2"
  ///////////////////////////////////////////////////
  str.clear(); str="We think in generalities, but we live in details.";
  str1.clear(); str2.clear();size_t pos;
  str2 = str.substr (12,12); // "generalities"
  pos = str.find("live");    // position of "live" in str
  str3 = str.substr (pos);   // get from "live" to the end
  cout << str2 << ' ' << str3 << endl;//generalities live in details.
  ////////////////////////////////////////////7
  str1.clear(); str1="green apple";
  str2.clear(); str2 ="red apple";
  if (str1.compare(str2) != 0) cout<<str1<<"!="<<str2;
  if (str1.compare(6,5,"apple") == 0) cout<<str1<< "is an apple\n";
  if (str2.compare(str2.size()-5,5,"apple") == 0) cout<<str2 <<"is also an apple\n";
  if (str1.compare(6,5,str2,4,5) == 0) cout << "ambas son apple\n";
  system("PAUSE");
  return 0;
}
