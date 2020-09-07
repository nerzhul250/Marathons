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
ll gcd(ll a, ll b){return a?gcd(b%a,a):b;}
int main(){FIN;
	ll la,ra,ta;
	ll lb,rb,tb;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	if(la<lb){
		swap(la,lb);
		swap(ra,rb);
		swap(ta,tb);
	}
	ll d=gcd(ta,tb);
	ll k=((lb-la)-(lb-la)%d)/d;
	if(lb==la)cout << min(rb-lb+1,ra-la+1)<<"\n";
	cout << max(max(min(rb-lb+1-(la-lb+d*k),ra-la+1),min(ra-la+1+(la-lb+d*(k-1)),rb-lb+1)),(ll)0)<<"\n";
    return 0;
}
