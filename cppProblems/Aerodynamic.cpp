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
typedef pair<ll,ll> ii;


int main(){FIN;
	int n;
	cin >> n;
	vector<ii> pol;
	fore(i,0,n){
		ll x,y;
		cin >> x >> y;
		pol.pb(ii(x,y));
	}
	if(pol.size()%2==0){
		bool cs=true;
		set<ii> midPoints;
		fore(i,0,n/2){
			ll x1=pol[i].ff,y1=pol[i].ss;
			ll x2=pol[i+n/2].ff,y2=pol[i+n/2].ss;
			midPoints.insert(ii(y2-y1+2*y1,x2-x1+2*x1));
		}
		if(midPoints.size()==1){
			cout <<"YES\n";
		}else{
			cout <<"NO\n";
		}
	}else{
		cout << "NO\n";
	}
    return 0;
}

