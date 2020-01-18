#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;


typedef long long int ll;

int const maxn=100005;
ll sum[4*maxn],maximum[4*maxn],a[maxn];

void push_up(int v){
	sum[v]=sum[v*2]+sum[v*2+1];
	maximum[v]=max(maximum[v*2],maximum[v*2+1]);
	return ;
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        sum[v]=maximum[v]=a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        push_up(v);
    }
}

void updatemod(int v, int tl, int tr, int ql, int qr, ll x){
	if(tr<ql || qr<tl)return ;
	if(maximum[v]<x)return ;
	if(tl==tr){
		sum[v]%=x;
		maximum[v]%=x;
	}else{
		int m=(tl+tr)/2;
		updatemod(v*2,tl,m,ql,qr,x);
		updatemod(v*2+1,m+1,tr,ql,qr,x);
		push_up(v);
	}
	return ;
}
void update(int v, int tl, int tr, int k, ll x){
	if(tr<k || k<tl)return ;
	if(tl==tr){
		sum[v]=x;
		maximum[v]=x;
	}else{
		int m=(tl+tr)/2;
		update(v*2,tl,m,k,x);
		update(v*2+1,m+1,tr,k,x);
		push_up(v);
	}
	return ;
}

ll query(int v, int tl, int tr, int ql, int qr){
	if(tr<ql || qr<tl)return 0;
	if(ql<=tl && tr<=qr){
		return sum[v];
	}else{
		int m=(tl+tr)/2;
		ll ans=query(v*2,tl,m,ql,qr);
		ans+=query(v*2+1,m+1,tr,ql,qr);
		return ans;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n>>m;
    fore(i,0,n)cin >> a[i];
    build(1,0,n-1);
    fore(i,0,m){
		int type;
		cin >> type;
		if(type==1){
			int l,r;
			cin >> l >> r;
			l--;
			r--;
			cout << query(1,0,n-1,l,r)<<"\n";
		}else if(type==2){
			int l,r;
			ll x;
			cin >> l >> r >> x;
			l--;
			r--;
			updatemod(1,0,n-1,l,r,x);
		}else if(type==3){
			int k;
			ll x;
			cin >> k>>x;
			k--;
			update(1,0,n-1,k,x);
		}
	}
}
