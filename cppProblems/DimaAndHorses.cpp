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
const int MAXN=300005;
int n,m;
int color[MAXN];
vector<int> g[MAXN];
void dfs(int u, int p){
	if(p==-1 || color[p]==1){
		color[u]=0;
	}else{
		color[u]=1;
	}
	int enemies=0;
	for(int v:g[u]){
		if(v!=p){
			if(color[v]==-1)dfs(v,u);
			if(color[v]==color[u]){
				enemies++;
			}
		}
	}
	if(enemies>1){
		color[u]=1-color[u];
	}
	return ;
}
int main(){FIN;	
	cin >> n >> m;
	fore(i,0,m){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(color,-1,sizeof color);
	fore(i,0,n){
		if(color[i]==-1){
			dfs(i,-1);
		}
	}
	fore(i,0,n){
		cout << color[i];
	}
	cout << "\n";
    return 0;
}
