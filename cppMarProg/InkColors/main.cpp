#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string.h>
using namespace std;

struct data {int u,f0,f1;};

const int MAXN=1e5 + 5;
const int oo = 1e4 + 100;

int dp[MAXN][4];
vector<int> nodes[MAXN];

int beststicks(const vector<data>& all,int u=-1){
    int num=2,ans=0;
    for (auto&d:all){
        if(num==0)break;
        if(d.u==u)continue;
        ans+=d.f0-max(d.f0,d.f1);
        num--;
    }
    if(num!=0)return -oo;
    return ans;
}
int stickman(int node, int level){
    if(dp[node][level]!=-1){return dp[node][level];}
    int& r=dp[node][level];
    if(level==0){
        r=0;
        for(auto& v : nodes[node])
            r += max(stickman(v, 0), stickman(v, 1) + 1);
    }else{
        int sum=0;
        vector<data> all;
        for(auto& v: nodes[node]){
            int f0=stickman(v, 0),f1=stickman(v, 1) + 1;
            sum+=max(f0,f1);
            all.push_back({v,f0,f1});
        }
        sort(all.begin(),all.end(),[&](const data&d1,const data&d2){
             return d1.f1-d1.f0<d2.f1-d2.f0;
             });
        if(level==1){
            r=-1;
            for(auto&d:all){
                r=max(r,sum+(stickman(d.u,2)-max(d.f0,d.f1))+beststicks(all,d.u));
            }
        }else{
            r=-oo;
            r=max(r,sum+beststicks(all));
        }
    }
    return r;
}

int main()
{
    memset(dp,-1,sizeof dp);
    int N;
    scanf("%d",&N);
    for (int i=2;i<=N;i++){
        int val; scanf("%d",&val);
        nodes[val].push_back(i);
    }
    printf("%d\n",stickman(1,0));
}
