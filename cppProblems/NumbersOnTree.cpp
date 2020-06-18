#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree < int ,  null_type ,  less<int> ,  rb_tree_tag ,  tree_order_statistics_node_update > ordered_set;
ordered_set os;
vector<int> adjList[2005];
int crray[2005];
int subTreeSize[2005];
int assigns[2005];
void dfs(int u,int p){
	auto selected=os.find_by_order(crray[u]);
	assigns[u]=*selected;
	os.erase(selected);
	for(auto v:adjList[u]){
		if(v!=p){
			dfs(v,u);
		}
	}
}
int dfsCount(int u,int p){
	for(auto v:adjList[u]){
		if(v!=p){
			subTreeSize[u]+=(1+dfsCount(v,u));
		}
	}
	return subTreeSize[u];
}
int main(){FIN;
	int n;
	cin >> n;
	int root=-1;
	fore(i,0,n){
		int p,c;
		cin >> p >> c;
		if(p!=0){
			adjList[p-1].pb(i);
			adjList[i].pb(p-1);
		}else{
			root=i;
		}
		crray[i]=c;
	}
	dfsCount(root,-1);
	bool puedo=true;
	fore(i,0,n){
		if(crray[i]>subTreeSize[i])puedo=false;
	}
	if(puedo){
		cout << "YES\n";
		fore(i,1,n+1)os.insert(i);
		dfs(root,-1);
		fore(i,0,n){
			if(i==n-1)cout << assigns[i]<<"\n";
			else cout << assigns[i]<<" ";
		}
	}else{
		cout << "NO\n";
	}
    return 0;
}

