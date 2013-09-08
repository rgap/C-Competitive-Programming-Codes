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
 
#include <sstream>
#include <iostream>
#include <iomanip>
 
using namespace std;
 
typedef long long int64;
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
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
 
const long double EPS = 1E-9;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

long long m[100];
long long catalan(int n){
	m[0]=m[1]=1;
	for(int i=2;i<=n;i++){
		forn(j,i){
			m[i]+=(m[j]*m[(i-1)-j]);
		}
	}
	return m[n];
}
