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

auto rnd=bind(uniform_int_distribution<long long>(1,1e13), mt19937(time(0)));//random range 1->1e13
map<ll,ll> mp;
vector<int> g[300010];//change size and random range accordingly
ll subt[300010];// same
 
ll f(ll x){
	if(!mp.count(x)){
		mp[x]=rnd();
	}
	return mp[x];
}
 
ll dfs(int v, int par=-1){
	ll sum=0;
	for(int c:g[v]) if(c!=par){
		sum+=dfs(c,v);
	}
	subt[v]=f(sum);
	return subt[v];
}

set<ll> ans;//data structure to save/accumulate distinct hashes
 
void go(int v, int par=-1, ll hashpar=0){
	ll sum=hashpar;
	for(int c:g[v]) if(c!=par) sum+=subt[c];	//sumando los de mis hijos
	ans.insert(f(sum));//save, or accumulate
	for(int c:g[v]) if(c!=par){
		go(c,v,f(sum-subt[c]));
	}
}

int main(){FIN;
	int n;
	cin >>n;
	fore(i,0,n-1){
		int a,b;
		cin >> a >> b;
		a--,b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0);
	go(0);
	cout << ans.size() << "\n";
    return 0;
}

