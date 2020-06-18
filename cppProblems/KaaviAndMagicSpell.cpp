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
const ll MOD=998244353;
ll dp[3005][3005];
string s,t;
int n,m;
ll go(int i,int j){
	ll &r=dp[i][j];
	if(r!=-1)return r;
	r=0;
	if(j==0 && i+j>=m){
		r+=n-i+1;
		return r;
	}
	if(j-1>=0){
		if(j-1<m){
			if(s[i]==t[j-1]){
				r+=go(i+1,j-1);
			}
		}else{
			r+=go(i+1,j-1);
		}
	}
	if(j+i<n){
		if(j+i<m){
			if(s[i]==t[j+i]){
				r+=go(i+1,j);
			}
		}else{
			r+=go(i+1,j);
		}
	}
	r%=MOD;
	return r;
}
int main(){FIN;
	cin >>s>>t;
	n=s.size();
	m=t.size();
	ll ans=0;
	memset(dp,-1,sizeof dp);
	fore(j,0,n){
		if(j<m){
			if(t[j]==s[0]){
				ans+=go(1,j);
			}
		}else{
			ans+=go(1,j);
		}
	}
	cout << (2*ans)%MOD << "\n";
    return 0;
}
