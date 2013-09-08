

// it works when MOD is a prime number, the formula is  (b / a) % MOD == (b * (a ^ (MOD - 2))) % MOD;
// this holds because the fermat theorem.

/////////////////Modular Inverse ////////////

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
int64 inv(int64 x){
	return bigPow(x, MOD - 2);
}
