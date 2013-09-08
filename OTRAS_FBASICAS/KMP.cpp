#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>

#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <fstream>

#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define fore(i, a, n) for(int i = a; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) (a).size()
#define all(a) a.begin(), a.end()
#define LD (long double)
#define VI vector<int>
#define PII vector<pair<int,int> >
#define iss istringstream //>>
#define MAX 1000

const long double EPS = 1E-9;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

// KMP: Knuth-Morris-Pratt Algorithm -------> string matching y mucho mas!
/*
 * crea una tabla que luego se usara para hacer los shift por el KMP,
 * todo se guarda en el array F,
*/
int F[MAX];// AQUI SE guarda el precalculo
//pat: es el pattern
void KMP_failure(string pat){
    int pos=2, cnd=0;
    F[0]=-1;
    F[1]=0; // de length = 1;
    while(pos<=sz(pat)){
        if(pat[pos-1]==pat[cnd]){
            cnd++;
            F[pos]=cnd;
            pos++;
        }else if(cnd>0) cnd=F[cnd];
        else{
            F[pos]=0;
            pos++;
        }
    }
    forn(i, sz(pat)) cout<<F[i+1]<<" ";
    cout<<endl;
    forn(i, sz(pat)) cout<<pat[i]<<" ";
    cout<<endl;
    return;
}
bool KMP(string text,string pattern){
  // let n be the size of the text, m the
  // size of the pattern, and F[] - the
  // "failure function"

  KMP_failure(pattern);
  int i = 0; // the initial state of the automaton is
         // the empty string
  int j = 0; // the first character of the text
  for( ; ; ) {
    if(j == sz(text)) break;// se encontro que no hay ningun match, ps se alcanzo el final del texto
    if(text[j] == pattern[i]) {
      i++; // change the state of the automaton
      j++; // get the next character from the text
      if(i == sz(pattern)) return 1;// match found
    } else if(i > 0) i = F[i]; /* if the current state is not zero (we have not reached the empty string yet) we try to "expand" the next best (largest) match*/
    else j++;
  }
  return 0;
}

int main(){
    ifstream cin("KMP.in");
    string tex, pat;
    cin>>tex>>pat;
    cout<<KMP(tex, pat)<<endl;
    return 0;
}
