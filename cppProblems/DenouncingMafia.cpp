#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

int N,K,W[100005];
vector<int> adjList [100005];
priority_queue <int> q;

void dfs(int u){
	int maximum=0;
	int theSon=-1;
	W[u]=1;
	for(int v:adjList[u]){
		dfs(v);
		if(W[v]>maximum){theSon=v;maximum=W[v];}
	}
	W[u]+=maximum;
	for(int v:adjList[u]){
		if(v!=theSon)q.push(W[v]);
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N>>K;
    fore(i,0,N-1){
		int u;
		cin >> u;
		u--;
		adjList[u].pb(i+1);
	}
	
	dfs(0);
    
    q.push(W[0]);
    
    int ans=0;
    while(K && !q.empty()){
		ans+=q.top();
		q.pop();
		K--;
	}
	
	cout << ans <<"\n";
	
    return 0;
}
