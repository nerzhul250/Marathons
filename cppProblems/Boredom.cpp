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
typedef pair<ll,int> ii;
ll cnt[100005];
ll arr[100005];
ll dp[100005];
int n;
ll f(int i){
	if(i>=n)return 0;
	if(dp[i]!=-1)return dp[i];
	return dp[i]=max(f(i+1),f(i+2)+cnt[arr[i]]*arr[i]);
}
int main(){FIN;
	cin >> n;
	memset(dp,-1,sizeof dp);
	ll mi=1e8;
	ll ma=-1;
	fore(i,0,n){
		cin >> arr[i];
		cnt[arr[i]]++;
		ma=max(ma,arr[i]);
		mi=min(mi,arr[i]);
	}
	fore(i,0,ma-mi+1)arr[i]=mi+i;
	sort(begin(arr),begin(arr)+n);
	auto it=unique(begin(arr),begin(arr)+n);
	n=(it-begin(arr));
	cout << f(0)<<"\n";
    return 0;
}
