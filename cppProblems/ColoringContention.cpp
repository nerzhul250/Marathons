#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,int> ii;
vector<int> g[100005];
int visited[100005];
int d[100005];
int main(){FIN;
	int N,M;
	cin >> N >> M;
	fore(i,0,M){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	queue<ii> q;
	visited[0]=1;
	q.push(ii(0,0));
	while(!q.empty()){
		ii u=q.front();
		q.pop();
		for(int v:g[u.ff]){
			if(!visited[v]){
				visited[v]=1;
				d[v]=u.ss+1;
				q.push(ii(v,d[v]));
			}
		}
	}
	cout << d[N-1]-1<<"\n";
    return 0;
}
