//extended euclidean algorithm
/* retorna 'x' e 'y' en la ecuacion ax+by=gcd(a,b)
esta es conocido como 'Bézout's identity' donde el gcd es el minimo valor
positivo que puede tomar la combinacion lineal de la izquierda, es muy
util cuando a y b son coprimos(gcd(a,b)=1).
*/
pair<int, int> e_gcd(int a, int b){
	if(a%b == 0)	return mp(0, 1); 
	pair<int , int> xy= e_gcd(b, a%b);
	return mp(xy.sc, xy.fs-(xy.sc*(a/b)));
}
