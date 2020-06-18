#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>

#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int dp[5005][5];
int main(){FIN;
	int N;
	string s;
	cin >> N;
	cin >> s;
	fore(l,0,N){
		dp[l][0]=0;
		if(l+1<N){
			if(s[l]==s[l+1]){
				dp[l][1]=0;
			}else{
				dp[l][1]=1;
			}
		}
	}
	int r0=1;
	int r1=0;
	int r2=-1;
	fore(sz,2,N){
		r0++;r1++;r2++;
		r0%=3;r1%=3;r2%=3;
		fore(l,0,N-sz){
			if(s[l]==s[l+sz]){
				dp[l][r0]=dp[l+1][r2];
			}else{
				dp[l][r0]=1+min(dp[l+1][r1],min(dp[l][r1],1+dp[l+1][r2]));
			}
		}
	}
	cout << dp[0][r0] << "\n";
    return 0;
}
