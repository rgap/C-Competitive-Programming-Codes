//bellman ford

typedef vector< pair<pair<int ,int> ,int> > nodo;
int resp[MAXS];
bool centi;
bool BF(nodo grafo,int num_nodos,int key){
	fill(resp,resp+num_nodos,INF);//changevable if start in 1
	resp[key]=0;
	centi=true;
	for(int i=0;(i<num_nodos-1&&centi);i++){
		centi=false;
		for(int j=0;j<grafo.size();j++){
			if(resp[grafo[j].first.second] > resp[grafo[j].first.first] +grafo[j].second){
				resp[grafo[j].first.second] = resp[grafo[j].first.first] +grafo[j].second;
				centi=true;
			}
		}
	}
	for(int j=0;j<grafo.size();j++){
		if(resp[grafo[j].first.second] > resp[grafo[j].first.first] +grafo[j].second)
			return false;
	}
	return true;
}


//bfs

using namespace std;
#define MAXS 500
#define INF 1234567

typedef vector<int> nodo;

void bfs(nodo grafo[MAXS],int key,int *resp)
{
	queue <int> fifo;
	fifo.push(key);
	resp[key]=0;
	int t;
	while(!fifo.empty())
	{
		t=fifo.front();
		fifo.pop();
		for(int i=0;i<(grafo[t]).size();i++)
		{
			if(resp[(grafo[t])[i]]==INF)
			{
				resp[(grafo[t])[i]]=resp[t]+1;
				fifo.push((grafo[t])[i]);

			}
		}
	}
	return;
}

//catalan numbers

long long m[100];
long long catalan(int n){
	m[0]=m[1]=1;
	for(int i=2;i<=n;i++){
		forn(j,i){
			m[i]+=(m[j]*m[(i-1)-j]);
		}
	}
	return m[n];
}

//coin change

int aux;
int A[MAXN];
int B[MAXN];
long long int resp[MAXN][MAXS];
int coins[12]={0,1,2,4,10,20,40,100,200,400,1000,2000};
void coinChange(void){
	for(int i=1;i<MAXS;i++)
		resp[1][i]=resp[0][i]=1;
	for(int i=1;i<=MAXN;i++)
		resp[i][1]=1;
	for(int i=2;i<MAXN;i++){
		for(int j=2;j<MAXS;j++){
			if((i-coins[j])<0)
				resp[i][j]=resp[i][j-1];
			else
				resp[i][j]=resp[i][j-1]+resp[i-coins[j]][j];
		}
	}

	return;
}

//DFS

int visited[MAX];
VI gr[MAX];
VI grR[MAX];
int pre[MAX];
int pos[MAX];
int cc=0;
VI sol;

//simple DFS
void dfs(int sp){
	cout<<"Nodo: "<<(char)('A'+sp)<<endl;
	visited[sp]=true;
	//pre[sp]=cont++;
	forn(i,sz(gr[sp])){
		if(!visited[gr[sp][i]]) dfs(gr[sp][i]);
	}
	//pos[sp]=cont++;
}

//topological sort
void ts(int sp){
	cout<<"Nodo: "<<(char)('A'+sp)<<endl;
	visited[sp]=true;
	forn(i,sz(gr[sp])){
		if(!visited[gr[sp][i]]) ts(gr[sp][i]);
	}
	sol.pb(sp); // puede de frente imprimirse si se toma el grafo inverso
}

// para scc
void dfsR(int sp){
	visited[sp]=true;
	forn(i,sz(grR[sp])){
		if(!visited[grR[sp][i]]) dfsR(grR[sp][i]);
	}
	sol.pb(sp);
}
void dfs2(int sp){
	visited[sp]=true;
	pre[sp]=cc;
	forn(i,sz(gr[sp])){
		if(!visited[gr[sp][i]]) dfs2(gr[sp][i]);
	}
}
void scc(int N){
	fill(visited,visited+N,0 );
	forn(i,N) if(!visited[i]) dfsR(i);
	fill(visited,visited+N,0 );
	fill(pre,pre+N,0 );
	cc=0;
	forn(i,N) if(!visited[sol[N-1-i]]){ dfs2(sol[N-1-i]);cc++;}
	forn(i,N) cout<<(char)('A'+sol[N-1-i])<<" -> "<<pre[sol[N-1-i]]<<endl;
}

//DJ

typedef vector< pair<int ,int> > nodo;

void DJ(nodo grafo[MAXS],int num_nodos,int key,int *resp){
	fill(resp,resp+num_nodos,INF);
	resp[key]=0;
	priority_queue < pair<int ,int> > heap;
	int s;
	heap.push( make_pair(-resp[key], key) );
	while(!heap.empty()){
		s = heap.top().second;
		heap.pop();
		for(int i=0;i<(grafo[s]).size();i++){
			if(resp[(grafo[s])[i].first]>(grafo[s])[i].second+resp[s]){
				resp[(grafo[s])[i].first]=(grafo[s])[i].second+resp[s];
				heap.push(make_pair(-resp[(grafo[s])[i].first],(grafo[s])[i].first));
			}
		}
	}
	return;
}

//flouyCycle

int Z,I,M,L;
int f(int a){
	return (a*Z+I)%M;
}

int FC(int seed){
	int tor=f(seed), hare=f(f(seed));
	while(tor != hare){
		tor = f(tor);
		hare = f(f(hare));
	}

	int sol=tor;
	tor=f(tor);
	int cont=1;
	while(tor!=sol){
		tor=f(tor);
		cont++;
	}
	return cont;
}

