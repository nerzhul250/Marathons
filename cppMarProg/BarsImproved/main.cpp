#include <iostream>
#include <string.h>

using namespace std;
typedef long long ll;

int dp[25][1005];
ll arr[25];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        ll n;
        int p;
        cin >> n;
        cin >> p;
        memset(dp,0,sizeof dp);
        for(int i=0;i<p;i++){cin >> arr[i];}
        dp[p-1][arr[p-1]]=1;
        dp[p-1][0]=1;
        for(int i=p-1;i>0;i--){
            for(int j=0;j<n+1;j++){
                dp[i-1][j]=dp[i][j]|dp[i-1][j];
                dp[i-1][j+arr[i-1]]=dp[i][j]|dp[i-1][j+arr[i-1]];
            }
        }
        if(dp[0][n]){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
    return 0;
}
