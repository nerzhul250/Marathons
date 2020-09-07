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
struct STree { // example: range sum with range addition
	vector<ii> st,lazy;int n;
	STree(int n): st(4*n+5,ii(-1,-1)), lazy(4*n+5,ii(-1,-1)), n(n) {}
	void push(int k, int s, int e){
		if(lazy[k].ff==-1)return; // if neutral, nothing to do
		st[k]=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=ii(-1,-1); // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ii v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		if(st[2*k]==st[2*k+1]){
			st[k]=st[2*k];
		}else{
			st[k]=ii(-1,-1);
		}
	}
	ii query(int k, int s, int e, int p){
		if(p<s || p>=e)return ii(-1,-1); // operation neutral
		push(k,s,e);
		if(st[k].ff!=-1 || s+1==e)return st[k];
		int m=(s+e)/2;
		ii q1=query(2*k,s,m,p);
		if(q1.ff!=-1){
			return q1;
		}else{
			return query(2*k+1,m,e,p);
		}
	}
	void upd(int a, int b, ii v){upd(1,0,n,a,b,v);}
	ii query(int p){return query(1,0,n,p);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
int a[100005],b[100005];
int main(){FIN;	
	int n,m;
	cin >> n >> m;
	fore(i,0,n)cin >> a[i];
	fore(i,0,n)cin >> b[i];
	STree st(n);
	fore(i,0,m){
		int t;
		cin >> t;
		if(t==1){
			int x,y,k;
			cin >> x >> y>>k;
			x--;
			y--;
			st.upd(y,y+k,ii(x,y));
		}else{
			int p;
			cin >> p;
			p--;
			ii v=st.query(p);
			if(v.ff!=-1){
				cout << a[p-v.ss+v.ff]<<"\n";
			}else{
				cout << b[p]<<"\n";
			}
		}
	}
    return 0;
}
