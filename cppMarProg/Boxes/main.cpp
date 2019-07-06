#include <iostream>
#include <string.h>

using namespace std;

int weight[1005],load[1005];
int dp[1005][7000],N;
int countBoxes(int i,int c){
    if(c<0)return -5000000;
    if(i>=N)return 0;
    if(dp[i][c]!=-1)return dp[i][c];
    return dp[i][c]=max(countBoxes(i+1,c),1+countBoxes(i+1,min(c-weight[i],load[i])));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while(N){
        memset(dp,-1,sizeof dp);
        for(int i=0;i<N;i++){
          cin >> weight[i] >>load[i];
        }
        cout << countBoxes(0,6999) << "\n";
        cin >> N;
    }
    return 0;
}
