//permutaciones con sets
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
#define mod 1234567891
const long double EPS = 1E-9;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

class TheCardLineDivTwo {
public:
	int count(vector <string>);
};
int64 dp[1<<16][14][2];
//black --0 . red --1;
int val[200];
int TheCardLineDivTwo::count(vector <string> ca) {
	fore(i,2,10 ) val['0'+i]=i;
	memset(dp,0,sizeof(dp));
	val['T']=10;
	val['J']=11;
	val['Q']=12;
	val['K']=13;
	val['A']=1;
	val['D'] =val['H']=1;
	val['C'] =val['S']=0;
	forn(i,sz(ca)) dp[1<<i][val[ca[i][0]]][val[ca[i][1]]]=1;
	fore(i,1,1<<sz(ca)){
		forn(l,sz(ca)){
			if(!(i&(1<<l))){
				fore(j,1,14){
					forn(k,2){
							if((i+(1<<l)) >=(1<<sz(ca)) ) continue;
							if(val[ca[l][0]]==j || val[ca[l][1]]==k) dp[i+(1<<l)][val[ca[l][0]]][val[ca[l][1]]]+=dp[i][j][k]%mod;
					}
				}
			}
		}
		
	}
	int64 cont =0;
	forn(i,14) forn(j,2) cont=(cont+dp[(1<<sz(ca))-1][i][j])%mod;
	return (int)(cont%mod);
}



