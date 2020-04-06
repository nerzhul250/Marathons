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

const ll MOD=998244353;

ll answers[200005];
int main(){FIN;
	int n;
	cin >> n;
	answers[n]=10;
	ll ten=1;
	for(ll b=n-2;b>=0;b--){
		if(b!=n-2)ten*=10;
		ten%=MOD;
		ll part=(180+81*(n-b-2));
		part%=MOD;
		answers[b+1]=(ten*part)%MOD;
	}
	fore(i,1,n+1){
		if(i==n){
			cout << answers[i] <<"\n";
		}else{
			cout << answers[i] << " ";
		} 
	}
    return 0;
}
