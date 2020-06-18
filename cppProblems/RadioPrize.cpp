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
typedef pair<int,ll> ii;
ll subtCnt[100005],subtSum[100005],tolls[100005],ans[100005];
ll totalToll;
ll initpart1,initpart2;
int n;
vector<ii> g[100005];
void set_up(int u,int p,ll acumDis){
	initpart1+=acumDis;
	initpart2+=tolls[u]*acumDis;
	subtCnt[u]++;
	subtSum[u]+=tolls[u];
	for(ii v:g[u]){
		if(v.ff!=p){
			set_up(v.ff,u,acumDis+v.ss);
			subtCnt[u]+=subtCnt[v.ff];
			subtSum[u]+=subtSum[v.ff];
		}
	}
	return ;
}
void go(int u,int p,ll part1,ll part2){
	ans[u]=tolls[u]*part1 + part2;
	for(ii v:g[u]){
		if(v.ff!=p){
			go(v.ff,u,part1-(v.ss*subtCnt[v.ff])+(v.ss*(n-subtCnt[v.ff])),part2+(v.ss*(totalToll-subtSum[v.ff]))-(v.ss*subtSum[v.ff]));
		}
	}
	return ;
}
int main(){FIN;
	cin >>n;
	fore(i,0,n){
		cin >> tolls[i];
		totalToll+=tolls[i];
	}
	fore(i,0,n-1){
		int u,v;
		ll t;
		cin >> u >> v>>t;
		u--;
		v--;
		g[u].pb(ii(v,t));
		g[v].pb(ii(u,t));
	}
	set_up(0,-1,0);
	go(0,-1,initpart1,initpart2);
	fore(i,0,n){
		cout << ans[i]<<"\n";
	}
    return 0;
}
