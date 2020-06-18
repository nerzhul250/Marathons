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
const ll MOD=11092019;
ll freq[30];
int main(){FIN;
	string s;
	cin >> s;
	fore(i,0,s.size()){
		freq[s[i]-'a']++;
	}
	ll ans=1;
	fore(i,0,26){
		ans*=(freq[i]+1);
		ans%=MOD;
	}
	cout << ans << "\n";
    return 0;
}