//floyd warshall

int resp[MAXS][MAXS];
int add[MAXS][MAXS];
void FW(int num_nodos){
	for(int k=0;k<num_nodos;k++){
		for(int i=0;i<num_nodos;i++){
			for(int j=0;j<num_nodos;j++){
				resp[i][j]=min(resp[i][j],resp[i][k]+resp[k][j]);
			}
		}
	}
	return;
}
void FWadd(int num_nodos,int w,int u,int v){
	for(int i=1;i<=num_nodos;i++){
		for(int j=i+1;j<=num_nodos;j++){
			add[i][j]=min(resp[i][j],min(resp[i][u]+w+resp[v][j],resp[i][v]+w+resp[u][j]));//despues de un floyd cuando queremos aumentar una arista mas
		}
	}
}
void ini(int num_nodos){
	for(int i=0;i<num_nodos;i++){
		for(int j=i+1;j<num_nodos;j++){
			resp[i][j]=resp[j][i]=INF;
		}
	}

}
void print(int num_nodos){
	for(int i=0;i<num_nodos;i++){
		for(int j=0;j<num_nodos;j++){
			if(resp[i][j]>=INF)
				cout<<"~ ";
			else
				cout<<resp[i][j]<<" ";
		}
		cout<<endl;
	}
}

//gcd lcm

int64 gcd(int64 a, int64 b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int64 gcd(vector<int64> pp){
	int64 y=pp[0];
	forn(i,sz(pp)-1) y=gcd(pp[i+1],y);
	return y;
}
int64 lcm(vector<int64> pp){
	int64 y=pp[0];
	forn(i,sz(pp)-1) y=y*(pp[i+1]/gcd(pp[i+1],y));
	return y;
}


//LCS

#define MAXN 102

int N;
int A[MAXN];
int B[MAXN];
int resp[MAXN][MAXN];
void LCS(void){
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			if(B[i]==A[j]){
				resp[i][j]=resp[i-1][j-1]+1;
			}
			else{
				resp[i][j]=max(resp[i-1][j],resp[i][j-1]);
			}
		}
	}
	return;
}

//palindromo_operations

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

//permutaciones DP-- contest topcoder

//permutaciones con sets

class TheCardLineDivTwo {
	public:
		int count(vector <string>);
};
int64 dp[1<<16][14][2];
//black --0 . red --1;
int val[200];
int TheCardLineDivTwo::count(vector <string> ca) {
	fore(i,2,10 ) val['0'+i]=i;
	memset(dp,0,sizeof(dp));
	val['T']=10;
	val['J']=11;
	val['Q']=12;
	val['K']=13;
	val['A']=1;
	val['D'] =val['H']=1;
	val['C'] =val['S']=0;
	forn(i,sz(ca)) dp[1<<i][val[ca[i][0]]][val[ca[i][1]]]=1;
	fore(i,1,1<<sz(ca)){
		forn(l,sz(ca)){
			if(!(i&(1<<l))){
				fore(j,1,14){
					forn(k,2){
						if((i+(1<<l)) >=(1<<sz(ca)) ) continue;
						if(val[ca[l][0]]==j || val[ca[l][1]]==k) dp[i+(1<<l)][val[ca[l][0]]][val[ca[l][1]]]+=dp[i][j][k]%mod;
					}
				}
			}
		}

	}
	int64 cont =0;
	forn(i,14) forn(j,2) cont=(cont+dp[(1<<sz(ca))-1][i][j])%mod;
	return (int)(cont%mod);
}


//prim_mst

typedef vector< pair<int ,int> > nodo;
bool deck[MAXS];
int resp[MAXS];
void PR(nodo grafo[MAXS],int num_nodos,int key)
{
	fill(resp,resp+num_nodos,INF);
	fill(deck,deck+num_nodos,true);
	resp[key]=0;
	priority_queue < pair<int ,int> > heap;
	int s;
	heap.push( make_pair(-resp[key], key) );
	while(!heap.empty()){
		s = heap.top().second;
		heap.pop();
		if(!deck[s])
			continue;
		deck[s]=false;
		for(int i=0;i<(grafo[s]).size();i++){
			if(resp[(grafo[s])[i].first]>(grafo[s])[i].second&&deck[(grafo[s])[i].first]){
				resp[(grafo[s])[i].first]=(grafo[s])[i].second;
				heap.push(make_pair(-resp[(grafo[s])[i].first],(grafo[s])[i].first));
			}
		}

	}
	return;
}

//numeros romanos

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

//sieva

bool tp[MAX];
VI pri;
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
	forn(i,sz(pri)) cout<<pri[i]<<endl;
	return ;
}

//suffix array

#define MAXS 100010
using namespace std;
#define MAXN 65536
#define MAXLG 17
char A[MAXN];
struct entry {
	int nr[2], p;
} L[MAXN];
int P[MAXLG][MAXN], N, i, stp, cnt;
int cmp(struct entry a, struct entry b)
{
	return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
int main(void)
{
	cin>>(A);
	for (N = strlen(A), i = 0; i < N; i ++)
		P[0][i] = A[i] - 'a';
	for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
	{
		for (i = 0; i < N; i ++)
		{
			L[i].nr[0] = P[stp - 1][i];
			L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
			L[i].p = i;
		}
		sort(L, L + N, cmp);
		for (i = 0; i < N; i ++)
			P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
	}
	for (i = 0; i < N; i ++){
		cout<<L[i].p<<endl;
	}
	return 0;
}


