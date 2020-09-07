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
const int MAXN=80;
const ll INF=1e10;
// g[i][j]: weight of edge (i, j) or INF if there's no edge
// g[i][i]=0
ll g[MAXN][MAXN];
int n;
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,n)fore(i,0,n)if(g[i][k]<INF)fore(j,0,n)if(g[k][j]<INF)
		g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

int main(){FIN;
	cin >> n;
	if(n==1){
		cout << "-1.00000 -1.00000\n";
		return 0;
	}
	int M;
	cin >> M;
	fore(i,0,n){
		fore(j,0,n){
			g[i][j]=INF;
		}
		g[i][i]=0;
	}
	fore(i,0,M){
		int u,v;
		ll t;
		cin >> u >> v >> t;
		u--;
		v--;
		g[u][v]=min(g[u][v],t);
		g[v][u]=min(g[v][u],t);
	}
	floyd();
	ll bfg=INF;
	fore(u,0,n-1){
		fore(v,u+1,n){
			ll maxDis=-1;
			fore(x,0,n-1){
				fore(y,x+1,n){
					maxDis=max(maxDis,min(g[x][y],min(g[x][u]+g[v][y],g[x][v]+g[u][y])));
				}
			}
			bfg=min(bfg,maxDis);
		}
	}
	ll maxArista=0;
	fore(u,0,n-1){
		fore(v,u+1,n){
			ll l=0;
			ll r=INF;
			while(l<=r){
				ll mid=(l+r)/2;
				ll maxDis=-1;
				fore(x,0,n-1){
					fore(y,x+1,n){
						maxDis=max(maxDis,min(g[x][y],min(g[x][u]+g[v][y]+mid,g[x][v]+g[u][y]+mid)));
					}
				}
				if(maxDis==bfg){
					maxArista=max(maxArista,mid);
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
		}
	}
	if(bfg==INF){
		cout << "-1.00000 ";
	}else{
		cout << bfg << " ";
	}
	if(maxArista==INF){
		cout << "-1.00000\n";
	}else{
		cout << maxArista<<"\n";
	}
    return 0;
}
