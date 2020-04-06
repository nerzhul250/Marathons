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
typedef long long int ll;

const int MAXN=200005;

vector<int> g2[MAXN];
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
			if(dist[y]<0||dist[x]+c<dist[y])
				dist[y]=dist[x]+c,q.push({-dist[y],y});
		}
	}
}
int n,m,k;
int path[MAXN];
int main(){FIN;
	cin >> n >>m;
	fore(i,0,m){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		g[v].pb(ii(u,1));
		g2[u].pb(v);
	}
	cin >> k;
	fore(i,0,k){
		int p;
		cin >> p;
		p--;
		path[i]=p;
	}
	dijkstra(path[k-1]);
	int minimum=0;
	int maximum=0;
	fore(i,1,k)if(dist[path[i-1]]<=dist[path[i]])minimum++;
	fore(i,0,k){
		int cnt=0;
		int minimumNode=-1;
		for(int u : g2[path[i]]){
			if(dist[path[i]]-1==dist[u]){
				cnt++;
				minimumNode=u;
			}
		}
		if(cnt>1){
			maximum++;
		}else if(cnt==1){
			if(i+1<k && path[i+1]!=minimumNode){
				maximum++;
			}
		}
	}
	cout << minimum << " "<<maximum << "\n";
    return 0;
}
