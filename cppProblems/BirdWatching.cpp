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
vector<int> g[MAXN];  // u->[(v,cost)]
set<int> reach[MAXN];
void go(int curr,int pred){
	if(reach[curr].count(pred))return ;
	if(reach[curr].size()>=2)return ;
	reach[curr].insert(pred);
	for(int u:g[curr]){
		go(u,pred);
	}
	return ;
}
int main(){FIN;
	int N,M,T;
	cin >> N >> M >> T;
	vector<int> pred;
	fore(i,0,M){
		int u,v;
		cin >> u >> v;
		if(v==T){
			pred.pb(u);
		}else{
			g[v].pb(u);	
		}
	}
	for(int p:pred){
		go(p,p);
	}
	vector<int> ans;
	for(int p:pred){
		if(reach[p].size()==1){
			ans.pb(p);
		}
	}
	sort(ALL(ans));
	cout << ans.size() << "\n";
	fore(i,0,ans.size()){
		cout << ans[i]<<"\n";
	}
	
    return 0;
}
