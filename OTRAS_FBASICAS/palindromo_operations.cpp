int B;
string toP(int N){
	string h="",w="",q="";
	while(N>0){
		int r=N%B;
		w="";
		q="";
		w+=('0'+r);
		q+=('A'+(r-10));
		if(r<10) h.insert(0,w);
		else h.insert(0, q);
		N/=B;	
	}
	return h;
}
bool isP(string h){
	int y=sz(h)/2;
	int u=sz(h)-1;
	forn(i,y){
		if(h[i]!=h[u]) return 0;
		u--;
	}
	return 1;
}
