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
#define MAX 1000004;

const long double EPS = 1E-8;
const int INF = 6000;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

int64 gcd(int64 a, int64 b){
  if(b==0) return a;
  return gcd(b,a%b);
}
int64 gcd(vector<int64> pp){
  int64 y=pp[0];
  forn(i,sz(pp)-1) y=gcd(pp[i+1],y);
  return y;
}
int64 lcm(vector<int64> pp){
  int64 y=pp[0];
  forn(i,sz(pp)-1) y=y*(pp[i+1]/gcd(pp[i+1],y));
  return y;
}

int main(){
  int a,b;
  /*cin>>a>>b;
  cout<<gcd(a,b)<<endl;*/
  cin>>a;
  vector<int64> pp;
  forn(i,a){
    cin>>b;
    pp.pb(b);
  }
  cout<<lcm(pp)<<endl;
  return 0;
}
