#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
vector<int> adj[100005];
bool even;
int l,m;
void dfs(int node,int parent,int dis){
	if(adj[node].size()==1){
		l++;
		if(dis%2!=0){
			even=false;
		}
	}
	bool counted=false;
	for(int u:adj[node]){
		if(!counted && adj[node].size()!=1 && adj[u].size()==1){
			m++;
			counted=true;
		}
		if(u!=parent){
			dfs(u,node,dis+1);
		}
	}
}
int main(){FIN;
	int n;
	cin >> n;
	even=true;
	fore(i,0,n-1){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	int root=-1;
	fore(i,0,n){
		if(adj[i].size()==1){
			root=i;
			break;
		}
	}
	dfs(root,-1,0);
	if(even){
		cout << "1 ";
	}else{
		cout << "3 ";
	}
	cout << n-1-l+m<<"\n";
    return 0;
}
