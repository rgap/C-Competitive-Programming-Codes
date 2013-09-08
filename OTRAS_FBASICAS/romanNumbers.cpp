//PROG: numeros romanos 
string rom[4][3]= {{"I","V","X"},{"X","L","C"},{"C","D","M"},{"M","M","M"} };
string toNR(int dec){
	string h="";
	int cont=0, w=dec;
	while(w>0){
		int i=w%10;
		w/=10;
		if(i<4) forn(j, i)  h.insert(0,rom[cont][0]);
		else if(i==4) { h.insert(0,rom[cont][1]); h.insert(0,rom[cont][0]); }
		else if(i==5){ h.insert(0,rom[cont][1]); }
		else if(i<9){
			forn(j, i-5)  h.insert(0,rom[cont][0]);
			h.insert(0,rom[cont][1]);
		}
		else if(i==9){  h.insert(0,rom[cont][2]); h.insert(0,rom[cont][0]); }
		cont++;
	}
	return h;
}
