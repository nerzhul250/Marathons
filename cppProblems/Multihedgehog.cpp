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
int n,k;
vector<bool> visited;
int parent[100005];
int dis[100005];
void bfs(int u,vector<vector<int>> &g){
	visited[u]=true;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(int w:g[v]){
			if(visited[w]==false){
				visited[w]=true;
				dis[w]=dis[v]+1;
				parent[w]=v;
				q.push(w);
			}		
		}
	}
	return ;
}
bool verify(int u,int val,vector<vector<int>> &graph){
	visited[u]=true;
	queue<ii> q;
	q.push(ii(u,1));
	while(!q.empty()){
		ii v=q.front();
		q.pop();
		if(sz(graph[v.ff])==1 && v.ss!=val)return false;
		for(int w:graph[v.ff]){
			if(!visited[w]){
				visited[w]=true;
				if( !(sz(graph[w])==1 || sz(graph[w])>=4) ){
					return false;
				}
				q.push(ii(w,v.ss+1));
			}		
		}	
	}
	return true;
}
int main(){FIN;
	cin>>n>>k;
	vector<vector<int>> graph(n+1);
	visited.resize(n+10);
	fore(i,0,n-1){
		int a,b; cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	for(int i = 1; i<=n; i++){
		if(sz(graph[i])==1){
			parent[i]=i;
			bfs(i,graph);
			break;
		}
	}
	int farthest=-1;
	int maxDis=0;
	for(int i=1;i<=n;i++){
		if(dis[i]>maxDis){
			maxDis=dis[i];
			farthest=i;
		}
	}
	int center=farthest;
	while(dis[center]>k)center=parent[center];
	if(sz(graph[center])<3){
		cout<<"No\n";
		return 0;
	}
	visited.clear(); visited.resize(n+10);
	bool meet = verify(center,k+1,graph);
	if(meet){
		cout<<"Yes\n";
	}else{
		cout<<"No\n";
	}
	return 0;
}
