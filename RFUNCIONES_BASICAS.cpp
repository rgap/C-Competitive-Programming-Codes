#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

///////////////////////////////////////////////////////////////

int main(){

    return 0;
}

memset(a,0,sizeof(a));

//CUADRADO MAGICO

int n,a[MAX][MAX];
memset(a,0,sizeof(a));
n=3;
int X=0,Y=n/2;	

for(int i=1;i<=(n*n);i++){
	a[X][Y]=i;
	if (a[(X+n-1)%n][(Y+n+1)%n])
		X=(X+n+1)%n ;
	else
		X=(X+n-1)%n,Y=(Y+n+1)%n ;
}

for(int i=0;i<n; i++){
	cout<<'\n';
	for(int j=0;j<n; cout<<a[i][j++]<<'\t');
}

int s=(1/2.0)*n*(1+n*n);//suma ctte

//////////////////////////////////////////////


typedef vector<int> tvi;
#define ABS(x) ((x<0)?(-(x)):(x))
//freopen("1.txt","r",stdin);

//referencia
void f(int&x)
void f(vector<int>&x)

//n es impar -> if(n&1)
int a[] = {1,2,3,4,5,4,3,2,1};
vector<int> v(a,a+9);

//Redondeo a 4 cifras
double a=2.56379381;
int p=pow(10,4.0);
a=ceil(a*p)/p;


int n=6;
n<<=3;//multiplica n por 2^3
n>>=3;//divide entre 2^3

//indice mitad = techo((v.size+1)/2)-1

piso: int n = x/y;
techo: int n = (x+y-1)/y

///////////////////////////////////////////////////////////////

/*
include <limits.h>
CHAR_BIT
SCHAR_MIN
SCHAR_MAX
UCHAR_MAX
CHAR_MIN
CHAR_MAX
MB_LEN_MAX
SHRT_MIN
SHRT_MAX
USHRT_MAX
INT_MIN
INT_MAX
UINT_MAX
LONG_MIN
LONG_MAX
ULONG_MAX
*/

////////////////////////////////////

string s;//tamaño n
//s se repite repeticiones veces
//pos=[0..n*repeticiones-1]
s[pos % n]//posicion en s con limite de n


forn(i,sz){//Para cad de tamaño sz, toma 2 adyacentes de cada elemento
	if(cad[(i-1+sz)%sz]=='1')c++; //para i=0, elementos 1 y sz-1
	if(cad[i]=='1')c++; //posicion de 0 a sz-1
	if(cad[(i+1)%sz]=='1')c++; 
}


//subarray maximo
int kadane(vector<int>v){
	int maxSum=-99,maxi=0,maxf=0,sum=0,inicio=0;
    fori(i,1,v.size()){
        sum += v[i];
        if(sum > maxSum){
            maxSum=sum;
			maxi=inicio;
			maxf=i;
		}
        if(maxSum<0){
            maxSum= 0;
			inicio= i+1;
		}
	}
    return maxSum;
}

//s+=c;
vector<string> splitString(string s,char c){
	vector<string>v;
	string ste=""; 
	forn(i,s.size()){
		if(s[i]==c){
			if(ste.size()>0)
				v.pb(ste);
			ste="";
		}
		else 
			ste+=s[i];
	}
	return v;
}

bool check_inc(int i,int j,const VI& seq){	
    int diff = seq[i+1]-seq[i];
    for(i++;i<j;++i)
	if(diff<=0 || (seq[i]-seq[i-1])!=diff) return false;
    return true;
}

bool check_dec(int i,int j,const VI& seq){
    int diff = seq[i+1]-seq[i];
    for(i++;i<j;++i)
	if(diff>=0 || (seq[i]-seq[i-1])!=diff) return false;
    return true;
}
	
bool check_eq(int i,int j,const VI& seq){
    int k=seq[i];
    for(i++;i<j;++i)
	if(seq[i]!=k) return false;
    return true;
}

long permutation(int x,int n){//P(x,n)
    long r=1;
    for(int i=0;i<n;++i)
        r=r*(x-i);
    return r;
}

bool isPal(int perm[],int i,int j){//es palindromo
    for(;i<j;i++,j--)
        if(perm[i]!=perm[j]) return 0;
    return 1;
}

