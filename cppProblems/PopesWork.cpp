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
int N;
int W[1005],R[1005];
int dp[5][1005];
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		cin >> N;
		vector<ii> mm;
		fore(i,0,N){
			cin >> W[i]>> R[i];
			mm.pb(ii(R[i],W[i]));
		}
		sort(ALL(mm));
		fore(i,0,N){
			R[i]=mm[i].ff;
			W[i]=mm[i].ss;
		}
		fore(i,0,N){
			dp[0][i]=W[i];
		}
		int r=0;
		int maxh=1;
		fore(i,1,N){
			r^=1;
			int cnt=0;
			fore(j,0,N){
				int MINW=1e8;
				dp[r][j]=-1;
				fore(k,i-1,j){
					if(dp[r^1][k]!=-1 && dp[r^1][k]+W[j]<=R[j] &&dp[r^1][k]+W[j]<MINW){
						MINW=dp[r^1][k]+W[j];
					}
				}
				if(MINW!=1e8){
					cnt++;
					dp[r][j]=MINW;
				}
			}
			if(cnt>0){
				maxh=i+1;
			}else{
				break;
			}
		}
		cout << maxh << "\n";
	}
    return 0;
}
