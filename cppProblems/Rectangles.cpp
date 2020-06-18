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
struct STree { // example: range sum with range addition
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=-a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]*=-1; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=1-lazy[2*k];
			lazy[2*k+1]=1-lazy[2*k+1];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=1; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b);upd(2*k+1,m,e,a,b);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b){upd(1,0,n,a,b);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

struct ev{
	int x,y1,y2;
	ev() {}
	ev(int x,int y1,int y2): x(x),y1(y1),y2(y2){}
	bool operator < (const ev &e) const {return x<e.x;}
};
int a[200005];
int main(){FIN;
	int n;
	cin>>n;
	vector<ev> eventos;
	vector<int> ys;
	map<int,int> ytoi;
	fore(i,0,n){
		int x1,y1,x2,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1>y2)swap(y1,y2);
		eventos.pb(ev(x1,y1,y2));
		eventos.pb(ev(x2,y1,y2));
		ys.pb(y1);
		ys.pb(y2);
	}
	sort(ALL(ys));
	ys.erase(unique(ALL(ys)),ys.end());
	fore(i,0,ys.size())ytoi[ys[i]]=i;
	for(ev &e:eventos){
		e.y1=ytoi[e.y1];
		e.y2=ytoi[e.y2];
	}
	sort(ALL(eventos));
	ll sum=0;
	fore(i,0,ys.size()-1){
		a[i]=(ys[i+1]-ys[i]);
		sum+=a[i];
	}
	STree st(ys.size()-1);
	st.init(a);
	ll ans=0;
	ll lstx=eventos[0].x;
	for(ev &e:eventos){
		ll dx=e.x-lstx;
		ans+=(dx*((st.query(0,ys.size()-1)+sum)/2));
		st.upd(e.y1,e.y2);
		lstx=e.x;
	}
	cout << ans<<"\n";
    return 0;
}
