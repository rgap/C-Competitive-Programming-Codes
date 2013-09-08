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

using namespace std;
#define MAXL 101
typedef pair<int, char> vi;
typedef pair<char, char> vis;
vi dist[MAXL][MAXL];
vector< pair<vis , int> > resp;
char oper[MAXL][MAXL];


int leven_dist(string init, string goal)
{
    /*for(int i=0; i< MAXL ;i++)
        fill(oper[i],oper[i]+MAXL,'-');*/
    int m=init.length();
    int n=goal.length();
    for(int i=0;i<=max(m,n);i++)
    {
        (dist[0][i]).first=i; //deletion
        (dist[i][0]).first=i; //insertion
        (dist[0][i]).second='D';
        (dist[i][0]).second='I';
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(init[j-1]==goal[i-1])
            {
                (dist[i][j]).first=(dist[i-1][j-1]).first;
                (dist[i][j]).second='-';
                //cout<<(dist[i][j]).second<<" ";
            }
            else
            {
                if((dist[i][j-1]).first+1 < (dist[i-1][j]).first+1)
                {
                    (dist[i][j]).first=(dist[i][j-1]).first+1;
                    (dist[i][j]).second='D';
                }
                else
                {
                    (dist[i][j]).first=(dist[i-1][j]).first+1;
                    (dist[i][j]).second='I';
                }
                if((dist[i-1][j-1]).first+1<(dist[i][j]).first)
                {
                    (dist[i][j]).first=(dist[i-1][j-1]).first+1;
                    (dist[i][j]).second='C';
                }
                //cout<<(dist[i][j]).second<<" ";
            }
        }
        //cout<<endl;
    }

    return (dist[n][m]).first;
}
void Print(string init, string goal)
{
    resp.clear();
    int m=init.length();
    int n=goal.length();
    while((dist[n][m]).first!=0)
    {
        if((dist[n][m]).second=='-')
        {
            m--;
            n--;
        }else
        {
            int y=0 , z=0;
            //cout<<(dist[n][m]).second<<goal[n-1]<<"   m= "<<m<<endl;
            pair <vis , int> pa;
            pa.first.first=(dist[n][m]).second;
            pa.first.second=goal[n-1];
            pa.second=m;
            resp.push_back(pa);
            if((dist[n][m]).second=='C' || (dist[n][m]).second=='I')
                y=1;
            if((dist[n][m]).second=='C' || (dist[n][m]).second=='D')
                z=1;
            n-=y;
            m-=z;
        }
    }
    //cout<<endl;
    int t=0;
    for(int i=resp.size()-1;i>=0;i--)
    {
        int temp=0;
        cout<<resp[i].first.first;
        switch(resp[i].first.first)
        {
            case 'C':
            {
                cout<<resp[i].first.second;
                break;
            }
            case 'D':
            {
                cout<<init[resp[i].second-1];
                temp=-1;
                break;
            }
            case 'I':
            {
                cout<<resp[i].first.second;
                t++;
                temp=0;
                break;
            }
        }
        if((resp[i].second+t<10))
            cout<<"0"<<resp[i].second+t;
        else
            cout<<resp[i].second+t;
        //cout<<"t= "<<t<<endl;
        t=t+temp;


    }
    cout<<"E"<<endl;

    return;
}

int main()
{
    string A,B;
    cin>>A;
    while(A[0]!='#')
    {
        cin>>B;
        int t=leven_dist(A,B);
        int y;

        //cout<<t<<endl;
        Print(A,B);

        cin>>A;
    }
    return 0;
}
