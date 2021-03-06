
///////////////// Trie con strings ////////////////////////////////

const int ESTMAX = 30000; // number of states
const int VOCMAX = 26; // size of the dictionary;

int scan[ESTMAX][VOCMAX];
int flag[ESTMAX];

int num_estados = 1;
int toNumber(char x){
	return x - 'a';
}

void add(string a){
	int estado = 0;
	int nn = sz(a);
	forn(i, nn){
		int p = toNumber(a[i]);
		if(scan[estado][p] == -1){
			scan[estado][p] = num_estados;
			estado = num_estados ++;
		}else		estado = scan[estado][p];
		flag[estado] ++;
	}
	return ;
}
int search(string a){
	int estado = 0;
	int nn = sz(a);
	forn(i, nn){
		int p = toNumber(a[i]) ;
		if(scan[estado][p] == -1){
			return 0;
		}else{
			estado = scan[estado][p];
		}
	}
	return flag[estado];
}
void trieInit(){
	num_estados = 1;
	memset(scan, -1, sizeof(scan));
	memset(flag, 0, sizeof(flag));
}

//////////////// Para mas eficiencia: TRIE con chars ///////////////////////////


const int ESTMAX = 30000; // max number of states
const int VOCMAX = 26; // size of the dictionary;
const int WORDMAX = 31; // max word length
int scan[ESTMAX][VOCMAX];
int flag[ESTMAX];

int num_estados = 1;
int toNumber(char x){
	return x - 'a';
}

void add(char a[WORDMAX], int tama){
	int estado = 0;
	int nn = tama;
	forn(i, nn){
		int p = toNumber(a[i]);
		if(scan[estado][p] == -1){
			scan[estado][p] = num_estados;
			estado = num_estados ++;
		}else		estado = scan[estado][p];
		flag[estado] ++;
	}
	return ;
}
int search(char a[WORDMAX], int tama){
	int estado = 0;
	int nn = tama;
	forn(i, nn){
		int p = toNumber(a[i]) ;
		if(scan[estado][p] == -1){
			return 0;
		}else{
			estado = scan[estado][p];
		}
	}
	return flag[estado];
}
void trieInit(){
	num_estados = 1;
	memset(scan, -1, sizeof(scan));
	memset(flag, 0, sizeof(flag));
}

///////////////////////////////// a dinamic trie //////////////////////////////////////////////
const int VOCMAX = 26; // size of the dictionary;
const int WORDMAX = 31; // max word length
class node
{
        public: 
        bool flag; 
        node *childs[VOCMAX];
        node(){ flag=false; forn(i,VOCMAX) childs[i] = NULL; }
};

node *root, *cur;
int ans = 0;
void add(char a[WORDMAX], int tama){
	cur = root;
	int nn = tama;
	forn(i, nn){
        int k = a[i]-'a';
        if(cur->childs[k] == NULL) cur->childs[k] = new node();
        cur = cur->childs[k];
	}
	if(cur->flag) return;
	cur->flag = true;
	ans ++;
}
void trieInit(){
	root = new node();
}
///////////////////////////a trie with save a lot of memory//////////////////////
///////////////warning: need to be adapted..///////////////////////////////
class node
{
        public: 
        bool ends; 
        vector<node*> childPtr;
        vector<int> childId;
        node(){ ends=false; }
};

int ans = 0, pos;
node *root, *cur;
vector<node*>::iterator it1;
vector<int>::iterator it2;
 
void add(int i, int till)
{
        int k = s[i]-'a';
        it2 = lower_bound( ALL(cur->childId), k);
        it1 = cur->childPtr.begin() + ( it2 - cur->childId.begin() );
        
        if( it2 == cur->childId.end() || *it2 > k )
        {
                it2 = cur->childId.insert( it2, k );
                node *newBorn = new node();
                it1 = cur->childPtr.insert( it1, newBorn );
        }
        
        cur = *it1;
 
        if(i!=till) add(i+1,till);
        else{ if(!cur->ends) ans++; cur->ends=true; }
}
void trieInit(){
	root = new node();
}
