#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
typedef long long int ll;
ll dp[250005][10][10][3];
//paid,to pay
//0->1,1->2,2->3
ll arr[250005];
int main(){FIN;
	int N,K;
	cin >> N >> K;
	fore(i,1,N+1){
		cin >> arr[i];
	}
	fore(j,0,K+1){
		fore(k,0,K+1){
			fore(l,0,3){
				if(j!=k || l==2){
					dp[0][j][k][l]=1e18;
				}
			}
		}
	}
	fore(i,1,N+1){
		fore(j,0,K+1){
			fore(k,0,K+1){
				fore(l,0,3){
					ll &r=dp[i][j][k][l];
					r=1e18;
					r=min(r,arr[i]+dp[i-1][j][k][0]);
					if(k!=K)r=min(r,dp[i-1][j][k+1][0]);
					if(l!=2){
						r=min(r,dp[i-1][j][k][l+1]);
						if(j!=K)r=min(r,arr[i]+dp[i-1][j+1][k][l+1]);
					}	
				}
			}
		}
	}
	cout << dp[N][0][0][1]<<"\n";
    return 0;
}
