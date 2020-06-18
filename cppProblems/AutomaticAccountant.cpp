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
typedef long long int ll;

struct STree { // segment tree for min over integers
	vector<ii> st;int n;
	STree(int n): st(4*n+5,ii(-1,1e9)), n(n) {}
	ii opera(ii a, ii b){
		return ii(max(a.ff,b.ff),min(a.ss,b.ss));
	}
	void init(int k, int s, int e, ii *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=opera(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e,ii v){
		if(s+1==e)return s;
		int m=(s+e)/2;
		int ans=-1;
		if(st[2*k].ff>=v.ff && st[2*k].ss<=v.ss){
			ans=query(2*k,s,m,v);
			if(ans!=-1)return ans;
		}
		if(st[2*k+1].ff>=v.ff && st[2*k+1].ss<=v.ss){
			return query(2*k+1,m,e,v);
		}
		return ans;
	}
	void init(ii *a){init(1,0,n,a);}
	int query(ii v){return query(1,0,n,v);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);


int main(){FIN;
	int s;
	cin >> s;
	ii slots[s+1];
	STree st(s);
	fore(i,0,s){
		ii a;
		cin >> a.ff >> a.ss;
		slots[i]=a;
	}
	st.init(slots);
	int c;
	cin >> c;
	ll acum=0;
	fore(i,0,c){
		ii a;
		cin >> a.ff >> a.ss;
		acum=acum+st.query(a)+1;
	}
	cout << acum << "\n";
    return 0;
}
