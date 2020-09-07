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
typedef pair<int,int> ii;
const int MAXN=100005;
int labos[MAXN];
vector<int> g[MAXN];
int n,m;
vector<int> tsort(int s){  // lexicographically smallest topological sort
	vector<int> r;
	multiset<ii> q;
	vector<int> d(2*n,0);
	fore(i,0,n)fore(j,0,g[i].size())d[g[i][j]]++;
	fore(i,0,n)if(!d[i])q.insert(ii(labos[i],i));
	while(!q.empty()){
		int x=0;
		if(r.size()==0){
			if(s==0){
				x=q.begin()->ss;
				r.pb(q.begin()->ff);
				q.erase(q.begin());
			}else if(s==1){
				x=q.rbegin()->ss;
				r.pb(q.rbegin()->ff);
				q.erase(next(q.rbegin()).base());
			}
		}else{
			if(r.back()==q.begin()->ff){
				x=q.begin()->ss;
				r.pb(q.begin()->ff);
				q.erase(q.begin());
			}else{
				x=q.rbegin()->ss;
				r.pb(q.rbegin()->ff);
				q.erase(next(q.rbegin()).base());
			}
		}
		fore(i,0,g[x].size()){
			d[g[x][i]]--;
			if(!d[g[x][i]])q.insert(ii(labos[g[x][i]],g[x][i]));
		}
	}
	return r;  // if not DAG it will have less than n elements
}
int minimoS(int s){
	vector<int> r=tsort(s);
	int minimo=0;
	int prev=r[0];
	fore(i,0,r.size()){
		if(r[i]!=prev){
			minimo++;
			prev=r[i];
		}
	}
	return minimo;
}
int main(){FIN;	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		fore(i,0,n){
			cin >> labos[i];
			g[i].clear();
		}
		fore(i,0,m){
			int u,v;
			cin >> u >> v;
			u--;
			v--;
			g[u].pb(v);
		}
		cout << min(minimoS(0),minimoS(1))<<"\n";
	}
    return 0;
}
