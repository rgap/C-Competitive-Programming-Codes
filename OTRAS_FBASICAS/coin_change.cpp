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
#define MAXN 6001
#define MAXS 13
#define INF 12345678
int aux;
int A[MAXN];
int B[MAXN];
long long int resp[MAXN][MAXS];
int coins[12]={0,1,2,4,10,20,40,100,200,400,1000,2000};
void coinChange(void){
    for(int i=1;i<MAXS;i++)
        resp[1][i]=resp[0][i]=1;
    for(int i=1;i<=MAXN;i++)
        resp[i][1]=1;
    for(int i=2;i<MAXN;i++){
        for(int j=2;j<MAXS;j++){
            if((i-coins[j])<0)
                resp[i][j]=resp[i][j-1];
            else
                resp[i][j]=resp[i][j-1]+resp[i-coins[j]][j];
        }
    }

    return;
}

int main(){
    //ifstream cin("CC.in");
    float num;
    int N;
    coinChange();
    while(scanf("%f",&num)&&(N=round(num*20))!=0){
        //N=round(num*20);
        printf("%6.2f%17lli\n",num,resp[N][12]);

    }
}


