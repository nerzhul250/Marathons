#include <iostream>

using namespace std;

int dp[5006], h[5006],w,n,maxi;

int L(int i){
    if(dp[i]!=-1)return dp[i];
    if(h[i]==maxi)return dp[i]=0;
    for (int k=-w;k<w+1;k++){
        if(k==0 || i+k<=0 || i+k>n || h[i+k]<=h[i]) continue;
        dp[i]=max(dp[i],L(i+k));
    }
    dp[i]++;
    return dp[i];
}

int main()
{
    while(scanf("%d %d",&n,&w)==2){
        for (int i=1;i<=n;i++){
            dp[i]=-1;
        }
        for (int i=1;i<=n;i++){
            scanf("%d",&h[i]);
            maxi=max(maxi,h[i]);
        }
        int maximo=-1;
        for (int i=1;i<=n;i++){
            L(i);
            maximo=max(maximo,dp[i]);
        }
        printf("%d\n",maximo);
    }
}
