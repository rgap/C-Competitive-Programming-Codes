#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <cstring>
 
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <list>
 
#include <sstream>
#include <iostream>
#include <iomanip>
 
using namespace std;
 
typedef long long int64;
 
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define fore(i, a, n) for(int i = a; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) (a).size()
#define all(a) a.begin(), a.end()
#define LD (long double)
#define VI vector<int>
#define iss istringstream //>>
#define MAX 100005
 
const long double EPS = 1E-9;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);


/*INPUT:
  x: entero que simboliza un array ordenado de elementos que va desde 1 .. x
	k: La kth permutacion que queremos sacar.
OUTPUT:
	vector<int> donde se encuentra almacenado la k-esima permitacion
RESTRICCIONES:
  solo funciona hasta un MAXPERM = 19 como maximo. y un k <= 19! (factorial de 19).
LOGICA:	
	Si tenemos x = 4 elementos 1 2 3 4 y queremos sacar el elemento k = 15,
1	primero sacamos factorial hasta el 4, asi tendremos:
	- fact[0] = 1, fact[1] =1, fact[2] = 2, fact[3] = 6, fact[4] = 24
2	luego verificamos que la kth permutacion sea menor que el # total de permutaciones, 
	si no fuera asi, devolveriamos el	vector vacio
	- 15 < fact[4]? => 15 < 24? , entonces si cumple,
3 para calcular el 1er elemento de la kth permutacion, notar que tendremos
	fact[x - 1] permutaciones que comiencen con 1, fact[x - 1] permutaciones que comiencen con 2
	y asi sucesivamente:
	- 1 234 , 1 243, 1 324, 1 342, 1 423, 1 432  ... fact[x - 1] = fact[4 - 1] = 6 permutaciones
	- 2 134,  2 143, 2 314, 2 341, 2 413, 2 431
	- 3 124, ..... and so on....
4 entonces para calcular el primer elemento simplemente iteramos mientra se cumpla que
  k > m * fact[x - 1]	, donde  1 <= m <= x, una ves que ya no se cumpla esto, escogemos 
  el elemento m que ya no haga cumplir esta condicion.
  - 15 > 1 * fact[4 - 1]? => 15 > 6 , si cumple.. seguimos.
  - 15 > 2 * fact[4 - 1]? => 15 > 12, si cumple.. seguimos.
  - 15 > 3 * fact[4 - 1]? => 15 > 18, NO cumple.. entonces elegimos 3 como primer elemento 
  - de la kth permutacion
5 Ahora podemos extender la observacion del paso 3 , para el 2do elemento donde ahora habrian
	fact[x - 2] permutaciones que empiecen con 1, fact[x - 2] , permutaciones que empiecen con 2, etc
	el paso 4 cambiaria un poco en el sentido que ya no elegiriamos m como el proximo kth elemento ya 
	podria darse que ya haya sido utilizado previamente, es por eso que en el codigo hacemos uso de
	bool used[MAXPERM], para llevar traza de los elementos que hayan sido utilizados.
	repetimos este mismo procedimiento para el 3er elemento el 4th hasta haber finalizado de sacar
	la kth permutacion.
	* PARA el 2DO ELEMENTO.
	- 15 - 12 > 1 * fact[4 - 2] => 3 > 2, si cumple .. seguimos // notar que decimos 15 - 12 debido a
																									 que en el paso anterior nos quedamos en ese numero
	- 15 - 12 > 2 * fact[4 - 2] => 3 > 4, No cumple .. entonces elegimos 2, como segundo elemento.
	                                                   ya que este num no fue elegido anteriormente.
	* PARA EL 3ER ELEMENTO
	- 15 - 14 > 1 * fact[4 - 3] => 1 > 1, No cumple .. entonces elegimos 1, como 3er element0
	                                                   ya que este num no fue elegido anteriormente.
	* PARA EL 4TO ELEMENTO
	- 15 - 14 > 1 * fact[4 - 4] => 1 > 1, No cumple .. pero no podemos elegir 1, porque ya fue elegido
																										previamente , tampoco 2 ni 3, solo nos queda 4
																								ya que es el mas proximo a m = 1 que no fue elegido.
																								
  * Por lo que para este ejemplo la 15th permutacion seria:  3 2 1 4
*/ 
const int MAXPERM = 19; // maximo numero de digitos para permutacion
vector<int> kthPerm(int x, int64 k){
	int64 fact[MAXPERM], base = 0;
	bool used[MAXPERM];
	vector<int> resp ;
	fact[0] = fact[1] = 1;
	for(int i = 2; i <= x ; i++) fact[i] = i * fact[i - 1];
	for(int i = 0; i <= x ; i++) used[i] = 0;
	if(fact[x] < k) return resp;
	for(int i = 0 ; i < x ; i ++){
		int64 rad = fact[x - i - 1];
		for(int j = 1; i <= x ; j ++){
			if(used[j]) continue;
			if(base + rad >= k){
				resp.pb(j);
				used[j] = 1;
				break;
			}else {
				base += rad;
			}
		}
	}
	return resp;
}

int main(){
	VI pp = kthPerm(4, 15);
	forn(i, sz(pp)) cout << pp[i] << " ";
	cout << endl;
	return 0;
}
