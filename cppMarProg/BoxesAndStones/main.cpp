#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
#define MOD 1000000007
long long S,B;

long long memo[101][201][201];

long long dp(int pos,int piedras,int val){
    if(pos==0){
        if(val==0 && piedras==0)return 1;
        return 0;
    }else if(piedras<0){
        return 0;
    }
    if(memo[pos][piedras][val]!=-1)return memo[pos][piedras][val];
    memo[pos][piedras][val]=(dp(pos-1,piedras,val/2)+dp(pos,piedras-1,val+1))%MOD;
    return memo[pos][piedras][val];
}

int main(){

    int n;
    memset(memo,-1,sizeof(memo));

    while(cin>>S>>B){
        cout<<dp(B-1,S,0)%MOD<<endl;
    }

    return 0;
}
