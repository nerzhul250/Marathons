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
const int MAXN=10000007;
ll a[1000005];
ll cnt[10000005];
ll cr[MAXN];
vector<ll> primes;
void init_sieve(){
	memset(cr,-1,sizeof(cr));
	fore(i,2,MAXN){
		if(cr[i]<0){
			primes.pb(i);
			for(ll j=1LL*i*i;j<MAXN;j+=i)cr[j]=max((ll)i,cr[j]);
		}
	}
}
int main(){FIN;
	init_sieve();
	int k;
	cin >> k;
	ll r=0;
	fore(i,0,k){
		cin >> a[i];
		r+=a[i];
		cnt[a[i]]++;
	}
	for(int i=MAXN-1;i>=0;i--)cnt[i]+=cnt[i+1];
	for(int i=MAXN-1;i>=0;i--){
		if(cr[i]!=-1){
			cnt[cr[i]]+=cnt[i];
			cnt[i/cr[i]]+=cnt[i];
		}
	}
	fore(i,0,primes.size())cnt[i]=cnt[primes[i]];	
	ll l=1;
	ll ans=-1;
	while(l<=r){
		bool divides=true;
		ll m=(l+r)/2;
		fore(i,0,primes.size()){
			if(cnt[i]>0){
				ll tmp=m;
				ll count=0;
				while(tmp){
					count+=tmp/primes[i];
					tmp/=primes[i];
				}
				if(count<cnt[i]){
					divides=false;
					break;
				}
			}
		}
		if(divides){
			ans=m;
			r=m-1;
		}else{
			l=m+1;
		}
	}
	cout << ans<<"\n";
    return 0;
}
