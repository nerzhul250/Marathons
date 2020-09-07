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
const ll MOD=7+1e9;
ll fact[1000006];
ll inv[1000006];
int a,b,n;
ll powmod(ll a,ll b){
	ll res=1;
	while(b){
		if(1&b){
			res=(res*a)%MOD;
		}
		a=(a*a)%MOD;
		b>>=1;
	}
	return res;
}
bool good(int num){
	bool nice=true;
	while(num){
		if(num%10==a || num%10==b){
			num/=10;
		}else{
			nice=false;
			break;
		}
	}
	return nice;
}
int main(){FIN;
	ll curr=1;
	fore(i,1,1000006){
		curr*=i;
		curr%=MOD;
		fact[i]=curr;
		inv[i]=powmod(curr,MOD-2);
	}
	inv[0]=1;
	cin >> a >> b >> n;
	ll ans=0;
	fore(i,0,n+1){
		int sum=a*i+b*(n-i);
		if(good(sum)){
			ll toSum=(fact[n]*inv[i])%MOD;
			toSum=(toSum*inv[n-i])%MOD;
			ans+=toSum;
			ans%=MOD;
		}
	}
	cout << ans<<"\n";
    return 0;
}
