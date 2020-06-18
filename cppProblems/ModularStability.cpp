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
const ll MOD=998244353;
ll factMod[500005];
ll factInvMod[500005];

ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}

ll euclid(ll a, ll b, ll& x, ll& y){ // a*(x+k*(b/d))+b*(y-k*(a/d))=d
	if(!b){x=1;y=0;return a;}          // (for any k)
	ll d=euclid(b,a%b,x,y);
	ll t=y;y=x-(a/b)*y;x=t;
	return d;
}

ll inv(ll a, ll mod) { //inverse of a modulo mod
	assert(gcd(a,mod)==1);
	ll x,y;
	euclid(a,mod,x,y);
	return (x+mod)%mod;
}
int main(){FIN;
	ll currFact=1;
	factMod[0]=1;
	factInvMod[0]=1;
	fore(i,1,500005){
		currFact*=i;
		currFact%=MOD;
		factMod[i]=currFact;
		factInvMod[i]=inv(currFact,MOD);
	}
	int n,k;
	cin >>n>>k;
	k--;
	ll sum=0;
	fore(i,1,n+1){
		int num=n/i;
		num--;
		if(num>=k){
			ll x=factMod[num];
			x*=factInvMod[num-k];
			x%=MOD;
			x*=factInvMod[k];
			x%=MOD;
			sum+=x;
			sum%=MOD;	
		}
	}
	cout << sum << "\n";
    return 0;
}
