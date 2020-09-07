#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,int> ii;
const int MOD=7+1e9;
int dp[1001][251][251];
ii quebabs[1001];
int acum[1001];
int des[250101];
int n,t;
int go(int q,int pos,int h){
	if(q==n)return 1;
	int &r=dp[q][pos][h];
	if(r!=-1)return r;
	r=0;
	if(h+1<=quebabs[q].ff-quebabs[q].ss){
		if(pos+t+1<quebabs[q].ff){
			r+=go(q,pos+t+1,h+1);
		}else{
			if(des[acum[q]+pos+t+1]==-1){
				r+=go(n,0,0);
			}else{
				int nq=des[acum[q]+pos+t+1];
				int npos=acum[q]+pos+t+1-acum[nq];
				r+=go(nq,npos,0);
			}
		}	
	}
	if(pos+1<quebabs[q].ff){
		r+=go(q,pos+1,h);
	}else{
		if(des[acum[q]+pos+1]==-1){
			r+=go(n,0,0);
		}else{
			int nq=des[acum[q]+pos+1];
			int npos=acum[q]+pos+1-acum[nq];
			r+=go(nq,npos,0);
		}
	}
	r%=MOD;
	return r;
}
int main(){FIN;
	freopen("kebab.in","r",stdin);
	freopen("kebab.out","w",stdout);
	cin >> n >> t;
	memset(des,-1,sizeof des);
	fore(i,0,n){
		cin >> quebabs[i].ff >> quebabs[i].ss;
		if(i){
			acum[i]=acum[i-1]+quebabs[i-1].ff;			
			fore(j,acum[i],acum[i]+quebabs[i].ff)des[j]=i;
		}
	}
	fore(i,0,quebabs[0].ff)des[i]=0;
	memset(dp,-1,sizeof dp);
	cout << go(0,0,0)<<"\n";
    return 0;
}
