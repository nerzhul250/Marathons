#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;

const ll MOD=7+1e9;
ll dp[5005][5005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int S,B;
    cin >> S>>B;
    B=B-S;

    fore(i,1,S+1)dp[0][i]=1;
    fore(i,1,B+1)dp[i][1]=1;

    fore(i,1,B+1){
        ll toSum=1;
        ll toRest=1;
        fore(j,2,S+1){
            toSum+=(i<j?0:dp[i-j][j]);
            toRest+=(i<j?0:dp[i-j][j]*j);
            toSum=toSum%MOD;
            toRest=toRest%MOD;
            dp[i][j]=(toSum*(j+1)-toRest)%MOD;
        }
    }

    cout << dp[B][S]<<endl;

    return 0;
}
