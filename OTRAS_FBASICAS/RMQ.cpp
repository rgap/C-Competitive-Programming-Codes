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


// RMQ y LCA y shotest path con RMQ en DAG
#define MAX 100010

const long double EPS = 1E-9;
const int INF = (int)1<<30;
PII gr[MAX];// el arbol que se quiere transformar
int N, aux,w,u,v,Q; //N: numero de nodos
int64 dcost[MAX];// dcost[i]: tiene el costo de ir de un nodo inicial al nodo i

int depth[2*MAX+1]; // depth[i]: es la profundidad de ir del nodo inicial al nodo i
int seq[2*MAX+1]; // seq[i]: tiene el nodo que hay en la posicion i
//NOTE que esto significa que en la posicion i se encuentra el seq[i] de profundidad depth[i]
int r[MAX]; //r[i]: guarda la primera posicion donde se encuentra el nodo i en el array seq
int M[2][450]; // M[0][i]: tiene el valor minimo de un intervalo definido en depth
//                M[1][i]: tiene la posición del valor minimo dentro del mismo intervalo en depth
int gra, part, ind; // gra: es 2*N+1 elementos ,  part: numero de particiones

//Usara: gra(el numero de nodos), depth(definido arriba),
//return: implicitamente retorna M(tabla donde se encuentra las posiciones y los valores de los elementos
//        minimos que hay en los sqrt(gra)+1 intervalos que hay en depth) y part  q son el numero de particiones
//         a depth que se haran
//tiempo de ejecucion: O(n)
void precalculo() {
    ind =0;
    part=(int)(sqrt(gra)+EPS);
    int i=0,j=0, mini=INF ,pos=-1;
    for(; i<gra;) {
        mini=INF;
        for(j=i; (j-i)<part && j<gra; j++) {
            if(mini>depth[j]) {
                mini=depth[j];
                pos=j;
            }
        }
        M[0][ind]=mini;
        M[1][ind++]=pos;
        i=j;
    }
    return;
}

//parametros: el intervalo [x,y] donde se buscará el menor elemento
//usará: la tabla M creada y el #de partes en que esta dividido el array depth dada en la funcion precalculo,
//       y el array depth (donde estan los elementos a buscar el minimo)
//return; un entero que indicara la posición del menor elemmento en el intervalo dado
//Note: porsiacaso se hace se saca el min(x,y) y max(x,y) por si nos dan un intervalo donde x es mayor que y
//tiempo de ejecucion O(sqrt(N)) .... N:numero de elementos en el array a buscar
int64 RMQ_basico(int x, int y) {
    int dirx=x, diry=y;
    if(x>y){ dirx=y; diry=x;}
    int ix=dirx/part , iy=diry/part;
    int ww=INF;
    int pos=-1;
    fore(i,ix+1,iy) {
        if(ww>M[0][i]) {
            pos=M[1][i];
            ww=M[0][i];
        }
    }
    if(ix!=iy) {
        for(int i=dirx; i<(ix+1)*part && i<gra; i++) {
            if(ww>depth[i]) {
                pos=i;
                ww=depth[i];
            }
        }
        for(int i=(iy)*part; i<=diry &&i<gra; i++) {
            if(ww>depth[i]) {
                pos=i;
                ww=depth[i];
            }
        }
    }else{
        for(int i=dirx; i<=diry && i<gra; i++) {
            if(ww>depth[i]) {
                pos=i;
                ww=depth[i];
            }
        }
    }
    return pos;
}

//Este dfs lo que hace es transformar un arbol a un array, para que se pueda tranaformar el probelma del LCA a RMQ
// ademas de paso calcula el shortest path del nodo inicial a los demas
//parametros: i(pa posición del arbol en que estamos), parent(el padre de i), cost(es el costo actual de ir de un nodo inicial hasta i)
//            prof(es la profundidad de ir de un nodo inicial hasta i)
//return: depth(array de gra=2*N+1 elementos que son la profundidad de ir del nodo inicial a los demas),
//         seq(array que contiene la misma cantidad de elementos que depth y son la secuencia de nodos que recorre el dfs)
//         r(tiene N elementos donde el r[i] es la primera posicion en que aparece el nodo i en seq)
//         dcost(dcost[i]: costo de ir del nodo inicial a el nodo i)
void dfs( int i,int parent, int64 cost, int prof) {
    r[i]=min(r[i],gra);
    depth[gra]=prof;
    seq[gra++]=i;
    dcost[i]=cost;
    forn(j, sz(gr[i]))
    if(gr[i][j].fs!=parent) {
        dfs(gr[i][j].fs,i, cost+gr[i][j].sc, prof+1);
        depth[gra]=prof;
        seq[gra++]=i;
    }
    return;
}
int main() {
    ifstream cin("C.in");
    ofstream cout("C.out");
    while(cin>>N && N) {
        gra=0;
        r[0]=INF;
        forn(i, N-1) {
            cin>>aux>>w;
            gr[i+1].pb(mp(aux,w));
            gr[aux].pb(mp(i+1,w));
            r[i+1]=INF;
        }
        dfs(0,-1,0,0);
        precalculo();
        cin>>Q;
        forn(i,Q) {
            cin>>u>>v;
            if(i!=0) cout<<" ";
            cout<<dcost[seq[r[u]]]+dcost[seq[r[v]]]-2*(dcost[seq[RMQ_basico(r[u],r[v])]]);
        }
        cout<<endl;
        forn(i, N) gr[i].clear();
    }
    return 0;
}
