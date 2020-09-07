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
typedef pair<ll,ll> ii;
struct STree { // example: range sum with range addition
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	ll query(int k, int s, int e, int p){
		if(p<s || p>=e)return 0; // operation neutral
		push(k,s,e);
		if(s+1==e)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,p)+query(2*k+1,m,e,p); // operation
	}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	ll query(int p){return query(1,0,n,p);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
int depth[300005];
ll ans[300005];
int n,m;
vector<int> g[300005];
map<int,vector<ii>> mp;//d,x
void compDepth(int u,int p){
	for(int v:g[u]){
		if(v!=p){
			compDepth(v,u);
			depth[u]=max(depth[u],depth[v]+1);
		}
	}
	return ;
}
STree st(1);
void dfs(int u, int p, int h){
	vector<ii> &upds=mp[u];
	fore(i,0,upds.size()){
		st.upd(h,h+1+min(upds[i].ff,(ll)depth[u]),upds[i].ss);
	}
	ans[u]=st.query(h);
	for(int v:g[u]){
		if(v!=p){
			dfs(v,u,h+1);
		}
	}
	fore(i,0,upds.size()){
		st.upd(h,h+1+min(upds[i].ff,(ll)depth[u]),-upds[i].ss);
	}
	return ;
}
int main(){FIN;
	cin >> n;
	st=STree(n+5);
	fore(i,0,n-1){
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		g[y].pb(x);
		g[x].pb(y);
	}
	compDepth(0,-1);
	cin >> m;
	fore(i,0,m){
		int v;
		ll d,x;
		cin >> v >> d >>x;
		v--;
		mp[v].pb(ii(d,x));
	}
	dfs(0,-1,0);
	fore(i,0,n){
		cout << ans[i]<<" ";
	}
	cout << "\n";
    return 0;
}
