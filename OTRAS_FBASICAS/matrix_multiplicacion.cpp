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
#define MAXN 20
#define INF 2147483647
int aux,N;
int A[MAXN];
int resp[MAXN][MAXN];
int track[MAXN][MAXN];
void print(int i, int j){
    if( i == j){
        cout<<"A"<<i; return;
    }

        cout<<"(";
        print( i, track[i][j]);
        cout<<" x ";
        print(track[i][j]+1,j);
        cout <<")";

}
void MM(void){
    for(int i=1; i<=N;i++){
        resp[i][i]=0;
        track[i][i]=-1;
        for(int j=i+1; j<=N;j++){
            resp[i][j]=INF;
            track[i][j]=-1;
        }
    }
    int j;
    for(int l=2; l<=N;l++){
        for(int i=1; i<=N-l+1;i++){
            j=i+l-1;
            resp[i][j]=INF;
            track[i][j]=-1;
            for(int k=i;k<j;k++){
                aux=resp[i][k]+resp[k+1][j]+A[i-1]*A[k]*A[j];
                if(aux<resp[i][j]){
                    resp[i][j]=aux;
                    track[i][j]=k;
                }
            }
        }
    }
    //cout<<resp[1][N]<<endl;
    print(1,N);
    cout<<endl;
    return;
}


int main(){
    //ifstream cin("MM.in");
    int cont=1;
    while(cin>>N&&N){
        cin>>A[0];
        for(int i=1;i<N;i++)
            cin>>A[i]>>A[i];
        cin>>A[N];
        cout<<"Case "<<cont++<<": ";

        MM();
    }
}



