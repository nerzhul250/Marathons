#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(long long int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
 
using namespace std;
#define oper max
struct STree { // segment tree for max over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e,int v){
		if(st[k]<=v)return -1;
		if(s+1==e)return s;
		int m=(s+e)/2;
		if(st[2*k]>v){
			return query(2*k,s,m,v);
		}else{
			return query(2*k+1,m,e,v);
		}
	}
	void init(int *a){init(1,0,n,a);}
	int query(int v){return query(1,0,n,v);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

int arra[100005],arrb[100005];
int main(){FIN;
	int n; cin>>n;
	STree a(n),b(n);
	fore(i,0,n)cin >> arra[i];
	fore(i,0,n)cin >> arrb[i];
	a.init(arra);
	b.init(arrb);
	int q; cin>>q;
	vector<int> sa(q),sb(q);
	fore(i,0,q)cin>>sa[i];
	fore(i,0,q)cin>>sb[i];
	fore(i,0,q){
		int x=sa[i],y=sb[i];
		int indice1=a.query(x);
		int indice2=b.query(y);
		if(indice1==-1 && indice2==-1){
			cout << "Draw\n";
		}else if(indice1!=-1 && indice2==-1){
			cout << "Mike\n";
		}else if(indice1==-1 && indice2!=-1){
			cout << "Constantine\n";
		}else{
			if(indice1==indice2){
				cout << "Draw\n";
			}else if(indice1<indice2){
				cout << "Mike\n";
			}else{
				cout << "Constantine\n";
			}
		}
	}
	return 0;
}
