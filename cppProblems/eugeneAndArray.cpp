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
typedef pair<int,int> ii;

ll arr[200005];
int n;
int main(){FIN;
	cin >> n;
	fore(i,1,n+1)cin >> arr[i];
	map<ll,ll> acum;
	acum[0]=0;
	ll sum=0;
	ll last=0;
	ll ans=0;
	fore(i,1,n+1){
		sum+=arr[i];
		if(acum.count(sum)){
			last=max(last,acum[sum]+1);
		}
		acum[sum]=i;
		ans+=(i-last);
	}
	cout << ans << "\n";
    return 0;
}
