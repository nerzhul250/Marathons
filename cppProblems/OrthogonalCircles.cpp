#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef __int128 i128;
typedef __float128 f128;
typedef long double ld;
typedef long long int ll;
typedef pair<ll,ll> ii;
const ld EPS = 1e-10;
const int INF = 2; // it doesn't actually have to be infinity or a big number

int main(){FIN;
	int n;
	cin >> n;
	map<ii,ll> mp;
	vector<vector<ll>> equations;
	fore(i,0,n){
		ll x,y,r;
		cin >> x >> y >> r;
		if(mp[ii(x,y)]){
			if(mp[ii(x,y)]!=r){
				cout << "-1\n";
				return 0;
			}
		}else{
			mp[ii(x,y)]=r;
			equations.pb({x,y,r});
		}
	}
	n=equations.size();
	if(n<=2){
		cout << "-2\n";
		return 0;
	}
	ll x0=equations[0][0];
	ll y0=equations[0][1];
	ll r0=equations[0][2];
	set<vector<ll>> L;
	fore(i,1,n){
		equations[i][0]-=x0;
		equations[i][1]-=y0;
		ll x=equations[i][0];
		ll y=equations[i][1];
		ll r=equations[i][2];
		equations[i][0]=2*x;
		equations[i][1]=2*y;
		equations[i][2]=x*x+y*y+r0*r0-r*r;
		ll g=abs(__gcd(equations[i][0],__gcd(equations[i][1],equations[i][2])));
		ll sgn=(equations[i][0] < 0 || (equations[i][0] == 0 && equations[i][1] < 0)) ? -1 : 1;
		g*=sgn;
		equations[i][0]/=g;
		equations[i][1]/=g;
		equations[i][2]/=g;
		L.insert(equations[i]);
	}
	
	vector<vector<ll>> temp;
	for(auto e:L)temp.pb(e);
	temp.insert(temp.begin(),equations[0]);
	equations=temp;
	if(equations.size()<=2){
		cout << "-2\n";
		return 0;
	}
	n=equations.size();
	
	i128 a1=equations[1][0],b1=equations[1][1],c1=equations[1][2];
	i128 a2=equations[2][0],b2=equations[2][1],c2=equations[2][2];
	if(a1*b2==a2*b1){
		cout << "-1\n";
	}else{
		i128 yc1=c1*a2-a1*c2,yc2=b1*a2-b2*a1;
		i128 g=__gcd(yc1,yc2);
		if(g<0)g=g*-1;
		yc1/=g;
		yc2/=g;
		i128 xc1=c2*b1-b2*c1,xc2=b1*a2-a1*b2;
		g=__gcd(xc1,xc2);
		if(g<0)g=g*-1;
		xc1/=g;
		xc2/=g;
		fore(i,1,n){
			i128 a=equations[i][0];
			i128 b=equations[i][1];
			i128 c=equations[i][2];
			if(xc1*yc2*a+xc2*yc1*b!=c*xc2*yc2){
				cout << "-1\n";
				return 0;
			}
		}
		f128 f1=f128(xc1)/xc2,f2=f128(yc1)/yc2,f3=r0;
		if(f1*f1+f2*f2-f3*f3>EPS){
			ld xc=f1;
			ld yc=f2;
			ld rr=r0;
			ld rc=sqrt(xc*xc+yc*yc-rr*rr);
			cout << fixed;
			cout << setprecision(9);
			cout << xc+ld(x0) << " " << yc+ld(y0) <<" "<< rc<<"\n"; 
		}else{
			cout << "-1\n";
		}
	}
	return 0;
}
