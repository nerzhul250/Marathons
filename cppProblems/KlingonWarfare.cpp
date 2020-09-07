#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long int ll;
auto rnd=bind(uniform_int_distribution<long long>(1,1e13), mt19937(time(0)));//random range 1->1e13
const ll MOD=7+1e9;
map<ll,ll> mp;
map<ll,int> h2size;
int maximo;
int styles1[10005],styles2[10005];
vector<int> g1[10005],g2[10005];
ll subt1[10005],subt2[10005];
int subtsz1[10005],subtsz2[10005];
ll f(ll x){
	if(!mp.count(x)){
		mp[x]=rnd();
	}
	return mp[x];
}
ll dfs(int v, int par,int type,vector<int> *g, int *styles,ll *subt,int *subtsz){
	subtsz[v]=1;
	ll sum=styles[v];
	ll pow=31;
	for(int c:g[v]){
		if(c!=par){
			sum+=(pow*dfs(c,v,type,g,styles,subt,subtsz))%MOD;
			subtsz[v]+=subtsz[c];
			sum%=MOD;
			pow*=31;
			pow%=MOD;
		}
	}
	subt[v]=f(sum);
	if(type==0){
		h2size[subt[v]]=subtsz[v];
	}else if(type==1){
		if(h2size.count(subt[v])){
			maximo=max(maximo,subtsz[v]);
		}
	}
	return subt[v];
}
void read(int len,int *styles,vector<int> *g){
	fore(i,0,len){
		char c;
		int p;
		cin >> c >> p;
		styles[i]=(int)c;
		if(p!=-1){
			g[p].pb(i);
			g[i].pb(p);
		}
	}
}
void init(vector<int> *g, int *styles,ll *subt,int *subtsz){
	fore(i,0,10005){
		styles[i]=0;
		subt[i]=0;
		subtsz[i]=0;
		g[i].clear();
	}
}
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int M,N;
		cin >> M >> N;
		mp.clear();
		h2size.clear();
		init(g1,styles1,subt1,subtsz1);
		init(g2,styles2,subt2,subtsz2);
		maximo=0;
		read(M,styles1,g1);
		read(N,styles2,g2);
		dfs(0,-1,0,g1,styles1,subt1,subtsz1);
		dfs(0,-1,1,g2,styles2,subt2,subtsz2);
		cout << maximo << "\n";
	}
    return 0;
}
