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
	int t;
	cin >>t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		if(b>a){
			int cnt=0;
			while(b>=(a<<3)){
				a<<=3;
				cnt++;
			}
			while(b>=(a<<2)){
				a<<=2;
				cnt++;
			}
			while(b>=(a<<1)){
				a<<=1;
				cnt++;
			}
			if(b!=a){
				cout << "-1\n";
			}else{
				cout << cnt << "\n";
			}
		}else if(b<a){
			int cnt=0;
			while(a%8==0 && b<=(a>>3)){
				a>>=3;
				cnt++;
			}
			while(a%4==0 && b<=(a>>2)){
				a>>=2;
				cnt++;
			}
			while(a%2==0 && b<=(a>>1)){
				a>>=1;
				cnt++;
			}
			if(b!=a){
				cout << "-1\n";
			}else{
				cout << cnt << "\n";
			}
		}else{
			cout << "0\n";
		}
	}
    return 0;
}
