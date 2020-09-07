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
ll dp[105][12];
ll comb[105][105];
ll nck(int n,int k){
	if(n==k || k==0)return 1;
	if(comb[n][k]!=-1)return comb[n][k];
	return comb[n][k]=(nck(n-1,k-1)+nck(n-1,k))%MOD;
}
int a[12];
int n;
ll go(int L,int i){
	if(L<0)return 0;
	if(L==0){
		if(i==10){
			return 1;
		}else if(a[i]>0){
			return 0;
		}else{
			return go(L,i+1);
		}
	}
	if(i==10){
		return 0;
	}
	ll &r=dp[L][i];
	if(r!=-1)return r;
	r=0;
	fore(j,max(a[i],0),L+1){
		r+=(nck(L,j)*go(L-j,i+1))%MOD;
		r%=MOD;
	}
	return r;
}
int main(){FIN;
	memset(comb,-1,sizeof comb);
	cin >> n;
	fore(i,0,10)cin >> a[i];
	ll ans=0;
	fore(L,1,n+1){
		fore(i,1,10){
			a[i]--;
			memset(dp,-1,sizeof dp);
			ans+=go(L-1,0);
			ans%=MOD;
			a[i]++;
		}
	}
	cout << ans << "\n";
    return 0;
}
