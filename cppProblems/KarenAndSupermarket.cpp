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
const ll INF=1e18;
int par[5005];
ll cost[5005],d[5005];
ll dp[5005][2][5005];
int sz[5005];
int main(){FIN;
	int n;
	ll b;
	cin >> n >> b;
	cin >> cost[0] >> d[0];
	d[0]=cost[0]-d[0];
	fore(i,1,n){
		cin >> cost[i] >> d[i] >> par[i];
		par[i]--;
		d[i]=cost[i]-d[i];
	}
	fore(i,0,n){
		sz[i]=1;
		dp[i][0][0]=0;
		dp[i][1][0]=INF;
		dp[i][0][1]=cost[i];
		dp[i][1][1]=d[i];
		fore(j,2,n+1){
			dp[i][0][j]=INF;
			dp[i][1][j]=INF;
		}
	}
	for(int v=n-1;v>0;v--){
		int u=par[v];
		fore(i,0,sz[v]+1)dp[v][1][i]=min(dp[v][1][i],dp[v][0][i]);
		for(int i=sz[u];i>=0;i--){
			for(int j=sz[v];j>=0;j--){
				fore(k,0,2){
					dp[u][k][i+j]=min(dp[u][k][i+j],dp[u][k][i]+dp[v][k][j]);
				}
			}
		}
		sz[u]+=sz[v];
	}
	fore(i,0,sz[0]+1)dp[0][1][i]=min(dp[0][0][i],dp[0][1][i]);
	int ans=0;
	while(ans<sz[0] && dp[0][1][ans+1]<=b)ans++;
	cout << ans << "\n";
    return 0;
}
