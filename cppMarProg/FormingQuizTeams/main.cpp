#include <iostream>
#include <cmath>
#include <float.h>
#include <bits/stdc++.h> //MEMSET


using namespace std;

int N,target;
double distances[20][20], dp[1<<16];
double matching(int bitmask){
    if(bitmask==target)return 0;
    if(dp[bitmask]>-0.5)return dp[bitmask];
    int i,j;
    for (i=0;i<2*N;i++){
        if(!(bitmask & (1<<i)))break;
    }
    double ans=DBL_MAX;
    for (j=i+1;j<2*N;j++){
        if(!(bitmask & (1<<j))){
            ans=min(ans,distances[i][j]+matching(bitmask|(1<<i)|(1<<j)));
        }
    }
    return dp[bitmask]=ans;
}
int main()
{
    int caseNo=1,x[20],y[20];
    while(scanf("%d",&N),N){
        memset(dp,-1,sizeof dp);
        for (int i=0;i<2*N;i++)scanf("%*s %d %d",&x[i],&y[i]);
        for (int i=0;i<2*N;i++){
            for (int j=i+1;j<2*N;j++){
                distances[i][j]=distances[j][i]=hypot(x[i]-x[j],y[i]-y[j]);
            }
        }
        target=(1<<(2*N))-1;
        printf("Case %d: %.2f\n",caseNo++,matching(0));
    }
}
