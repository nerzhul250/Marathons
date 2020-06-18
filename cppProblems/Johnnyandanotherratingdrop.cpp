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
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll ans=0;
		fore(i,1,63){
			ll num=(n+(1LL<<(i-1)))/(1LL<<i);
			ans+=(num*i);
		}
		cout << ans<<"\n";
	}
    return 0;
}
