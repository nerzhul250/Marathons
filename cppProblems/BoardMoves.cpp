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
ll ans[500005];
int main(){FIN;
	int t;
	cin >> t;
	ans[1]=0;
	ll k=3;
	while(k<500000){
		ans[k]=ans[k-2]+(4*k-4)*((k-1)/2);
		k+=2;
	}
	while(t--){
		int n;
		cin >> n;
		cout << ans[n]<<"\n";
	}
    return 0;
}

