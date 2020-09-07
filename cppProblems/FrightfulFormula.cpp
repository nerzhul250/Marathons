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
const ll MOD=3+1e6;
const int MAXN=200005;
ll lft[MAXN],up[MAXN];
ll fact[500005],invFact[500005];
ll binpow(ll a, ll b){
	ll res=1;
	while(b){
		if(b&1)res*=a,res%=MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
int main(){FIN;
	fact[0]=1;
	invFact[0]=1;
	fore(i,1,500005){
		fact[i]=(fact[i-1]*i)%MOD;
		invFact[i]=binpow(fact[i],MOD-2);
	}
	ll n,a,b,c;
	cin >> n >> a >> b >> c;
	fore(i,0,n)cin >> lft[n-i-1];
	fore(i,0,n)cin >> up[n-i-1];
	ll ans=0;
	//bot->up
	fore(i,0,n-1){
		ll part=1;
		part*=lft[i];
		part=(part*fact[i+n-2])%MOD;
		part=(part*invFact[i])%MOD;
		part=(part*invFact[n-2])%MOD;
		part=(part*binpow(b,i))%MOD;
		part=(part*binpow(a,n-1))%MOD;
		ans=(ans+part)%MOD;
	}
	fore(i,0,n-1){
		ll part=1;
		part*=up[i];
		part=(part*fact[i+n-2])%MOD;
		part=(part*invFact[i])%MOD;
		part=(part*invFact[n-2])%MOD;
		part=(part*binpow(a,i))%MOD;
		part=(part*binpow(b,n-1))%MOD;
		ans=(ans+part)%MOD;
	}
	ll curr=1;
	fore(i,0,n-1){
		ans=(ans+(c*curr)%MOD)%MOD;
		curr=(curr*(a+b))%MOD;
	}
	fore(i,0,n-2){
		ll part=1;
		part=(part*fact[i+n-2])%MOD;
		part=(part*invFact[i])%MOD;
		part=(part*invFact[n-2])%MOD;
		ll part1=binpow(a,n-1);
		part1*=binpow(b,i);
		ll part2=binpow(a,i);
		part2*=binpow(b,n-1);
		part=(part*(part1+part2))%MOD;
		part=(MOD-part)%MOD;
		curr=(curr+part)%MOD;
		ans=(ans+(c*curr)%MOD)%MOD;
		curr=(curr*(a+b))%MOD;
	}
	cout << ans << "\n";
    return 0;
}
