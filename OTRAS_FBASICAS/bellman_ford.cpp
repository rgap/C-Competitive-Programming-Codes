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
typedef vector< pair<pair<int ,int> ,int> > nodo;
int resp[MAXS];
bool centi;
bool BF(nodo grafo,int num_nodos,int key){
    fill(resp,resp+num_nodos,INF);//changevable if start in 1
    resp[key]=0;
    centi=true;
    for(int i=0;(i<num_nodos-1&&centi);i++){
        centi=false;
        for(int j=0;j<grafo.size();j++){
            if(resp[grafo[j].first.second] > resp[grafo[j].first.first] +grafo[j].second){
                resp[grafo[j].first.second] = resp[grafo[j].first.first] +grafo[j].second;
                centi=true;
            }
        }
    }
    for(int j=0;j<grafo.size();j++){
        if(resp[grafo[j].first.second] > resp[grafo[j].first.first] +grafo[j].second)
            return false;
    }
    return true;
}

int main(){
    ifstream cin("BF.in");
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
    if(BF(grafo,num_nodos,0)){
        for(int i=0;i<num_nodos;i++){
            cout<<resp[i]<<endl;
        }
    }
    else
        cout<<"ciclo negativo grrr!"<<endl;
    return 0;
}
