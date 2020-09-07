#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef __int128 ll;
typedef pair<ll,ll> ii;
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		vector<ii> ans;
		ll low=ceil(((2*a*1.0)/b)-2);
		ll up=(2*a)/b;
		for(ll k=low;k<=up;k++){
			if(k>1){
				ll n=(k*(k+1))/2;
				if(((k-1)*a)%b==0){
					n-=(((k-1)*a)/b);
					if(n>=1 && n<=k){
						ans.pb(ii(k,n));
					}
				}
			}
		}
		cout << ans.size()<<"\n";
		fore(i,0,ans.size()){
			cout << ans[i].ff<<" "<<ans[i].ss<<"\n";
		}
	}
    return 0;
}
