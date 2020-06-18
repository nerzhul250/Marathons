#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

const int INF=1000000005;

int gcd(int a,int b){return a?gcd(b%a,a):b;}

struct node{
	int g,min,numMin;
	node(): g(0),min(INF),numMin(0) {}
};
#define NEUT node()
struct STree { // segment tree for min over integers
	vector<node> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){
			st[k].g=a[s];
			st[k].min=a[s];
			st[k].numMin=1;
			return;
		}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k].min=min(st[2*k].min,st[2*k+1].min);
		st[k].g=gcd(st[2*k].g,st[2*k+1].g);
		if(st[k].min==st[2*k].min){
			st[k].numMin+=st[2*k].numMin;
		}
		if(st[k].min==st[2*k+1].min){
			st[k].numMin+=st[2*k+1].numMin;
		}
	}
	node query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		node nodo=node();
		node left=query(2*k,s,m,a,b);
		node right=query(2*k+1,m,e,a,b);
		nodo.min=min(left.min,right.min);
		nodo.g=gcd(left.g,right.g);
		if(nodo.min==left.min){
			nodo.numMin+=left.numMin;
		}
		if(nodo.min==right.min){
			nodo.numMin+=right.numMin;
		}
		return nodo;
	}
	void init(int *a){init(1,0,n,a);}
	node query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);


int main(){FIN;
	int n;
	cin >> n;
	int arr[n+1];
	fore(i,0,n)cin >> arr[i];
	STree st(n);
	st.init(arr);
	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		l--;
		node ndo=st.query(l,r);
		int ans=r-l;
		if(ndo.min==ndo.g){
			ans-=(ndo.numMin);
		}
		cout << ans << "\n";
	}
    return 0;
}
