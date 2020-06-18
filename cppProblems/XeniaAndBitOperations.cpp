#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

const int INF=1e9;

#define NEUT INF
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}	
	int xorO(int a,int b){return a^b;}
	int orO(int a,int b){return a|b;}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		if(31-__builtin_clz(e-s)%2==0){
			st[k]=xorO(st[2*k],st[2*k+1]);	
		}else{
			st[k]=orO(st[2*k],st[2*k+1]);
		}
	}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		if(31-__builtin_clz(e-s)%2==0){
			st[k]=xorO(st[2*k],st[2*k+1]);	
		}else{
			st[k]=orO(st[2*k],st[2*k+1]);
		}
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		if(31-__builtin_clz(e-s)%2==0){
			st[k]=xorO(st[2*k],st[2*k+1]);	
		}else{
			st[k]=orO(st[2*k],st[2*k+1]);
		}
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int p, int v){upd(1,0,n,p,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int arr[1<<18];
int main(){FIN;
	int n,m;
	cin >> n >> m;
	fore(i,0,1<<n)cin >> arr[i];
	STree st(1<<n);
	st.init(arr);
	fore(i,0,m){
		int p,b;
		cin >> p >> b;
		p--;
		st.upd(p,b);
		cout << st.query(0,1<<n)<<"\n";		
	}
    return 0;
}
