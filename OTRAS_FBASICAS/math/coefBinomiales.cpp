
/* facts:
	pascal triangle:
      0  1  2  3  4  5  6  7  8  
      '	 |  |  |  |  |  |  |  | 
0 ->	1  '  |  |  |  |  |  |  | 
1 ->	1  1  '  |  |  |  |  |  | 
2 ->	1  2  1  '  |  |  |  |  | 
3 ->	1  3  3  1  '  |  |  |  | 
4 ->	1  4  6  4  1  '  |  |  | 
5 ->	1  5 10 10  5  1  '  |  | 
6 ->	1  6 15 20 15  6  1  '  | 
7 ->	1  7 21 35 35 21  7  1  '
8 ->	1  8 28 56 70 56 28  8  1

// the DP form
coef[i][0] = coef[i][i] = 1;
coef[i][j] = coef[i - 1][j] + coef[i - 1][j - 1]

// the equations: to be calculate need the modular inverse.
C(n , k) = C(n - 1, k - 1) * (n / k);   -> with C(n - k, 0) = 1;
C(n , k) = C(n - 1, k) * (n / ( n - k));  -> with C(n - (n - k), k) = 1;
C(n , k) = C(n , k - 1) *( (n - k + 1)  / k ); -> with C(n, 0) = 1; 	
*/


/////////////// Binomial coeficients - The DP formula  ////////////
const int MAXCOEF = 100;
int64 coef[MAXCOEF][MAXCOEF];
const int64 MOD = 10000000007ll;
void bincoef(int n ){
	forn(i, n + 1) coef[i][i] = coef[i][0] = 1;
	fore(i, 2, n + 1){
		for(int j = 1; j < i ; j++){
			coef[i][j] = (coef[i - 1][j] + coef [i - 1][ j - 1] ) % MOD;
		}
	}
}



/// it has to call the modular inverse to get the right calculation.
///////////// Binomial coeficients - the recursive formula ///////////

const int64 MOD = 1000000007ll;

int64 bigPow(int64 a, int64 b){
	int64 resp = 1;
	while(b){
		if(b & 1) resp = (resp * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return resp % MOD;
}
int64 inv(int64 x){
	return bigPow(x, MOD - 2);
}

int64 binCoefRec(int nn, int kk){
	if(nn == kk) return 1ll;
	if(kk == 0) return 1ll;
	int64 bin = (binCoefRec( nn - 1, kk - 1) * nn) % MOD ;
	int64 resp = (bin * inv(kk)) % MOD;
	return resp ; 
}
