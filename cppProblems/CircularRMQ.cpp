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
 
const ll INF=1e18;
struct STree { // example: range sum with range addition
	vector<ll> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=min(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
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
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);
 
int arr[200010];
 
vector<int> ginp(){
	string s="";
	getline(cin,s);
	s+=' ';
	vector<int> inp;
	int curr=0;
	int mult=1;
	fore(i,0,s.size()){
		if(s[i]==' '){
			inp.pb(mult*curr);
			curr=0;
			mult=1;
		}else if(s[i]=='-'){
			mult=-1;
		}else{
			curr*=10;
			curr+=(s[i]-'0');
		}
	}
	return inp;
}
 
int main(){FIN;
	int n=ginp()[0];
	vector<int> nums=ginp();
	fore(i,0,n)arr[i]=nums[i];
	STree st(n);
	st.init(arr);
	int m=ginp()[0];
	while(m--){
		vector<int> inp=ginp();
		if(inp.size()==2){
			int a=inp[0];
			int b=inp[1];
			if(a<=b){
				cout << st.query(a,b+1)<<"\n";
			}else{
				cout << min(st.query(a,n),st.query(0,b+1)) <<"\n";
			}
		}else if(inp.size()==3){
			int a=inp[0];
			int b=inp[1];
			ll v=inp[2];
			if(a<=b){
				st.upd(a,b+1,v);
			}else{
				st.upd(a,n,v);
				st.upd(0,b+1,v);
			}
		}
	}
	return 0;
}
