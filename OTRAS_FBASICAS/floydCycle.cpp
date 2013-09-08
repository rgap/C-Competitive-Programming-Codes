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
int Z,I,M,L;
int f(int a){
    return (a*Z+I)%M;
}

int FC(int seed){
    int tor=f(seed), hare=f(f(seed));
    while(tor != hare){
        tor = f(tor);
        hare = f(f(hare));
    }

    int sol=tor;
    tor=f(tor);
    int cont=1;
    while(tor!=sol){
        tor=f(tor);
        cont++;
    }
    return cont;
}


int main()
{
    //ifstream cin("FC.in");
    int cont=1;
    while(cin>>Z>>I>>M>>L && (Z||I||M||L)){
        cout<<"Case "<<cont++<<": "<< FC(L)<<endl;
    }
    return 0;
}


