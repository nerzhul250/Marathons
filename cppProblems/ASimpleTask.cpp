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
	vector<int> st,lazy;int n;
	STree(){}
	STree(int n): st(4*n+5,0), lazy(4*n+5,-1), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=-1;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(lazy[k]==-1)return; // if neutral, nothing to do
		st[k]=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=lazy[k];
			lazy[2*k+1]=lazy[k];
		}
		lazy[k]=-1; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=v;
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; //operation
	}
	int query1(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0;//operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query1(2*k,s,m,a,b)+query1(2*k+1,m,e,a,b);
	}
	int query2(int k,int s,int e,int p){
		if(p<s || p>=e)return 0;
		push(k,s,e);
		if(s+1==e)return st[k];
		int m=(s+e)/2;
		return query2(k*2,s,m,p)+query2(k*2+1,m,e,p);
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query1(int a, int b){return query1(1,0,n,a,b);}
	int query2(int p){return query2(1,0,n,p);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
STree sgtree[30];
int arreglos[30][100005];
int main(){FIN;
	int n,Q;
	cin >> n >> Q;
	string s;
	cin >> s;
	fore(i,0,s.size()){
		arreglos[s[i]-'a'][i]=1;
	}
	fore(i,0,26){
		sgtree[i]=STree(n);
		sgtree[i].init(arreglos[i]);
	}
	fore(q,0,Q){
		int i,j,k;
		cin >> i >> j >> k;
		i--;j--;
		if(k==0){
			int currIndex=i;
			for(int let=25;let>=0;let--){
				int nums=sgtree[let].query1(i,j+1);
				sgtree[let].upd(i,j+1,0);
				if(nums==0)continue;
				sgtree[let].upd(currIndex,currIndex+nums,1);
				currIndex+=nums;
			}
		}else if(k==1){
			int currIndex=i;
			for(int let=0;let<26;let++){
				int nums=sgtree[let].query1(i,j+1);
				sgtree[let].upd(i,j+1,0);
				if(nums==0)continue;
				sgtree[let].upd(currIndex,currIndex+nums,1);
				currIndex+=nums;
			}
		}
	}
	string ans="";
	fore(i,0,n){
		fore(let,0,26){
			int val=sgtree[let].query2(i);
			if(val==1){
				char c='a'+let;
				ans+=c;
			}else if(val!=0){
				assert(false);
			}
		}
	}
	cout << ans << "\n";
    return 0;
}
