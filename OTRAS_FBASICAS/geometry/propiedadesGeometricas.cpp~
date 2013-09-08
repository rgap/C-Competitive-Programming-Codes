//Propiedad un conjunto de puntos con respecto a una matriz
//Dado un conjunto  de n puntos y queremos saber a que linea pertenecen
//(linea verticar, horizontal o diagonal )
// una buena forma de tratarlos seria usando el siguiente algoritmo

const int MAX2S = 200005; // 2 * (tamanio maximo de la matriz);
const int MAXS = 100005; // (tamanio maximo de la matriz);
	vector<pair<int ,int > > r[MAX2S], c[MAX2S] , d1[MAX2S], d2[MAX2S];
	forn(i,n){ // n = numero puntos
			scanf ("%d%d", &u, &v);
    	r[u].pb ( mp(v,i) );
    	c[v].pb ( mp(u,i) );
    	d1[u-v+ MAXS].pb ( mp(u, i) );
    	d2[u+v].pb ( mp(u, i) );
	}

/***** Observaciones
* donde r[u] va a tener todos los puntos que pertenecen a la fila u;
* c[u] va a tener todos los puntos que pertenecen a la columna v;
* d2[u + v] va a tener todos los puntos que pertenezcan a la diagonal u + v
* d1[u - v + MAXS] va a tener todos los puntos que pertenezcan a la diagonal ...
 ... u - v + MAXS , aqui u - v puede salir negativo por eso se le anade MAXS
* En d1[u - v + MAXS] , MAXS puede ser reemplazado por el tamanio actual de la matriz
* 0 <= u, v < MAXS ,   0 <= u + v,  u - v + MAXS < MAX2S;
*/
