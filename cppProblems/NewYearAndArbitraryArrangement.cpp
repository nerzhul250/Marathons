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
ll const MOD=7+1e9;
ll binpow(ll a, ll b){
	ll res=1;
	while(b){
		if(b&1)res=(res*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
ll inverse(ll a){
	return binpow(a,MOD-2);
}
ll mulmod(ll a, ll b){
	return (a*b)%MOD;
}
ll dp[1005][1005];
ll k,pa,pb;
ll go(int i,int j){
	if(i+j>=k){
		ll prt1=1;
		prt1=mulmod(prt1,pb);
		prt1=mulmod(prt1,inverse(pa+pb));
		ll prt2=1;
		prt2=mulmod(prt2,pa);
		prt2=mulmod(prt2,inverse(pa+pb));
		ll prt3=1;
		prt3=mulmod(prt3,prt2);
		prt3=mulmod(prt3,MOD-1);
		prt3=(prt3+1)%MOD;
		prt3=inverse(prt3);
		ll ans=prt1;
		ans=mulmod(ans,prt3);
		ans=mulmod(ans,(i+j+(mulmod(prt2,prt3))%MOD)%MOD);
		return ans;
	}
	ll &r=dp[i][j];
	if(r!=-1)return r;
	r=1;
	r=mulmod(r,pa);
	r=mulmod(r,go(i+1,j));
	ll sec=1;
	sec=mulmod(sec,pb);
	sec=mulmod(sec,go(i,i+j));
	r=(r+sec)%MOD;
	r=mulmod(r,inverse(pa+pb));
	return r;
}
int main(){FIN;
	cin >> k >> pa >> pb;
	memset(dp,-1,sizeof dp);
	cout << go(1,0)<<"\n";	
    return 0;
}
