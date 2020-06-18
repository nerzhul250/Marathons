#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
double dp[105][105][105];
double s[105],d[105],prob[105][105];
char table[105][105];
int main(){FIN;
	cout << fixed;
	cout << setprecision(9);
	int t,p;
	cin >> t >>p;
	fore(i,0,t-1)cin >> s[i];
	fore(i,0,p)cin >>d[i];
	fore(i,0,t-1){
		fore(j,0,p){
			prob[i][j]=s[i]*d[j];
		}
	}
	fore(i,0,t)fore(j,0,p)cin >> table[i][j];
	fore(i,0,t-1){
		if(table[i][0]=='X'){
			dp[i][0][0]=0;
			dp[i][0][1]=1;
		}else if(table[i][0]=='?'){
			dp[i][0][0]=1-prob[i][0];
			dp[i][0][1]=prob[i][0];
		}else if(table[i][0]=='-'){
			dp[i][0][0]=1;
			dp[i][0][1]=0;
		}
	}
	fore(i,0,t-1){
		fore(j,1,p){
			fore(k,0,j+2){
				if(table[i][j]=='X'){
					dp[i][j][k]=dp[i][j-1][k-1];
				}else if(table[i][j]=='?'){
					dp[i][j][k]=(1-prob[i][j])*dp[i][j-1][k];
					if(k)dp[i][j][k]+=(prob[i][j])*dp[i][j-1][k-1];
				}else if(table[i][j]=='-'){
					dp[i][j][k]=dp[i][j-1][k];
				}
			}
		}
	}
	int n=0;
	fore(i,0,p){
		if(table[t-1][i]=='X')n++;
	}
	double ans=1;
	fore(i,0,t-1){
		double sum=0;
		fore(j,0,n+1){
			sum+=dp[i][p-1][j];
		}
		ans*=sum;
	}
	cout << ans << "\n";
    return 0;
}
