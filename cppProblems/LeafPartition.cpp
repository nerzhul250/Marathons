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
const int MAXN=200005;
const ll MOD=998244353;
int n;
vector<int> g[MAXN];
int main(){FIN;
	cin >> n;
	fore(i,0,n-1){
		int p;
		cin >> p;
		g[p-1].pb(i+1);
	}
	vector<vector<ll>> dp(n,vector<ll>(3,0));
	for(int i=n-1;i>=0;i--){
		if(g[i].size()>0){
			dp[i][0]=1;
			for(int v:g[i]){
				ll tmp0=dp[i][0];
				ll tmp1=dp[i][1];
				ll tmp2=dp[i][2];
				dp[i][0]=(tmp0*(dp[v][0]+dp[v][2]))%MOD;
				dp[i][1]=((tmp1*(dp[v][0]+dp[v][2]))%MOD+(tmp0*(dp[v][1]+dp[v][2]))%MOD)%MOD;
				dp[i][2]=((tmp1*(dp[v][1]+dp[v][2]))%MOD+(tmp2*(2*dp[v][2]+dp[v][0]+dp[v][1]))%MOD)%MOD;
				//cout <<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<"\n";
			}
		}else{
			dp[i][2]=1;
		}
	}
	cout << (dp[0][0]+dp[0][2])%MOD<<"\n";
    return 0;
}
