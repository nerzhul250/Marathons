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
typedef pair<int,int> ii;
const ll MOD=7+1e9;
const int MAXN=2005;
const int MAXF=1000005;
ll dp[MAXN];
ll fact[MAXF],invFact[MAXF];
ii obs[MAXN];
ll binpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1)res*=a,res%=MOD;
		b>>=1;
		a=(a*a)%MOD;
	}
	return res;
}
int main(){FIN;
	int h,w,n;
	cin >> h >> w >> n;
	fact[0]=1;
	invFact[0]=1;
	fore(i,1,h+w+1){
		fact[i]=(i*fact[i-1])%MOD;
		invFact[i]=binpow(fact[i],MOD-2);
	}
	map<int,vector<int>> mp;
	fore(i,0,n){
		int y,x;
		cin >> y >> x;
		y--;
		x--;
		mp[x+y].pb(i+1);
		obs[i+1]=ii(y,x);
	}
	mp[0].pb(0);
	obs[0]=ii(0,0);
	mp[h+w-2].pb(n+1);
	obs[n+1]=ii(h-1,w-1);
	
	vector<vector<int>> diag;
	for(auto it=mp.begin();it!=mp.end();it++)diag.pb(it->ss);
	fore(i,1,diag.size()){
		fore(j,0,diag[i].size()){
			int pt=diag[i][j];
			int y=obs[pt].ff;
			int x=obs[pt].ss;
			dp[pt]=(((fact[x+y]*invFact[x])%MOD)*invFact[y])%MOD;
			fore(l,0,i){
				fore(k,0,diag[l].size()){
					int prev=diag[l][k];
					int yprev=obs[prev].ff;
					int xprev=obs[prev].ss;
					int dy=y-yprev;
					int dx=x-xprev;
					ll paths=0;
					if(dy>=0 && dx>=0){
						paths=(((fact[dx+dy]*invFact[dx])%MOD)*invFact[dy])%MOD;
					}
					ll res=(MOD-((dp[prev]*paths)%MOD))%MOD;
					dp[pt]+=res;
					dp[pt]%=MOD;
				}
			}
		}
	}
	cout << dp[n+1]<<"\n";
    return 0;
}
