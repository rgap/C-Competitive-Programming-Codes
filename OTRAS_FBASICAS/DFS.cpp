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
#define I64 (int64)
#define LD (long double)
#define VI vector<int>
#define iss istringstream //>>
#define MAX 3100

const long double EPS = 1E-8;
const int INF = 6000;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

int visited[MAX];
VI gr[MAX];
VI grR[MAX];
int pre[MAX];
int pos[MAX];
int cc=0;
VI sol;

//simple DFS
void dfs(int sp){
    cout<<"Nodo: "<<(char)('A'+sp)<<endl;
    visited[sp]=true;
    //pre[sp]=cont++;
    forn(i,sz(gr[sp])){
         if(!visited[gr[sp][i]]) dfs(gr[sp][i]);
    }
    //pos[sp]=cont++;
}

//topological sort
void ts(int sp){
    cout<<"Nodo: "<<(char)('A'+sp)<<endl;
    visited[sp]=true;
    forn(i,sz(gr[sp])){
         if(!visited[gr[sp][i]]) ts(gr[sp][i]);
    }
    sol.pb(sp); // puede de frente imprimirse si se toma el grafo inverso
}

// para scc
void dfsR(int sp){
    //cout<<"Nodo: "<<(char)('A'+sp)<<endl;
    visited[sp]=true;
    //pre[sp]=cont++;
    forn(i,sz(grR[sp])){
         if(!visited[grR[sp][i]]) dfsR(grR[sp][i]);
    }
    sol.pb(sp);
}
void dfs2(int sp){
    //cout<<"Nodo: "<<(char)('A'+sp)<<" "<<cont<<endl;
    visited[sp]=true;
    pre[sp]=cc;
    forn(i,sz(gr[sp])){
         if(!visited[gr[sp][i]]) dfs2(gr[sp][i]);
    }
}
void scc(int N){
    fill(visited,visited+N,0 );
    forn(i,N) if(!visited[i]) dfsR(i);
    fill(visited,visited+N,0 );
    fill(pre,pre+N,0 );
    cc=0;
    forn(i,N) if(!visited[sol[N-1-i]]){ dfs2(sol[N-1-i]);cc++;}
    forn(i,N) cout<<(char)('A'+sol[N-1-i])<<" -> "<<pre[sol[N-1-i]]<<endl;
}
int main(){
    ifstream cin("dfs.in");
    int N,u,v;
    cin>>N;
    forn(i,N){
        pre[i]=pos[i]=-1;
        visited[i]=false;
    }
    forn(i,N){
        cin>>u;
        forn(j,u){cin>>v; grR[v].pb(i); gr[i].pb(v);}
    }
    scc(N);
    /*forn(i,N) if(!visited[i]) dfs(i);
    forn(i,N) cout<<i<<" -> "<<pre[i]<<" "<<pos[i]<<endl;
    forn(i,N) cout<<(char)('A'+sol[N-1-i])<<endl;*/
}
