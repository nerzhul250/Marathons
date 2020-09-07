#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
 
using namespace std;
typedef pair<int,int> ii;
const int MAXN=300005;
int n,m;
vector<ii> g[MAXN];
vector<int> dp[MAXN];
bool cmp(const ii &a,const ii &b){
	return a.ss<b.ss;
}
int go(int u,int i){
	int &r=dp[u][i];
	if(r!=-1)return r;
	r=0;
	int starting=upper_bound(ALL(g[g[u][i].ff]),g[u][i],cmp)-g[g[u][i].ff].begin();
	fore(j,starting,g[g[u][i].ff].size()){
		r=max(r,1+go(g[u][i].ff,j));
	}
	return r;
}
int main(){FIN;
	cin >> n >> m;
	fore(i,0,m){
		int u,v,w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].pb(ii(v,w));
	}
	fore(i,0,n){
		dp[i]=vector<int>(g[i].size(),-1);
		sort(ALL(g[i]),cmp);
	}
	int maximo=0;
	fore(u,0,n){
		fore(i,0,g[u].size()){
			maximo=max(maximo,go(u,i));
		}
	}
	cout << maximo+1<<"\n";
	return 0;
}
