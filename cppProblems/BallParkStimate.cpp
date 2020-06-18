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
	ll n;
	cin >>n;
	ll dig=n;
	ll times=0;
	while(dig>=10)dig/=10,times++;
	ll up=dig+1;
	ll mid=dig;
	ll down=dig-1;
	fore(i,0,times){
		up*=10;
		down*=10;
		mid*=10;
	}
	vector<pair<ll,ll>> dist;
	dist.pb({abs(n-up),-up});
	dist.pb({abs(n-down),-down});
	dist.pb({abs(n-mid),-mid});
	sort(ALL(dist));
	cout << -dist[0].ss<<"\n";
    return 0;
}
