//gcd - lcm!

int64 gcd(int64 x, int64 y){
	if(y==0) return x;
	else return gcd(y,x%y);
}
int64 gcd(vector<int64> vec){
	int64 resp=vec[0];
	forn(i,sz(vec)-1) resp=gcd(resp, vec[i+1]);
	return resp;
}
int64 lcm(vector<int64> pp){
  int64 y=pp[0];
  forn(i,sz(pp)-1) y=y*(pp[i+1]/gcd(pp[i+1],y));
  return y;
}
