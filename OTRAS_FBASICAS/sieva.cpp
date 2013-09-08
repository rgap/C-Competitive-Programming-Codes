bool tp[MAX]; // tp[i]=true if i==primo else tp[i]=false.. excepto para #pares
VI pri; //guarda todos los primos 
void sieva(){
	fill(tp,tp+MAX,1);
	pri.pb(2);
	for(int i =3;i<sqrt(MAX);i+=2){
		if(tp[i]){
			int k=i*i;
			while(k<MAX){
				tp[k]=0;
				k+=i;
			}
		}
	}
	for(int i =3;i<=MAX;i+=2) if(tp[i]) pri.pb(i);
	//forn(i,sz(pri)) cout<<pri[i]<<endl;
	return ;
}
