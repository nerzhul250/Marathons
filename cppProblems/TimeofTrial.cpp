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
typedef pair<ll,ll> l2;
ll a[100005],b[100005];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n)cin >> a[i];
	fore(i,0,n)cin >> b[i];
	bool redemption=false;
	vector<l2> events;
	fore(i,0,n)events.pb(l2(a[i],b[i]));
	sort(ALL(events));
	ll acum=0;
	fore(i,0,events.size()){
		acum+=events[i].ss;
		if(acum>=events[i].ff){
			redemption=true;
			break;
		}
	}
	if(redemption){
		cout << "Redemption\n";
	}else{
		cout << "Dire victory\n";
	}
    return 0;
}
