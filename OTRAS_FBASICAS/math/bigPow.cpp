

// it works with bits
///// Big Pow/////
const int64 MOD = 1000000007;

int64 bigPow(int64 a, int64 b){
	int64 resp = 1;
	while(b){
		if(b & 1) resp = (resp * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return resp % MOD;
}
