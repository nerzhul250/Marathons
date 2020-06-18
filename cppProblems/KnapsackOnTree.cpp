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
vector<int> adjList[100005];
priority_queue<int> Q[100005];
int C[100005],P[100005];
void dfs(int u,int prev){
	int idx=-1;
	for(int v:adjList[u]){
		if(v!=prev){
			dfs(v,u);
			if(idx==-1 || Q[idx].size()<Q[v].size())idx=v;	
		}
	}
	if(idx!=-1){
		Q[u].swap(Q[idx]);
		for(int v:adjList[u]){
			if(v!=prev && v!=idx){
				while(!Q[v].empty()){
					Q[u].push(Q[v].top());
					Q[v].pop();
				}
			}
		}
	}
	Q[u].push(-P[u]);
	while(Q[u].size()>C[u])Q[u].pop();
}
int main(){FIN;
	int N;
	cin >> N;
	fore(i,0,N){
		int c,p;
		cin >> C[i]>>P[i];
	}
	fore(i,0,N-1){
		int u,v;
		cin >> u >> v;
		u--;v--;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	dfs(0,-1);
	ll ans=0;
	while(!Q[0].empty()){
		ans+=(-Q[0].top());
		Q[0].pop();
	}
	cout << ans << "\n";
    return 0;
}
