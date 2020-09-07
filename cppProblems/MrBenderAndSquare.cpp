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
typedef pair<int,ll> ii;
int main(){FIN;
	ll n,x,y,c;
	cin >> n >> x >> y >> c;
	ll l=0,r=2*n;
	ll ans=0;
	while(l<=r){
		ll mid=(l+r)/2;
		ll totalArea=1+2*mid*(mid+1);
		if(x-mid<1){
			ll out=1-(x-mid);
			totalArea-=(out*out);
		}
		if(x+mid>n){
			ll out=x+mid-n;
			totalArea-=(out*out);
		}
		if(y+mid>n){
			ll out=y+mid-n;
			totalArea-=(out*out);
			ll hight=1-(x-mid+(n+1-y));
			if(hight>0)totalArea+=(((hight+1)*hight)/2);	
			hight=(x+mid-(n+1-y))-n;
			if(hight>0)totalArea+=(((hight+1)*hight)/2);
		}
		if(y-mid<1){
			ll out=1-(y-mid);
			totalArea-=(out*out);
			ll hight=1-(x-mid+y);
			if(hight>0)totalArea+=(((hight+1)*hight)/2);
			hight=(x+mid-y)-n;
			if(hight>0)totalArea+=(((hight+1)*hight)/2);
		}
		if(totalArea>=c){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	cout << ans << "\n";
    return 0;
}
