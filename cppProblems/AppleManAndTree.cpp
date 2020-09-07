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
const ll MOD=7+1e9;
vector<int> g[100005];
int x[100005];
ll dp[100005][5];
void dfs(int v,int p){
	if(x[v]==1){
		dp[v][0]=0;
		dp[v][1]=1;
	}else{
		dp[v][0]=1;
		dp[v][1]=0;
	}
	for(int u:g[v]){
		if(u!=p){
			dfs(u,v);
			ll tmp1=dp[v][1];
			ll tmp0=dp[v][0];
			dp[v][1]=(tmp1*dp[u][1]+tmp0*dp[u][1]+tmp1*dp[u][0])%MOD;
			dp[v][0]=(tmp0*dp[u][0]+tmp0*dp[u][1])%MOD;
		}
	}
	return;
}
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n-1){
		int p;
		cin >> p;
		g[i+1].pb(p);
		g[p].pb(i+1);
	}
	fore(i,0,n)cin >> x[i];
	dfs(0,-1);
	cout << dp[0][1]<<"\n";
    return 0;
}