bool check(string a, string b){//"b" es subseq de "a".
    int i = 0, j = 0;
    while(i<a.size()&&j<b.size()) {
        if(a[i]==b[j]) j++;
        i++;
    }
    return j==b.size();
}

unsigned int bitsize(const unsigned int& n){//tamaño de n en binario
  if(n){
    unsigned int tn=n,numb = 0;
    while(tn){
      numb++;
      tn>>=1;
    }
    return numb;
  }
  return 1;
}

for(int i=0;i<tam;++i){
    if(n & (1 << i)){//iesimo bit de n en binario
        cout<<i;
    }
}

getline(cin,s);//get string line

void split(){//separa por espacios
    string s=" fsafas     adfff   feff gg     f",sub;
    istringstream iss(s);
    while(iss>>sub)
        cout<<sub<<endl;//subcadenas entre espacios
}

vector<string> split(string s){//separa por espacios
	vector<string>words;
	string sub;
    istringstream iss(s);
    while(iss>>sub)
		words.push_back(sub);
	return words;
}


void printm(int (*M)[MAX],int n, int m){//imprime matriz
    int i,j;
    for(i=0;i<n;++i){
        for(j=0;j<m;++j)
            cout<<" "<<M[i][j];
        cout<<endl;
    }
}

int printb(int n){//imprime en binario
  if(!n) return 1;
  else printb(n/2);
  cout<<n%2;
}

void print(vector<int>v){
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<"  ";
    cout<<endl;
}

///////////////////////////////////

bool isvowel(char c){
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		return 1;
	return 0;
}

bool isthere(int a[], int n, int key){//verifica si se encuentra en el arreglo
    a[n]=key;//sentinela
    for(int i=0;;++i)
        if(a[i] == key)
            return (i<n);
}

int binSearch(vector<int>v,int key,int i, int j) {
	if(j<i)return -1;
	int mid=i+(j-i)/2;
    if(v[mid]>key) return binSearch(v,key,i,mid-1);
    if(v[mid]<key) return binSearch(v,key,mid+1,j);
    return mid;
    
}

int Sumk(vector<int>v,int k){//si alguno 2 elem suman k
	vector<int>R; int t;
	forn(i,v.size())
		R.push_back(k-v[i]);
	stable_sort(v.begin(),v.end());
	forn(i,v.size()){
		t=binSearch(v,v[i],0,v.size()-1);
		if(i!=t && t>0) return 1; 
	}
	return 0;
}
	
int check_prefix(string p,string s){//p es prefijo de s
  if(p.size()>s.size()) return 0;
  forn(i,p.size())
    if(s[i]!=p[i]) return 0;
  return 1;
}
 
int check_suffix(string p,string s){//p es sufijo de s
  if(p.size()>s.size()) return 0;
  forn(i,p.size())
    if(p[p.size()-1-i]!=s[s.size()-1-i]) return 0;
  return 1;
}
 
int check_sub(string p,string s){//no es pref ni suf
  int f,j;
  for(int i=1;i+p.size()<s.size();++i,f=1){
    for(j=0;j<p.size();++j)
      if(p[j]!=s[i+j]) f=0;
    if(f) return 1;
  }
  return 0;
}

void raices(int n){
     int det=b*b-4*a*c;
     if(!det) printf("%.3f\n",-b/(2*a));//redondeado a 3 decimales
     if(det>0) printf("%.3f %.3f\n",(-b-sqrt(det))/(2*a),(-b+sqrt(det))/(2*a));
     if(det<0) cout<<"No solution!"<<endl;
}

bool esPerfecto(int n){
    int i,ac = 0;
    for( i = 1; i<n; i++ )
        if(n%i == 0) ac += i;
    if(ac==n) return 1;
    return 0;
}

bool isPal(string s){//es palindromo
    for(register int i=0,j=s.length()-1;i<j;i++,j--)
        if(s[i]!=s[j]) return 0;
    return 1;
}

string whatTime(int s) {//de segundos a hora
	int h=s/3600; s=s%3600;
	int m=s/60; s=s%60;
	stringstream st; st<<h<<":"<<m<<":"<<s;
    return st.str();
}

//C(n,n-k)
int comb(int n,int k){//combinatorio
    k=min(k,n-k);
    if(k<0) return 0;
    int c=1;
    for(int i=1; i<=k; ++i)
        c=c*(n-i+1)/i;
    return c;
}

