#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int dp[105][905];
int main(){FIN;
	int m,s;
	cin >> m >> s;
	dp[0][0]=1;
	fore(i,1,m+1){
		fore(j,0,s+1){
			fore(k,0,10){
				if(j>=k && dp[i-1][j-k]){
					dp[i][j]=1;
				}
			}
		}
	}
	if(!dp[m][s] || (m>1 && s==0)){
		cout << "-1 -1\n";
	}else if(m==1 && s==0){
		cout << "0 0\n";
	}else{
		string minimum;
		int S=s;
		for(int M=m;M>=1;M--){
			fore(k,(M==m?1:0),10){
				if(S-k>=0 && dp[M-1][S-k]){
					minimum+=to_string(k);
					S-=k;
					break;
				}
			}
		}
		cout << minimum << " ";
		string maximum;
		S=s;
		for(int M=m;M>=1;M--){
			for(int k=9;k>=0;k--){
				if(S-k>=0 && dp[M-1][S-k]){
					maximum+=to_string(k);
					S-=k;
					break;
				}
			}
		}
		cout << maximum << "\n";
	}
    return 0;
}
