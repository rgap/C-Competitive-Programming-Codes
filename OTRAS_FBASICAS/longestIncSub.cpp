#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int X[]={10,2,3,8,11,4,5,4,5,19,7,1,20};
    int n=13;
    int L,M[n+1],P[n];
    int lo,hi,mi;

    L=0;
    M[0]=0;
    cout<<"!!!"<<endl;
    for(int i=0,j;i<n;i++){
        cout<<"----------"<<endl;
        lo=0; hi=L;

        while(lo!=hi){
            mi=(lo+hi+1)/2;
            cout<<"mi= "<<mi<<"     M[mi]= "<<M[mi]<<"     X[M[mi]]= "<<X[M[mi]]<<"     lo= "<<lo<<"     hi= "<<hi<<endl;

            if(X[M[mi]]<X[i]) lo=mi;
            else hi=mi-1;
        }


        j=lo;
        cout<<"j=  "<<j;
        P[i]=M[j];
        cout<<"     L_before= "<<L;
        if(j==L || X[i]<X[M[j+1]]){
            M[j+1]=i;
            L=max(L,j+1);
            cout<<"      ++++++++++++++++";
        }
        cout<<"     L_after= "<<L<<endl;
    }

    cout<<L<<endl;

    int a[L];

    for(int i=L-1,j=M[L];i>=0;i--){
        a[i]=X[j];
        j=P[j];
    }

    for(int i=0;i<L;i++) cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}
