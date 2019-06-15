#include <iostream>

using namespace std;
int n,arr[105],dp[105][2][2];
const int INF=100000000;
int minNumber(int i,int g,int c){
    if(g<0 || c<0)return INF;
    if(i==n)return 0;
    if(dp[i][g][c]!=-1)return dp[i][g][c];
    if(arr[i]==0){
        return dp[i][g][c]=1+minNumber(i+1,1,1);
    }else if(arr[i]==1){
        return dp[i][g][c]=min(1+minNumber(i+1,1,1),minNumber(i+1,1,c-1));
    }else if(arr[i]==2){
        return dp[i][g][c]=min(1+minNumber(i+1,1,1),minNumber(i+1,g-1,1));
    }else if(arr[i]==3){
        return dp[i][g][c]=min(1+minNumber(i+1,1,1),min(minNumber(i+1,g-1,1),minNumber(i+1,1,c-1)));
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        dp[i][0][0]=-1;dp[i][0][1]=-1;
        dp[i][1][0]=-1;dp[i][1][1]=-1;
    }
    cout << minNumber(0,1,1)<<"\n";
    return 0;
}
