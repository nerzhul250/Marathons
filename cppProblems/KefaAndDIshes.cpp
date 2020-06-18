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
int n,m,k;
ll c[20][20];
ll a[20];
ll dp[20][(1<<18)+5];
ll go(int prev,int mask){
	if(__builtin_popcount(mask)==m)return 0;
	ll &r=dp[prev][mask];
	if(r!=-1)return r;
	r=0;
	fore(i,0,n){
		if(((1<<i)&mask)==0){
			r=max(r,c[prev][i]+a[i]+go(i,mask|(1<<i)));	
		}
	}
	return r;
}
int main(){FIN;
	cin >> n >> m >>k;
	fore(i,0,n)cin >> a[i];
	fore(i,0,k){
		int u,v;
		cin >> u >> v;
		u--;v--;
		ll s;
		cin >> s;
		c[u][v]=s;
	}
	memset(dp,-1,sizeof dp);
	cout << go(n,0) << "\n";
    return 0;
}
