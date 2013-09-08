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
#define MAXS 20
#define MAXM 100
#define INF 1234567
#define vi pair<int, int>
typedef vector<int> nodo;
typedef vector<string> message;
typedef pair<int,vi> origin;
int N,Q,tmp;

void bfs(nodo grafo[MAXS],int key,int *resp,bool *okay)
{
    queue <int> fifo;

    fifo.push(key);
    resp[key]=0;
    int t;
    while(!fifo.empty())
    {
        t=fifo.front();
        fifo.pop();
        int pp=0;
        //cout<<"front: "<<t<<endl;
        if(okay[t]==true)
        {
            resp[t]+=(grafo[t]).size();
            okay[t]=false;
        }
        else
            continue;
        for(int i=0;i<(grafo[t]).size();i++)
        {
            //'cout<<"aaa: "<<resp[(grafo[t])[i]]<<endl;

            if(resp[(grafo[t])[i]]==0)
            {
                fifo.push((grafo[t])[i]);
            }
        }


    }
    return;

}

int main()
{
    ifstream cin("spam.in");

    while(cin>>N&&N!=0)
    {
        nodo grafo[MAXS];
        message vectString[MAXM];
        origin vectInt[MAXM];
        vector <string> name;
        message solution[MAXM];
        int t;
        for(int i=0;i<N;i++){
            while(cin>>t &&t!=0)
                (grafo[i]).push_back(t-1);
        }

        Q=0;
        string A1,A2,A3;
        for(;;Q++){
            cin>>tmp;
            if(tmp!=0){
                vectInt[Q].first=tmp-1;
                cin>>vectInt[Q].second.first>>vectInt[Q].second.second>>A1>>A2>>A3;
                (vectString[Q]).push_back(A1);
                (vectString[Q]).push_back(A2);
                (vectString[Q]).push_back(A3);
            }
            else
                break;
        }
        //Q--;

        for(int i=0;i<N;i++){
            cin>>A1;
            name.push_back(A1);
        }

        int resp[N];
        bool okay[N];
        for(int j=0;j<Q;j++){

            fill(okay,okay+N,true);
            fill(resp,resp+N,0);
            bfs(grafo,vectInt[j].first,resp,okay);
            for(int i=0;i<N;i++){
                if(resp[i]<vectInt[j].second.first)
                    (solution[i]).push_back((vectString[j])[0]);
                else if(resp[i]>=vectInt[j].second.second)
                    (solution[i]).push_back((vectString[j])[2]);
                else
                    (solution[i]).push_back((vectString[j])[1]);
                //cout<<resp[i]<<endl;
            }
        }
        for(int i=0;i<N;i++)
        {
            cout<<name[i]<<": ";
            for(int k=0; k<Q;k++)
                cout<<(solution[i])[k]<<" ";
            //cout<<(solution[i])[Q-1]<<endl;
            cout<<endl;
        }

    }
    return 0;
}

