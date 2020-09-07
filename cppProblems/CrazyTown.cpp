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
	ll x1,y1;
	cin >> x1 >> y1;
	ll x2,y2;
	cin >> x2 >> y2;
	int n;
	cin >> n;
	int cnt=0;
	fore(i,0,n){
		ll a,b,c;
		cin >> a >> b >> c;
		ll val1=a*x1+b*y1+c;
		ll val2=a*x2+b*y2+c;
		if((val1>0 && val2<0) || (val2>0 && val1<0))cnt++;
	}
	cout << cnt << "\n";
    return 0;
}
