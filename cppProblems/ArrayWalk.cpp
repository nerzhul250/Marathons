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
ll arr[100005];
ll dp[100005][6];
int n,k,z;
ll go(int pos,int left){
	if(pos+2*left==k){
		return arr[pos];
	}
	ll &r=dp[pos][left];
	if(r!=-1)return r;
	if(left<z && pos-1>=0){
		r=go(pos-1,left+1);
	}
	r=max(r,go(pos+1,left));
	r+=arr[pos];
	return r;
}
int main(){FIN;	
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k >> z;
		fore(i,0,n)cin >> arr[i];
		memset(dp,-1,sizeof dp);
		cout << go(0,0)<<"\n";
	}
    return 0;
}
