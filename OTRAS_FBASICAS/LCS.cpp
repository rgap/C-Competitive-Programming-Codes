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
#define MAXN 102
#define INF 12345678
int N;
int A[MAXN];
int B[MAXN];
int resp[MAXN][MAXN];
void LCS(void){
    //cout<<N;
    for(int i=1;i<=N;i++){
        //cout<<"a: "<<i<<endl;
        for(int j=1;j<=N;j++){

            if(B[i]==A[j]){
                resp[i][j]=resp[i-1][j-1]+1;
                //cout<<"b: "<<resp[i-1][j-1]+1<<endl;
            }
            else{
                resp[i][j]=max(resp[i-1][j],resp[i][j-1]);
                //cout<<"b: "<<resp[i-1][j-1]+1<<endl;
            }
        }
    }
    return;
}

int main(){
    //ifstream cin("LCS.in");
    string line;
    cin>>N;
    getline(cin,line);
    getline(cin,line);
    istringstream ss(line);
    int aux;
    for(int i=1;i<=N;i++){
        ss>>aux;
        A[aux]=i;
    }
    resp[0][0]=0;
        for(int i=1;i<=N;i++)
            resp[0][i]=resp[i][0]=0;
    getline(cin,line);
    while(!line.empty()){
        istringstream ss1(line);
        for(int i=1;i<=N;i++){
            ss1>>aux;
            B[aux]=i;
        }
        //cout<<B[2]<<" a"<<endl;
        LCS();
        cout<<resp[N][N]<<endl;
        getline(cin,line);
    }
}

