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
#define INF 12345678
#define m_p(B,C) make_pair(B,C)
#define pb(A,D) (A).push_back(D)
typedef vector< pair<int ,int> > nodo;
int resp[MAXS][MAXS];
int add[MAXS][MAXS];
void FW(int num_nodos){
    for(int k=0;k<num_nodos;k++){
        for(int i=0;i<num_nodos;i++){
            for(int j=0;j<num_nodos;j++){
                resp[i][j]=min(resp[i][j],resp[i][k]+resp[k][j]);
            }
        }
    }
    return;
}
void FWadd(int num_nodos,int w,int u,int v){
    for(int i=1;i<=num_nodos;i++){
        for(int j=i+1;j<=num_nodos;j++){
            add[i][j]=min(resp[i][j],min(resp[i][u]+w+resp[v][j],resp[i][v]+w+resp[u][j]));//despues de un floyd cuando queremos aumentar una arista mas
        }
    }
}
void ini(int num_nodos){
    for(int i=0;i<num_nodos;i++){
        for(int j=i+1;j<num_nodos;j++){
            resp[i][j]=resp[j][i]=INF;
        }
    }

}
void print(int num_nodos){
    for(int i=0;i<num_nodos;i++){
        for(int j=0;j<num_nodos;j++){
            if(resp[i][j]>=INF)
                cout<<"~ ";
            else
                cout<<resp[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    //ifstream cin("DJ.in");
    //ofstream cout("DJ.out");
    return 0;
}


