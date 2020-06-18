#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int color[200005];
vector<int> adjList[200005];
int dp[200005];
int sol[200005];
int maxDiff(int u,int p){
	for(int v:adjList[u]){
		if(v!=p){
			dp[u]+=max(maxDiff(v,u),0);
		}
	}
	return dp[u]=dp[u]+color[u];
}
void solDFS(int u,int p, int solp){
	sol[u]=max(solp,0)+dp[u];
	for(int v:adjList[u]){
		if(v!=p){
			solDFS(v,u,sol[u]-max(dp[v],0));
		}
	}
}
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n){
		cin >> color[i];
		if(color[i]==0){
			color[i]=-1;
		}
	}
	fore(i,0,n-1){
		int u,v;
		cin >> u >> v;
		u--,v--;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	maxDiff(0,-1);
	solDFS(0,-1,0);
	fore(i,0,n){
		if(i==n-1)cout << sol[i]<<"\n";
		else cout << sol[i]<<" ";
	}
    return 0;
}
