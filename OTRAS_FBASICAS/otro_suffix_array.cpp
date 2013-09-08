/*
Alfonso2 Peterssen (mukel)
Simple suffix array -> O( n lg^2 n )
LCP -> O( n )
*/
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

#define REP( i, n ) for ( int i = 0; i < (n); i++ )

const int
	MAXN = 1 << 20;

int N, delta;
char S[MAXN];
int SA[MAXN];
int rank[MAXN];
int tmp[MAXN];
int LCP[MAXN];

bool comp( const int& i, const int& j ) {
	if ( rank[i] != rank[j] )
		return rank[i] < rank[j];
	if ( i + delta < N && j + delta < N )
		return rank[i + delta] < rank[j + delta];
	return i > j;
}

int main() {

	//ifstream cin("file.in");

	while(cin>>S&&S[0]!='*'){
	N = strlen( S );
	REP( i, N ) {
		SA[i] = i;
		rank[i] = S[i];
		cout<<SA[i]<<" ";
	}
	cout<<endl;
	for ( delta = 1; delta == 1 || tmp[N - 1] != N - 1; delta *= 2 ) {
		sort( SA, SA + N, comp );
		REP( i, N ) cout<< SA[i]<<" ";
		REP( i, N - 1 ) tmp[i + 1] = tmp[i] + comp( SA[i], SA[i + 1] );

		cout<<endl;
		REP( i, N ) rank[ SA[i] ] = tmp[i];
	}

	/*for ( int i = 0, k = 0; i < N; i++ ) {
		if ( rank[i] == N - 1 )
			continue;
		for ( int j = SA[ rank[i] + 1 ]; S[i + k] == S[j + k]; k++ );
		LCP[ rank[i] ] = k;
		if ( k > 0 ) k--;
	}*/

	/*REP( i, N )
	      printf( "%3d %s\n", LCP[i], S + SA[i] );*/
    REP( i, N ) printf( "%d ",SA[i] );
	REP( i, N )
	      printf( "%s\n", S + SA[i] );

    cout<<' '-'a'<<" "<<'a'-'a'<<endl;
	}
	return 0;
}
