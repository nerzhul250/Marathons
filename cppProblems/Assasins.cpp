#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
double dp[(1<<15)+5][2];
int n,m;
int ass[1005],vict[1005];
double prob[1005];
int main(){FIN;
	cin >> n >> m;
	fore(i,0,m){
		cin >> ass[i] >> vict[i] >> prob[i];
		ass[i]--;
		vict[i]--;
	}
	int r=0;
	dp[(1<<n)-1][r]=1;
	fore(moment,0,m){
		r^=1;
		double probLeft=1-prob[moment];
		double probRight=prob[moment];		
		int assasin=ass[moment];
		int victim=vict[moment];
		fore(mask,0,1<<n)dp[mask][r]=0;
		fore(mask,0,1<<n){
			if((mask&(1<<assasin)) && (mask&(1<<victim))){
				int rightMask=mask^(1<<victim);
				dp[mask][r]+=probLeft*dp[mask][r^1];
				dp[rightMask][r]+=probRight*dp[mask][r^1];
			}else{
				dp[mask][r]=dp[mask][r^1];
			}
		}
	}
	double probs[n];
	fore(i,0,n)probs[i]=0;
	fore(mask,0,(1<<n)){
		fore(i,0,n){
			if((1<<i)&mask){
				probs[i]+=dp[mask][r];
			}
		}
	}
	cout << fixed;
	cout << setprecision(10);
	fore(i,0,n)cout << probs[i]<<"\n";
    return 0;
}

