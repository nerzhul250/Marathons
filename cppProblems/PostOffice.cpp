#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long int ll;
int V,P;
ll x[305];
ll acum[305];
ll cost[305][305];
ll dp[305][35];
int main(){FIN;
	cin >> V >> P;
	fore(i,1,V+1)cin >> x[i];
	fore(i,0,V+1)fore(j,0,P+1)dp[i][j]=1e18;
	for(int i=V;i>=1;i--){
		acum[i]+=acum[i+1];
		acum[i]+=(x[i+1]-x[i])*(V-i);
	}
	dp[0][0]=0;
	fore(i,1,V+1){
		dp[i][0]=0;
		dp[i][0]+=dp[i-1][0];
		dp[i][0]+=(x[i]-x[i-1])*(i-1);
	}
	fore(i,1,V+1){
		fore(j,1,i){
			ll sum=0;
			fore(k,j+1,i)sum+=min(x[k]-x[j],x[i]-x[k]);
			cost[j][i]=sum;
		}
	}
	ll minimo=1e18;
	fore(i,1,V+1){
		fore(p,1,P){
			ll &v=dp[i][p];
			fore(j,1,i){
				v=min(v,dp[j][p-1]+cost[j][i]);
			}
		}
	}
	fore(i,1,V+1){
		minimo=min(minimo,dp[i][P-1]+acum[i]);
	}
	cout << minimo << "\n";
    return 0;
}
