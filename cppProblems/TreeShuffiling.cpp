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
ll a[200005];
int b[200005],c[200005],cnt[200005][2];
vector<int> g[200005];
ll ans;
void dfs(int u,int p, ll minCost){
	if(b[u]!=c[u])cnt[u][b[u]]++;
	minCost=min(minCost,a[u]);
	for(int v:g[u]){
		if(v!=p){
			dfs(v,u,minCost);
			cnt[u][0]+=cnt[v][0];
			cnt[u][1]+=cnt[v][1];
		}
	}
	int temp=min(cnt[u][0],cnt[u][1]);
	ans+=(temp*2)*minCost;
	cnt[u][0]-=temp;
	cnt[u][1]-=temp;
	return;
}
int main(){FIN;
	int n;
	cin >>n;
	fore(i,0,n){
		cin >> a[i] >> b[i] >> c[i];
	}
	fore(i,0,n-1){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(0,-1,a[0]);
	if(cnt[0][0]!=cnt[0][1]){
		cout << "-1\n";
	}else{
		cout << ans << "\n";
	}
    return 0;
}
