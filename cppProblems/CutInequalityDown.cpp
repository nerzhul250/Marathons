#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
 
struct node{
	ll mx,mn,sum;
	node(){}
	node(ll mx, ll mn, ll sum):mx(mx),mn(mn),sum(sum){}
};
 
node merge(node l, node r){
	node ans;
	ans.mx=max(l.mx,l.sum+r.mx);
	ans.mn=min(l.mn,l.sum+r.mn);
	ans.sum=l.sum+r.sum;
	return ans;
}
 
ll n,up,dw;
node NEUT(-1e18,1e18,0);
struct STree {
	vector<node> st;int n;
	STree(){}
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void upd(int k, int s, int e, int p, int v){
		if(s+1==e){st[k]=node(v,v,v);return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=merge(st[2*k],st[2*k+1]);
	}
	ii query(int k, int s, int e, int pos, int x){
		if(e<=pos)return {n,x};
		if(s>=pos){
			ll mn=x+st[k].mn,mx=x+st[k].mx;
			if(dw<mn&&mx<up) return {n,x+st[k].sum};
			if(s+1==e) return {s,min(up,max(dw,mx))};
		}
		int m=(s+e)/2;
		ii myl=query(2*k,s,m,pos,x);
		if(myl.fst<n) return myl;
		return query(2*k+1,m,e,pos,myl.snd);
	}
	void upd(int p, int v){upd(1,0,n,p,v);}
	ii query(int a, int b){return query(1,0,n,a,b);}
};
 
STree st;
 
ii get(int p, ll x){
	ii ans=st.query(p,x);
	if(ans.fst<n)ans.fst++;
	ans.snd=ans.snd>=up;
	return ans;
}
 
const int K=17;
ii par[1<<K][2][K];
ll ps[1<<K];
 
ll getsum(int l, int r){
	if(l>r)return 0;
	return ps[r]-(l?ps[l-1]:0);
}
 
int main(){FIN;
	cin>>n>>dw>>up;
	st=STree(n);
	vector<ll> a(n);
	fore(i,0,n){
		cin>>a[i];
		st.upd(i,a[i]);
		ps[i]=a[i]+(i?ps[i-1]:0);
	}
	fore(i,0,n){
		par[i][0][0]=get(i,dw);
		par[i][1][0]=get(i,up);
	}
	par[n][0][0]=par[n][1][0]={n,0};
 
	fore(k,1,K) fore(i,0,n+1) fore(j,0,2){
		ii myp=par[i][j][k-1];
		par[i][j][k]=par[myp.fst][myp.snd][k-1];
	}
	
	int q; cin>>q;
	while(q--){
		int l,r,x; cin>>l>>r>>x; l--; r--;
		ii now=get(l,x);
		if(now.fst>r) cout << max(min(x+getsum(l,r),up),dw) << "\n";
		else{
			for(int k=K-1;k>=0;k--) if(par[now.fst][now.snd][k].fst<=r){
				now=par[now.fst][now.snd][k];
			}
			ll ans=now.snd?up:dw;
			ans+=getsum(now.fst,r);
			cout << max(min(ans,up),dw) << "\n";
		}
	}
}
