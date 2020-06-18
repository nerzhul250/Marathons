#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int arr[105];
int cnt[10005];
int dp[105][10005];
int main(){FIN;
	int n;
	cin >> n;
	int sum=0;
	int sz=0;
	fore(i,0,n){
		cin >> arr[i];
		if(cnt[arr[i]]==0)sz++;
		cnt[arr[i]]++;
		sum+=arr[i];
	}
	if(sz<=2){
		cout << n<<"\n";
	}else{
		dp[0][0]=1;
		fore(v,1,101){
			//cout << v << endl;
			if(cnt[v]!=0){
				for(int k=n;k>=0;k--){
					for(int m=sum;m>=0;m--){
						fore(t,1,cnt[v]+1){
							//cout << t <<" "<<k<<" "<<m<<endl;
							if(k-t>=0 && m-t*v>=0){
								dp[k][m]+=dp[k-t][m-t*v];
							}
						}
					}
				}
			}
		}
		int maxh=1;
		fore(i,2,n){
			fore(m,1,sum+1){
				//cout << i << " "<<m<<" "<<dp[i][m]<<endl;
				if(dp[i][m]==1 && m%i==0 && cnt[m/i]>=i){
					maxh=i;
				}	
			}
		}
		cout << maxh << "\n";
	}
    return 0;
}
