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
int main(){FIN;
	ll r1,r2;
	cin >> r1 >> r2;
	int n;
	cin >> n;
	fore(i,0,n){		
		ll consumption;
		cin >> consumption;
		cout << consumption <<" ";
		if(consumption>1000){
			cout << 1000*r1 + (consumption-1000)*r2 << "\n";
		}else{
			cout << consumption*r1<<"\n";
		}
	}
    return 0;
}
