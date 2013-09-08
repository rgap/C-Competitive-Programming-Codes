
///////////////divisors of n//////////////////////////
VI divi;
void divisors(int n){
	divi.clear();
	int i = 0;
	for(i = 1; i * i < n; i++){
		if(n % i == 0) divi.pb(i), divi.pb(n / i);
	}
	if(i * i == n) divi.pb(i);
	return;
}