//Subsets

int best,n;
vector<int>item;
//i=cant inicial de elems  cant=actual  n=tam de set
void check_subsets(int i, int acum){
    if(i==n){
        best=min(best,acum);//minima cantidad
        return;
    }
    check_subsets(i+1,acum);
    //cout<<endl<<"--> "<<acum<<"  "<<item[i]<<endl;
    check_subsets(i+1,acum+item[i]);
}

int bitcount(int n){//numero de 1s de n en binario = subconj de tamaño k
	return (n==0)?0:(n&1)+bitcount(n/2);
}

//Bitfield Counter Method
void check_subsets(vector <int> items){
    int i,j,n=items.size();
    for(i=1;i<(1<<n);++i){
		//if(bitcount(i)!=k) 
			//continue;//no es subconj de tamaño k
        for(j=0;j<n;++j){
            if(i&(1<<j))
                cout<<items[j]<<" ";//elementos de subconjunto i
		}
		cout<<endl;
   }
}

//desde el mas grande
void check_subsets(vector <int> items){
    int i,j,n=items.size();
    for(i=1;i<(1<<n);++i){
		//if(bitcount(i)!=k) 
			//continue;//no es subconj de tamaño k
        for(j=n-1;j>=0;--j){
            if(!(i&(1<<j)))
                cout<<items[n-j-1]<<" ";//elementos de subconjunto i
		}
		cout<<endl;
   }
}

subsetsLex(0,"");
vector<string> items;
//en orden lexicografico
void subsetsLex(int i,string subset){
	cout<<subset<<"  ";
	for(;i<items.size();++i)
		subsetsLex(i+1,subset+items[i]);
}


