#include <iostream>

using namespace std;
int sums[105];
int dp[105][105];
int n;
int rangeSum(int i,int j){
    return (sums[j]-(i==0?0:sums[i-1]))%100;
}
int minSmoke(int a,int b){
    if(a==b) return 0;
    int &r=dp[a][b];
    if(r!=-1)return r;
    int minS=1e9;
    for(int j=a;j<b;j++){
        minS=min(minSmoke(a,j)+minSmoke(j+1,b)+rangeSum(a,j)*rangeSum(j+1,b),minS);
    }
    return r=minS;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            cin >> sums[i];
            if(i!=0)sums[i]+=sums[i-1];
        }
        cout << minSmoke(0,n-1)<<"\n";
    }
    return 0;
}
