#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,pair<int,int>> iii;
typedef pair<int,int> ii;
iii problems[105];
bool cmp(const iii &a,const iii&b){
	return a.ss.ff*b.ss.ss>a.ss.ss*b.ss.ff;
}
ii dp[105][1005];
vector<int> ans;
void compute(int i,int j){
	if(i==0)return ;
	if(dp[i][j]==dp[i-1][j]){		
		compute(i-1,j);
	}else{
		ans.pb(problems[i].ff);
		compute(i-1,j-problems[i].ss.ff);
	}
	return ;
}
int main(){FIN;
	int N,tmax;
	cin >>N>>tmax;
	fore(i,1,N+1){
		cin >> problems[i].ss.ff>>problems[i].ss.ss;
		problems[i].ff=i;
	}
	sort(problems+1,problems+N+1,cmp);
	fore(i,1,N+1){
		fore(j,0,tmax+1){
			if(j-problems[i].ss.ff>=0){
				if(dp[i-1][j].ff==problems[i].ss.ss+dp[i-1][j-problems[i].ss.ff].ff){
					dp[i][j]=min(dp[i-1][j]
							 ,ii(problems[i].ss.ss+dp[i-1][j-problems[i].ss.ff].ff,
								 problems[i].ss.ss*(problems[i].ss.ff+tmax-j)+dp[i-1][j-problems[i].ss.ff].ss));		
				}else{
					dp[i][j]=max(dp[i-1][j]
							 ,ii(problems[i].ss.ss+dp[i-1][j-problems[i].ss.ff].ff,
								 problems[i].ss.ss*(problems[i].ss.ff+tmax-j)+dp[i-1][j-problems[i].ss.ff].ss));
				}
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	compute(N,tmax);
	cout << ans.size()<<"\n";
	fore(i,0,ans.size()){
		if(i==ans.size()-1)cout << ans[i]<<"\n";
		else cout << ans[i]<<" ";
	}
	return 0;
}
