#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
int main(){FIN;
	int a,b;
	cin>>a>>b;
	int ans = 1;
	fore(i,0,b){
		ans*=a;
		ans%=9;
	}
	if(ans==0){
		ans=9;
	}
	cout<<ans<<"\n";
	return 0;
}
