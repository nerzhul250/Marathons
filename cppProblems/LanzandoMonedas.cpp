#include <bits/stdc++.h>
 
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
 
using namespace std;
 
typedef long long int ll;
ll N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	/*ll ans=1;
	while(N){
		if(N%2==1)ans<<=1;
		N>>=1;
	}
	cout << ans << "\n";*/
	ll ans=1;
	while(true){
		if(N==2){
			ans<<=1;
			break;
		}
		if(N==3){
			ans<<=2;
			break;
		}
		ll faggith=N;
		ll power=0;
		while (faggith >>= 1) ++power;
		ll low=((1L)<<power);
		ll high=low+((1L)<<(power-1));
		if(N>=low && N<high){
			N=N-((1L)<<(power-1));
		}else{
			N=N-low;
			ans<<=1;
		}
	}
	return 0;
}
