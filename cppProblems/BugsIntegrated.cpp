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
int powers[10]={1,3,9,27,81,243,729,2187,6561,19683};
int decimalToTernary[59054][15];
int dp[5][15][59054];
int bad[155][15];
int N,M,K;
int main(){FIN;
	int D;
	cin >> D;
	fore(mask,0,59049){
		int msk=mask;
		fore(i,0,10){
			decimalToTernary[mask][i]=msk%3;
			msk-=(msk%3);
			msk/=3;
		}
	}
	while(D--){
		cin >> N >> M >> K;
		memset(dp,0,sizeof dp);
		memset(bad,0,sizeof bad);
		fore(i,0,K){
			int n,m;
			cin >> n >> m;
			n--;
			m--;
			bad[n][m]=1;
		}
		int MASK=1;
		fore(i,0,M)MASK*=3;
		int r0=0,r1=1;
		for(int m=M-1;m>=0;m--){
			fore(mask,0,MASK){
				int &v=dp[r0][m][mask];
				v=0;
				if(m+1==M){
					v=max(v,dp[r1][0][mask-decimalToTernary[mask][m]*powers[m]+2*powers[m]]);
				}else{
					v=max(v,dp[r0][m+1][mask-decimalToTernary[mask][m]*powers[m]+2*powers[m]]);
				}
				if(m<M-2 &&
				   decimalToTernary[mask][m]==0 &&
				   decimalToTernary[mask][m+1]==0 &&
				   decimalToTernary[mask][m+2]==0){
					   v=max(v,1+dp[r0][m+1][mask+2*(powers[m]+powers[m+1]+powers[m+2])]); 
					}
			}
		}
		for(int n=N-3;n>=0;n--){
			r0++;
			r1++;
			r0%=2;
			r1%=2;
			for(int m=M-1;m>=0;m--){
				fore(mask,0,MASK){
					int &v=dp[r0][m][mask];
					v=0;
					if(m+1==M){
						if(bad[n+2][m]){
							v=max(v,dp[r1][0][mask-decimalToTernary[mask][m]*powers[m]+2*powers[m]]);
						}else{
							if(decimalToTernary[mask][m]==2){
								v=max(v,dp[r1][0][mask-powers[m]]);
							}else{
								v=max(v,dp[r1][0][mask-decimalToTernary[mask][m]*powers[m]]);
							}
						}
					}else{
						if(bad[n+2][m]){
							v=max(v,dp[r0][m+1][mask-decimalToTernary[mask][m]*powers[m]+2*powers[m]]);	
						}else{
							if(decimalToTernary[mask][m]==2){
								v=max(v,dp[r0][m+1][mask-powers[m]]);
							}else{
								v=max(v,dp[r0][m+1][mask-decimalToTernary[mask][m]*powers[m]]);
							}
						}
						if(m<M-2 &&
						   decimalToTernary[mask][m]==0 &&
						   decimalToTernary[mask][m+1]==0 &&
						   decimalToTernary[mask][m+2]==0){
							   if(bad[n+2][m]){
								   v=max(v,1+dp[r0][m+1][mask+2*(powers[m]+powers[m+1]+powers[m+2])]);   
							   }else{
								   v=max(v,1+dp[r0][m+1][mask+powers[m]+2*(powers[m+1]+powers[m+2])]);
							   }
						}
						if(m<M-1 &&
						   decimalToTernary[mask][m]==0 &&
						   decimalToTernary[mask][m+1]==0 &&
						   !bad[n+2][m] && !bad[n+2][m+1]){
							   if(m+2==M){
								   v=max(v,1+dp[r1][0][mask+2*(powers[m]+powers[m+1])]);
							   }else{
								   v=max(v,1+dp[r0][m+2][mask+2*(powers[m]+powers[m+1])]);
							   }
						}
					}
				}
				//cout << n << " "<<m<<" "<<dp[r0][m][0]<< "\n";
			}
		}
		int nMask=0;
		fore(i,0,M){
			if(bad[0][i] && bad[1][i]){
				nMask+=2*powers[i];
			}else if(!bad[0][i] && bad[1][i]){
				nMask+=2*powers[i];
			}else if(bad[0][i] && !bad[1][i]){
				nMask+=powers[i];
			}
		}
		if((N>=2 && M>=3) || (N>=3 && M>=2)){
			cout << dp[r0][0][nMask]<< "\n";	
		}else{
			cout << "0\n";
		}
		 
	}
    return 0;
}
