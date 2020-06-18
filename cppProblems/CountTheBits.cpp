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
ll MOD=9+1e9;
const ll INF=1e18;
ll dp[133][1005],dp2[133][1005];
int main(){FIN;
	int k,b;
	cin >> k >> b;
	fore(i,1,k)dp[0][i]=INF;
	fore(i,1,k)dp2[0][i]=0;
	dp2[0][0]=1;
	int rem=1%k;
	fore(i,1,b+1){
		fore(j,0,k)dp2[i][j]=(dp2[i-1][j]+dp2[i-1][(j+rem)%k])%MOD;
		fore(j,0,k){
			if(dp[i-1][j]==INF && dp[i-1][(j+rem)%k]==INF){
				dp[i][j]=INF;
			}else if(dp[i-1][j]==INF){
				dp[i][j]=(dp2[i-1][(j+rem)%k]+dp[i-1][(j+rem)%k])%MOD;
			}else if(dp[i-1][(j+rem)%k]==INF){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=(dp[i-1][j]+dp2[i-1][(j+rem)%k]+dp[i-1][(j+rem)%k])%MOD;
			}
			//cout << dp[i][j]<<" ";
		}
		//cout <<endl;
		rem*=2;
		rem%=k;
	}
	cout << dp[b][0] << "\n";
    return 0;
}
