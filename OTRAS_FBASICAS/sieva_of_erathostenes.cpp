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
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()
#define I (int)
#define I64 (int64)
#define LD (long double)
#define VI vector<int>
#define iss istringstream //>>
#define MAX 3100 

const long double EPS = 1E-8;
const int INF = 6000;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

bool tp[MAX];
VI pri;
void sieva(){
  //ifstream cin("c.in");
  fill(tp,tp+MAX,1);
  pri.pb(2);
  for(int i =3;i<sqrt(MAX);i+=2){
      if(tp[i]){
	int k=i*i;
	while(k<MAX){
	    tp[k]=0;
	    k+=i;
	}
      }
  }
  for(int i =3;i<=MAX;i+=2) if(tp[i]) pri.pb(i);
  forn(i,sz(pri)) cout<<pri[i]<<endl;
   
  return ;
}
int main(){
    sieva();
}