#include <iostream>

using namespace std;

typedef long long ll;
const ll MOD=1e8;
int n1,n2,k1,k2;
ll dp[105][105][15][15];
ll ways(int f,int h,int rf, int rh){
    if(rf<0 || rh<0 || f<0 || h<0)return 0;
    if(f==0 && h==0)return 1;
    if(dp[f][h][rf][rh]!=-1)return dp[f][h][rf][rh];
    return dp[f][h][rf][rh]=(ways(f-1,h,rf-1,k2)+ways(f,h-1,k1,rh-1))%MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n1 >> n2 >> k1 >> k2;
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            for(int k=0;k<15;k++){
                for(int l=0;l<15;l++){
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }
    cout << ways(n1,n2,k1,k2) << endl;
    return 0;
}
