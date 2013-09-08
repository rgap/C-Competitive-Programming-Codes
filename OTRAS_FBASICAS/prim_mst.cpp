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
typedef vector< pair<int ,int> > nodo;
bool deck[MAXS];
int resp[MAXS];
void PR(nodo grafo[MAXS],int num_nodos,int key)
{
    fill(resp,resp+num_nodos,INF);
    fill(deck,deck+num_nodos,true);
    resp[key]=0;
    priority_queue < pair<int ,int> > heap;
    int s;
    heap.push( make_pair(-resp[key], key) );
    while(!heap.empty()){
        s = heap.top().second;
        heap.pop();
        if(!deck[s])
            continue;
        deck[s]=false;
        for(int i=0;i<(grafo[s]).size();i++){
            if(resp[(grafo[s])[i].first]>(grafo[s])[i].second&&deck[(grafo[s])[i].first]){
                resp[(grafo[s])[i].first]=(grafo[s])[i].second;
                heap.push(make_pair(-resp[(grafo[s])[i].first],(grafo[s])[i].first));
            }
        }

    }
    return;
}

int main()
{
    ifstream cin("PR.in");
    //ofstream cout("DJ.out");
    nodo grafo[MAXS];

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
            (grafo[i]).push_back(edge);
        }
    }

    PR(grafo,num_nodos,5);
    for(int i=0;i<num_nodos;i++)
    {
        cout<<resp[i]<<endl;
    }
    return 0;
}

