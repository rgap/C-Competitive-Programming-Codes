#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <list>
#include <string>
#include <sstream>
#include <queue>

using namespace std;
#define MAXS 500
#define INF 1234567
#define m_p(B,C) make_pair(B,C)
#define pb(A,D) (A).push_back(D)
typedef vector< pair<pair<int ,int>, int>  > nodo;
typedef vector<int> clave;
int ciclo[MAXS];
nodo resp;

bool cmp(pair<pair<int ,int>, int> A,pair<pair<int ,int>, int> B){
    return A.second<B.second;
}
void KR(nodo grafo,int num_nodos){
    clave lista[MAXS];
    for(int i=0; i<num_nodos;i++){
        lista[i].push_back(i);
        ciclo[i]=i;
    }
    resp.clear();
    sort(grafo.begin(),grafo.end(),cmp);
    int W,ini,fin,maxi,mini;
    int cont=0;
    while(resp.size()<num_nodos-1){
        W=grafo[cont].second;
        ini=grafo[cont].first.first;
        fin=grafo[cont].first.second;
        cont++;
        //cout<<" ss"<<cont-1<<"   W: "<<W<<"  ini: "<<ini<<"   fin: "<<fin<<"   C[I]: "<<ciclo[ini]<<"   C[F]: "<<ciclo[fin]<<endl;
        if(ciclo[ini]==ciclo[fin])
            continue;
        resp.push_back(grafo[cont-1]);

        if(lista[ciclo[ini]].size()<=lista[ciclo[fin]].size()){
            mini=ciclo[ini];
            maxi=ciclo[fin];
        }
        else{
            mini=ciclo[fin];
            maxi=ciclo[ini];
        }
        for(int i=0;i<lista[mini].size();i++){
            lista[maxi].push_back(lista[mini][i]);
            ciclo[lista[mini][i]]=maxi;
        }
        lista[mini].clear();
    }
    return;
}

int main()
{
    ifstream cin("PR.in");
    //ofstream cout("DJ.out");
    nodo grafo;

    int  num_nodos;
    cout<<"INgrese Num de nodos"<<endl;
    cin>>num_nodos;
    pair<int ,int> edge;
    for(int i=0;i<num_nodos;i++)
    {
        cout<<"Ingrese nodos asociados al nodo : "<<i<<"  y peso de la arista que los une  (teclee -1 pa salir)"<<endl;
        while(cin>>edge.first &&edge.first!=-1)
        {
            cin>>edge.second;
            grafo.push_back(m_p(m_p(i,edge.first),edge.second));
        }
    }
    KR(grafo,num_nodos);
    for(int i=0;i<num_nodos-1;i++)
    {
        cout<<resp[i].second<<endl;
    }
    return 0;
}

