#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

typedef int64_t ll;

using namespace std;

int N,D,target;
ll dp[1<<21];
double grades[21];
bool validGroup(int i, int j, int k){
    return (max(grades[i],max(grades[j],grades[k]))-min(grades[i],min(grades[j],grades[k])))<=((double)D);
}
ll matching(int bitmask){
    if(bitmask==target)return 1;
    if(dp[bitmask]!=-1)return dp[bitmask];
    int i,j,k;
    for (i=0;i<N-2;i++){
        if(!(bitmask & (1<<i))){
            break;
        }
    }
    ll sum=0;
    for (j=i+1;j<N-1;j++){
        if(!(bitmask & (1<<j))){
            for (k=j+1;k<N;k++){
                if(!(bitmask & (1<<k))){
                    if(validGroup(i,j,k)){
                       sum+=matching(bitmask|(1<<i)|(1<<j)|(1<<k));
                    }
                }
            }
        }
    }
    return dp[bitmask]=sum;
}
int main()
{
    while(scanf("%d %d",&N,&D),N){
        memset(dp,-1,sizeof dp);
        for (int i=0;i<N;i++){
            scanf("%lf",&grades[i]);
        }
        target=(1<<N)-1;
        printf("%lld\n",matching(0));
    }
    return 0;
}
