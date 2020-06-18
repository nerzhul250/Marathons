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
const int MAXN=100005;
const int INF=1e9;
vector<ii> g[MAXN];
int n,m;
vector<int> dijkstra(int x){
	vector<int> state(n,INF);
	priority_queue<pair<int,int>> q;
	state[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().ss;int c=q.top().ff;q.pop();
		c*=-1;
		if(state[x]<c)continue;
		for(ii u:g[x]){
			int newC=max(u.ss,c);
			if(newC<state[u.ff]){
				state[u.ff]=newC;
				q.push({newC*-1,u.ff});
			}
		}
	}
	return state;
}
int main(){FIN;
	cin >> n >> m;
	if(n==1){cout << "0\n";return 0;}
	vector<pair<ii,int>> edges;
	fore(i,0,m){
		int a,b,c;
		cin >> a >> b>>c;
		a--;
		b--;
		g[a].pb(ii(b,c));
		g[b].pb(ii(a,c));
		edges.pb({ii(a,b),c});
	}
	vector<int> state0=dijkstra(0),staten=dijkstra(n-1);
	int ans=INF;
	fore(i,0,edges.size()){
		int a=edges[i].ff.ff,b=edges[i].ff.ss,c=edges[i].ss;
		if(c>=state0[a] && c>=staten[b]) ans=min(ans,max(state0[a],staten[b]));
		if(c>=state0[b] && c>=staten[a]) ans=min(ans,max(state0[b],staten[a]));
	}
	cout << (ans==INF?-1:ans) << "\n";
    return 0;
}
