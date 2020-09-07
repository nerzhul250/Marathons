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
const int INF=1e9;
int consumption[10]={6,2,5,5,4,5,6,3,7,6};
int dp[1000005];
int go(int n){
	if(n<0){
		return -INF;
	}
	if(n==0){
		return 0;
	}
	int &r=dp[n];
	if(r!=-1)return r;
	r=-INF;
	fore(i,0,10){
		r=max(r,i+go(n-consumption[i]));
	}
	return r;
}
int main(){FIN;
	int n;
	cin >> n;
	memset(dp,-1,sizeof dp);
	cout << go(n) << "\n";	
    return 0;
}
