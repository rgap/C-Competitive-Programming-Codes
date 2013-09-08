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

typedef vector<int> nodo;

void bfs(nodo grafo[MAXS],int key,int *resp)
{
    queue <int> fifo;

    fifo.push(key);
    resp[key]=0;
    int t;
    while(!fifo.empty())
    {
        t=fifo.front();
        fifo.pop();
        //cout<<"front: "<<t<<endl;
        for(int i=0;i<(grafo[t]).size();i++)
        {
            //'cout<<"aaa: "<<resp[(grafo[t])[i]]<<endl;
            if(resp[(grafo[t])[i]]==INF)
            {
                resp[(grafo[t])[i]]=resp[t]+1;
                fifo.push((grafo[t])[i]);
            }
        }


    }
    return;

}

int main()
{
    nodo grafo[MAXS];
    //int tama[MAXS];

    int  num_nodos;
    cout<<"INgrese Num de nodos"<<endl;
    cin>>num_nodos;
//    fill(tama,tama+num_nodos,0);
    int t;
    for(int i=0;i<num_nodos;i++)
    {
        cout<<"Ingrese nodos asociados al nodo: "<<i<<"    (teclee -1 pa salir)"<<endl;
        while(cin>>t &&t!=-1)
        {
            (grafo[i]).push_back(t);
            //tama[i]++;
        }
    }
    int resp[num_nodos];
    fill(resp,resp+num_nodos,INF);
    bfs(grafo,0,resp);
    for(int i=0;i<num_nodos;i++)
    {
        cout<<resp[i]<<endl;
    }
    return 0;
}