//Subset consecutivos
void subs_consec(vector<string>items){
	int i,j;
	for(i=0;i<items.size();++i){
		for(j=i;j<items.size();++j)
			cout<<items[j]<<" ";
}

//permutaciones n!
void perms(){
	do{ forn(i,v.sz) cout<<v[i]<<" ";
		cout<<endl;
	}while (next_permutation(all(v)));
}


#define MAX 1000000

bool primes[MAX];
void n_primos(){//primos hasta MAX
   primes[0]=false;
   for(int i=1;i<MAX;i++) primes[i]=true;
   for(int i=2;i*i<=MAX;i++){
      if(primes[i]){
         for(int j=i;j*i<=MAX;j++){
             primes[j*i]=false;
         }
      }
   }
}
////////////
for(i=2;i<=n/2;++i){//b-a maximizada
    if(primes[i] && primes[n-i]){
        printf("%d = %d + %d\n",n,i,n-i);
        break;
    }
}
////////////

int gcd(int a, int b){
   return b?gcd(b,a%b):a;
}

int lcm(int a, int b){
   return b*a/gcd(a,b);
}

string borraesp(string::const_iterator i, string::const_iterator f){//borra espacios
	string::const_iterator it; string s;
    for(it = i; it != f; ++it)
        if(*it!=' ') s+=*it;
    return s;    
}

int countStrOc(string s1,string s2){//cuenta # ocurrencias de s1 en s2
	int pos=0,c=0;
	while(pos!=-1){//mientras encuentre s1
		pos=s2.find(s1, pos);//busca s1 en s2 desde pos
		if(pos!=-1){//si encontro s1
			c++;
			pos = pos+s1.size();//recorre s1
		}
	}
	return c;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////___________GRAFOS________________///////////////////////////////////////////////////////

//PRIM1

#include <iostream>
#include <math.h>
using namespace std;
#define nn 101//numero maximo de puntos
double graph[nn][nn];//matriz adyac

struct coordinates{
    double x;double y;
};
double dist(coordinates p1, coordinates p2){
	return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}
bool compare(const void * a, const void * b){
	if(a<b) return true;
    return false;
}
double prim(double graph[][nn], int points, int src){
    int *visited=new int[points], *parent=new int[points],u,v,i,j;
    double *d=new double[points], min, stcost;
    for(i = 0; i < points; i++){
		d[i] = graph[src][i];
		visited[i] = 0;
		parent[i] = src;
    }
    visited[src] = 1; 
	stcost = 0;
    for(i = 0; i < points-1; i++){
		min = 999;
		for(j = 0; j < points; j++){
			if (!visited[j] && d[j] < min){
				min = d[j]; u = j;
			}
		}
		visited[u] = 1;
		stcost = stcost + d[u];
		for(v = 0; v < points; v++)
			if (!visited[v] && (graph[u][v] < d[v])){
				d[v] = graph[u][v]; 
				parent[v] = u;
			}
    }
    return stcost;
}

int main() {
	freopen("1.txt","r",stdin);
	int points,i,j,k; cin>>points;
	coordinates*coord=new coordinates[points];
	for(j = 0; j < points; j++)
		cin >> coord[j].x >> coord[j].y;
	for(j = 0; j < points; j++){
		for(k = j; k < points; k++){
			graph[j][k] = dist(coord[j], coord[k]);
			graph[k][j] = graph[j][k];
		}
	}
	printf("%.2f\n",prim(graph,points,0));
}

//PRIM2

#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#define INF 100000
using namespace std;

struct edge {
	vector<int>Adj; vector<int>Cost;
};
struct node{
	int x, y;
};

edge Ed[100];//100=#nodos maximo
int N, E,key[100],P[100], Cost,SS[100][100]; char F[100];

struct comp{ 
	bool operator()(const node&a,const node&b){return a.y>b.y;}
};

void CT(int u){
	if(F[u] == 1 || u == 1) return;
	F[u] = 1;
	if(P[u] == -1) return;
	Cost += SS[u][P[u]]; CT(P[u]);
}

int Prim(){
	int i,j,u,v,c; Cost=0;
	priority_queue<node,vector<node>,comp>Q;
	node temp,dum;
	for(i = 1; i<= N; i++) key[i] = INF;
	key[1] = 0; temp.x = 1; temp.y = 0;
	Q.push(temp); P[1] = -1;
	while(!Q.empty()){
		temp = Q.top();
		Q.pop();
		u = temp.x;
		F[u] = 1;
		for(i=0;i<Ed[u].Adj.size();i++){
			v = Ed[u].Adj[i];
			c = Ed[u].Cost[i] + temp.y;
			if(F[v] == 0) {
				if(key[v]>c){
					dum.x = v;
					dum.y = c;
					key[v] = c;
					P[v] = u;
					Q.push(dum);
				}
			}
		}
	}
	for(i=1;i<=N;i++)F[i] = 0;
	for(i=1;i<=N;i++) if(F[i] == 0) CT(i);
	return Cost;
}

void main() {
	int c,u,v,n;
	cin>>N>>E;
	n = E;
	while(n--) {
		cin>>u>>v>>c;
		Ed[u].Adj.push_back(v);//arista adyacente hacia nodo v
		Ed[u].Cost.push_back(c);//rista adyacente costo c
		Ed[v].Adj.push_back(u);
		Ed[v].Cost.push_back(c);
		SS[u][v] = SS[v][u] = c;//matriz de adyacencia - grafo no dir
	}
	cout<<Prim()<<endl;
}
//PRIM3 

///////////////////////////////_____________KRUSKAL_________________///////////////////////////////////////////////////

#include<iostream>
using namespace std;

#define MAXN 102 //maximo de nodos
int P[MAXN], Rank[MAXN];
int N, E, Cost;

struct edge{
	int u,v;
	int cost;
};
edge Edge[MAXN*MAXN];
edge Path[MAXN];

int com(const void *xy, const void *xz) {
	edge *x=(edge*)xy;
	edge *y=(edge*)xz;
	return (x->cost - y->cost);
}
void In(){
	int i;
	for(i = 1;i<= E;i++) {
		P[i] = i; Rank[i] = 1;
	}
}
int Find(int n) {//encuentra padre de nodo
	if(P[n]!=n)
		P[n] = Find(P[n]);
	return P[n];
}

void Link(int x, int y){
	if(Rank[x] > Rank[y]) P[y] = x;
	else{
		P[x] = y;
		if(Rank[x] == Rank[y]) Rank[y]++;
	}
}
void Kruskal(){
	int x, y, total = 0; Cost = 0;
	for(int i = 0; i<E; i++) {
		x = Find(Edge[i].u);
		y = Find(Edge[i].v);
		if(x != y) {
			Path[total++] = Edge[i];
			Link(x,y);
			Cost += Edge[i].cost;
			if(total == N - 1) break;
		}
	}
}

void Cal(){
	qsort(Edge,E,sizeof(edge),com);//ordena respcto al costo
	Kruskal();
	cout<<"Total Cast :"<<Cost<<endl;
	for(int i = 0; i<N-1; i++) //impr camino en lineas
		cout<<Path[i].u<<" "<<Path[i].v<<" "<<Path[i].cost<<endl;
}

void main() {
	int i;
	while(cin>>N>>E){
		In();
		for(i = 0; i<E; i++) cin>>Edge[i].u>>Edge[i].v>>Edge[i].cost;
		Cal();
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////_____________250______P1___________///////////////////////////////////////////////////////

string getMessage(string original){
	int p=0,q=0,i,k=1,k1=1;
	string voc="aeiou"; string ss; original+=" ";
	while(p<original.size()){
		q=original.find(" ",p);
		if(original.find_first_not_of(voc,p)>=q) 
			for(i=p;i<q;i++) 
				ss+=original[i];
		else
		for(i=p;i<q;i++){
			if(voc.find(original[i])==-1){		
				if(k){
					ss+=original[i];
					k=0;
				}
			}
			else{
				k=1;
			}
		}
		ss+=" ";
		k=k1=1;
		p=q+1;
	}
	ss.resize(ss.size()-1);
	return ss;
}

int minimumShifts(vector <string> ma, int v) {
	int n=(int)ma.size(),m=(int)ma[0].size(),res=-1,t,d;
	forn(i,n){
		forn(j,m){
			t=ma[i][j]-'0';
			if(t==v){
				d=min(i,n-i)+min(j,m-j);//regla"numero de tralados de filas o columnas para llegar a la posicion"
				if(res==-1||d<res) res=d;
			}
		}
	}
	return res;
}

string getWinner(vector <string> na, vector <string> vo) {
	int c=0,m=-1,s,k=0;
	forn(i,vo.size()){
		forn(j,vo.size()){
			if(i!=j && na[i]==vo[j])
				c++;
		}
		if(c==m) k=1;
		if(c>m){
			m=c; s=i; k=0;
		}
		c=0;
	}
	if(k==1)
		return "";
	return vo[s];
}

int count(string A, string B) {
	string t;int c=0;
	forn(i,A.size()+1){
		t+=A.substr(0,i);
		t+=B;
		t+=A.substr(i,A.size());
		if(esPal(t)) c++;
		t.clear();
	}
	return c;
}

vector <int> animals(int h, int l) {
	VI v;
	if(l%2==0 && l>=2*h && l<=4*h){
		v.push_back((h*4-l)/2);
		v.push_back((h*2-l)/-2);
	}
	return v;
}

int theMin(string r) {
	int res=0;
	forn1(i,r.size()){
		if(r[i]==r[i-1]){
			r[i]='.';
			res++;
		}
	}
	return res;
}

int containerSize(int N) {
	int c=0,t=1;
	for(int i=1;i<=N;i=i<<1){
		if(es_primo(N/i)){
			c++;
		}
	}
	return c;
}

int findMinimumDistance(vector <int> x, vector <int> y) {//distancia entre puntos en una linea recta
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());//empieza desde el menor punto y termina en el mas lejano para hallar la menor dist
	return abs(x[0]-x.back())+abs(y[0]-y.back());
}

int count(string badPrefix, string badSuffix, string badSubstring, vector <string> vocabulary){
  int c=0;
  forn(i,vocabulary.size()){
    if(check_prefix(badPrefix,vocabulary[i]))  c++;
    else if(check_suffix(badSuffix,vocabulary[i]))  c++;
    else if(check_sub(badSubstring,vocabulary[i]))  c++;
  }
  return c;
}


bool M[6][6]={{0,1,1,1,1,0},
			  {1,0,1,0,1,1},
			  {1,1,0,1,0,1},
			  {1,0,1,0,1,1},
			  {1,1,0,1,0,1},
			  {0,1,1,1,1,0}};
		
bool seen[6];	  
bool dfs(int a){
	seen[a]=true;
	forn(i,6){
		if(M[a][i] && !seen[i])
			dfs(i);
	}
}