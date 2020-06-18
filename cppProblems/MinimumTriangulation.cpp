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
ll dp[505][505];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,2,n){
		fore(j,0,n){
			ll &v=dp[j][(j+i)%n];
			v=1e18;
			fore(k,j+1,j+i){
				v=min(v,(j+1)*((k%n)+1)*(((j+i)%n)+1)+dp[j][k%n]+dp[k%n][(j+i)%n]);	
			}
		}
	}
	ll minimumWeight=1e18;
	fore(i,0,n)minimumWeight=min(minimumWeight,dp[i][(i+n-1)%n]);
	cout << minimumWeight<<"\n";
    return 0;
}

