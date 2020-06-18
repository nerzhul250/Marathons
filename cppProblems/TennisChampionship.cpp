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
	ll p;
	while(cin >> p){
		ll sum=0;
		while(p!=1){
			if(p%2==0){
				sum+=(p/2);
				p/=2;
			}else{
				sum+=(p/2);
				p/=2;
				p++;
			}
		}
		cout << sum << "\n";
	}
    return 0;
}
