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
ll dp[105][105];
ll heights[105][105];
ll a;
ll go(int i,int j){
	ll &r=dp[i][j];
	if(r!=-1)return r;
	ll b=a+i+j;
	if(i==0 && j==0){
		return r=heights[0][0]-b;
	}
	if(b<=heights[i][j]){
		ll cost=heights[i][j]-b;
		r=1e18;
		if(i-1>=0){
			ll up=go(i-1,j);
			if(up!=-2)r=up;
		}
		if(j-1>=0){
			ll left=go(i,j-1);
			if(left!=-2)r=min(r,left);
		}
		if(r!=1e18){
			r+=cost;
		}else{
			r=-2;
		}
	}else{
		r=-2;
	}
	return r;
}
int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		int n,m;
		cin >>n>>m;
		fore(i,0,n){
			fore(j,0,m){
				cin >> heights[i][j];
			}
		}
		ll minCost=1e18;
		fore(i,0,n){
			fore(j,0,m){
				if(heights[i][j]-i-j<=heights[0][0]){
					a=heights[i][j]-i-j;
					fore(k,0,n){
						fore(l,0,m){
							dp[k][l]=-1;
						}
					}
					ll cost=go(n-1,m-1);
					if(cost!=-2){
						minCost=min(minCost,cost);
					}
				}
			}
		}
		cout << minCost<<"\n";
	}
    return 0;
}

