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

struct STree { // example: range sum with range additio
	vector<ll> st,lazy,st2;
	int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n),st2(4*n+5,0) {}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]=max(st[k],lazy[k]); // update st according to lazy
		st2[k]=max(st2[k],lazy[k]);
		if(s+1<e){ // propagate to children
			lazy[2*k]=max(lazy[2*k],lazy[k]);
			lazy[2*k+1]=max(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=max(st[2*k],st[2*k+1]); // operation
		st2[k]=min(st2[2*k],st2[2*k+1]);
	}
	ll query(int k, int s, int e, int a, int b, ll v){
		push(k,s,e);
		if(s>=b||e<=a ||st2[k]>v)return 0; // operation neutral
		if(s>=a&&e<=b){
			if(v>=st[k]){
				return e-s;
			}else{
				if(s+1==e){
					return 0;
				}else{
					int m=(s+e)/2;
					return query(2*k,s,m,a,b,v)+query(2*k+1,m,e,a,b,v);
				}
			}
		}
		int m=(s+e)/2;
		return query(2*k,s,m,a,b,v)+query(2*k+1,m,e,a,b,v); // operation
	}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a,int b, int v){return query(1,0,n,a,b,v);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main(){FIN;
	int c;
	cin >> c;
	while(c--){
		int n;
		cin >> n;
		STree st(100000);
		ll sum=0;
		fore(i,0,n){
			int l,r;
			ll h;
			cin >> l >> r >> h;
			sum+=st.query(l,r,h);
			st.upd(l,r,h);
		}
		cout << sum << "\n";
	}
	cin >> c;
    return 0;
}
