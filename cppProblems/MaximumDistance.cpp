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
const int MAXN=5+1e5;
int n,m,k;
vector<int> esp;
vector<pair<int,int> > g[MAXN];  // u->[(v,cost)]
ll dist[MAXN];
void dijkstra(int x){
	memset(dist,-1,sizeof(dist));
	priority_queue<pair<ll,int> > q;
	dist[x]=0;q.push({0,x});
	while(!q.empty()){
		x=q.top().ss;ll c=-q.top().ff;q.pop();
		if(dist[x]!=c)continue;
		fore(i,0,g[x].size()){
			int y=g[x][i].ff; ll c=g[x][i].ss;
			if(dist[y]<0||max(dist[x],c)<dist[y])
				dist[y]=max(dist[x],c),q.push({-dist[y],y});
		}
	}
}
int main(){FIN;
	cin >> n >> m >> k;
	fore(i,0,k){
		int nam;
		cin>> nam;
		nam--;
		esp.pb(nam);
	}
	fore(i,0,m){
		int u,v;
		ll w;
		cin >> u>>v>>w;
		u--;
		v--;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	dijkstra(esp[0]);
	ll maximo=0;
	fore(i,0,esp.size()){
		maximo=max(maximo,dist[esp[i]]);
	}
	fore(i,0,k){
		cout <<maximo<<" ";
	}
	cout << "\n";
   return 0;
}
