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
const ll MOD=7+1e9;
ll times[1000005];
ll twoPow[1000005];
int main(){FIN;	
	string s;
	cin >> s;
	fore(i,0,s.size()){
		if(s[i]=='a'){
			times[i]=(i?times[i-1]+1:1);
		}else{
			times[i]=(i?times[i-1]:0);
		}
	}
	twoPow[1]=1;
	fore(i,2,s.size()+1)twoPow[i]=(twoPow[i-1]*2+1)%MOD;
	ll ans=0;
	fore(i,0,s.size()){
		if(s[i]=='b'){
			ans+=twoPow[times[i]];
			ans%=MOD;
		}
	}
	cout << ans << "\n";
    return 0;
}
