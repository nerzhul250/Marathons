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
ll fact[250005];
int main(){FIN;
	ll n,m;
	cin >> n>> m;
	fact[0]=1;
	fore(i,1,n+1){
		ll nam=i;
		fact[i]=(nam*fact[i-1])%m;
	}
	ll sum=0;
	fore(i,1,n+1){
		ll nam=i;
		ll res=1;
		res*=fact[i];
		res*=(n-nam+1);
		res%=m;
		res*=(n-nam+1);
		res%=m;
		res*=fact[n-i];
		res%=m;
		sum+=res;
		sum%=m;
	}
	cout << sum << "\n";
    return 0;
}
