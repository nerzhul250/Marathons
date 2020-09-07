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
typedef pair<int,ll> il;
const ll INF=1e18;
struct STree {
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,INF), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, ll *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=min(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		if(st[k]!=INF)st[k]+=lazy[k]; // update st according to lazy
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
		st[k]=min(st[2*k],st[2*k+1]); // operation
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return INF; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return min(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(int a, int b, ll v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
int n,q;
vector<il> g[500005];
ll a[500005];
void dfs(int u, int p, ll dis){
	a[u]=dis;
	for(){}{
}
int main(){FIN;	
	cin >> n >> q;
	fore(i,0,n-1){
		int p;
		ll w;
		cin >> p >> w;
		p--;
		g[i+1].pb(il(p,w));
		g[p].pb(il(i+1,w));
	}
	
    return 0;
}
