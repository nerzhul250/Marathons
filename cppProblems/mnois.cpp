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
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<int> a(n,0);
		fore(i,0,n)cin >> a[i];
		vector<vector<int>> len(n,vector<int>(n,0));
		fore(i,0,n){
			vector<int> seq;
			fore(j,i,n){
				if(seq.empty() || a[j]>seq.back()){
					seq.pb(a[j]);
				}else{
					auto t=lower_bound(ALL(seq),a[j]);
					*t=a[j];
				}
				len[i][j]=seq.size();
			}
		}
		fore(k,1,n+1){
			vector<int> dp(n,0);
			dp[0]=(k==1?1:0);
			fore(i,1,n){
				dp[i]=(len[0][i]>=k?len[0][i]:0);
				int j=1;
				while(j<=i && len[j][i]>=k){
					dp[i]=max(dp[i],dp[j-1]+len[j][i]);
					j++;
				}
			}
			if(k==n)cout << dp[n-1]<<"\n";
			else cout << dp[n-1]<<" ";
		}
	}
    return 0;
}
