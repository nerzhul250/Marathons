#include <iostream>
#include <string.h>
using namespace std;
int const INF=-1e8;
int a,b,c;
int dp[4005];
int getMaximum(int lgth){
    if(lgth<0){
        return INF;
    }
    if(lgth==0){
        return 0;
    }
    int &r=dp[lgth];
    if(r!=-1)return r;
    return r=1+max(getMaximum(lgth-a),max(getMaximum(lgth-b),getMaximum(lgth-c)));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof dp);
    int n;
    cin >> n >> a >> b >> c;
    cout << getMaximum(n) << "\n";
    return 0;
}
