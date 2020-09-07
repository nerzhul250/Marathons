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
ll dp[1005][1005];
ll nck(int n,int k){
	if(k>n)return 0;
	if(k==n || k==0)return 1;
	if(dp[n][k]!=-1)return dp[n][k];
	return dp[n][k]=(nck(n-1,k)+nck(n-1,k-1))%MOD;
}
int main(){FIN;	
	memset(dp,-1,sizeof dp);
	int n,m,k;
	cin >> n >> m >> k;
	ll res=1;
	res*=nck(n-1,2*k);
	res%=MOD;
	res*=nck(m-1,2*k);
	res%=MOD;
	cout << res<<"\n";
    return 0;
}
