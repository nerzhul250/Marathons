#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int n, dp[100005][5];
vector<int> sons[100005];

int maxStickMen(int node,int fatherType){
    if(dp[node][fatherType]!=-1)return dp[node][fatherType];
    if(fatherType==0){
        int maximum=0;
        for(int i=0;i<sons[node].size();i++){
            maximum+=max(maxStickMen(sons[node][i],0),maxStickMen(sons[node][i],1));
        }
        return dp[node][fatherType]=maximum;
    }else if(fatherType==1){
        if(sons[node].size()<3){
            return 0;
        }else{
            int temporalMaximums[sons[node].size()][3];
            int maximum=0;
            for(int i=0;i<sons[node].size();i++){
                temporalMaximums[i][1]=maxStickMen(sons[node][i],0);
                temporalMaximums[i][2]=maxStickMen(sons[node][i],1);
                temporalMaximums[i][0]=max(temporalMaximums[i][1],temporalMaximums[i][2]);
                maximum+=temporalMaximums[i][0];
            }
            int ans=-1;
            for(int i=0;i<sons[node].size();i++){
                int maxStickmenFromPechito=maxStickMen(sons[node][i],2);
                for(int j=0;j<sons[node].size();j++){
                    for(int k=j+1;k<sons[node].size();k++){
                        if(j!=i && k!=i){
                            ans=max(ans,maximum-temporalMaximums[i][0]-temporalMaximums[j][0]-temporalMaximums[k][0]+
                                    maxStickmenFromPechito+temporalMaximums[j][1]+temporalMaximums[k][1]);
                        }
                    }
                }
            }
            return dp[node][fatherType]= ans;
        }
    }else if(fatherType==2){
        if(sons[node].size()<2){
            return 0;
        }else{
            int temporalMaximums[sons[node].size()][3];
            int maximum=0;
            for(int i=0;i<sons[node].size();i++){
                temporalMaximums[i][1]=maxStickMen(sons[node][i],0);
                temporalMaximums[i][2]=maxStickMen(sons[node][i],1);
                temporalMaximums[i][0]=max(temporalMaximums[i][1],temporalMaximums[i][2]);
                maximum+=temporalMaximums[i][0];
            }
            int ans=-1;
            for(int j=0;j<sons[node].size();j++){
                for(int k=j+1;k<sons[node].size();k++){
                    ans=max(ans,maximum-temporalMaximums[j][0]-temporalMaximums[k][0]+
                            temporalMaximums[j][1]+temporalMaximums[k][1]);
                }
            }
            return dp[node][fatherType]= ans+1;
        }
    }
}
int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof dp);
    cin >> n;
    for(int i=2;i<=n;i++){
        int pi;
        cin >> pi;
        sons[pi].push_back(i);
    }
    cout << maxStickMen(1,0) << "\n";
}
