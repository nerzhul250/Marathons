#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,int> edge;
typedef long long int ll;
int dist[3][200005];
ll costs[200005];
vector<edge> edges;
vector<int> adjList[200005];
int n,m,a,b,c;
void bfs(int s, int idx){
	vector<int> visited(n,0);
	queue<int> q;
	q.push(s);
	visited[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int index:adjList[u]){
			edge e=edges[index];
			int v=-1;
			if(e.ff==u){
				v=e.ss;
			}else{
				v=e.ff;
			}
			if(!visited[v]){
				visited[v]=1;
				dist[idx][v]=dist[idx][u]+1;
				q.push(v);
			}
		}
	}
	return;
}
int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		cin >> n >> m >> a >> b >> c;
		a--;
		b--;
		c--;
		fore(i,0,m){
			cin >> costs[i];
		}
		sort(costs,costs+m);
		fore(i,0,m){
			if(i)costs[i]+=costs[i-1];
		}
		fore(i,0,n){
			adjList[i].clear();
		}
		edges.clear();
		fore(i,0,m){
			int u,v;
			cin >>u>>v;
			u--;
			v--;
			adjList[u].pb(i);
			adjList[v].pb(i);
			edges.pb(edge(u,v));
		}
		ll minCost=1e18;
		fore(i,0,n){
			dist[0][i]=0;
			dist[1][i]=0;
			dist[2][i]=0;
		}
		bfs(a,0);
		bfs(b,1);
		bfs(c,2);
		fore(x,0,n){
			ll theCost=0;
			//cout << "midpoint "<<x<<endl;
			//cout << dist[0][x]+dist[1][x]+dist[2][x]-1<<endl;
			//cout << dist[1][x]-1<<endl;
			if(dist[0][x]+dist[1][x]+dist[2][x]-1>=0){
				theCost+=costs[dist[0][x]+dist[1][x]+dist[2][x]-1];
				//cout << costs[dist[0][x]+dist[1][x]+dist[2][x]-1]<<endl;
			}
			if(dist[1][x]-1>=0){
				theCost+=costs[dist[1][x]-1];
				//cout << costs[dist[1][x]-1]<<endl;
			}
			if(dist[0][x]+dist[1][x]+dist[2][x]<=m){
				minCost=min(minCost,theCost);	
			}
		}
		cout << minCost << "\n";
	}
    return 0;
}
