#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long int ll;

ll const MOD=7+1e9;
ll combi[1000][1000],S,B;

ll getncomk(ll n, ll k){
    if(combi[n][k]!=0)return combi[n][k];
    if(n==k){
        return 1;
    }else if(k==0){
        return 1;
    }
    return combi[n][k]=(getncomk(n-1,k-1)+getncomk(n-1,k))%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    while(cin >> S>>B){
        ll ans=0;
        for(int i=1;i<B;i++){
            for(int j=(1<<i);j<=S;j++){
                ans+=getncomk(B-3+S-j,S-j);
                ans=ans%MOD;
            }
        }
        cout << (getncomk(B-2+S,S)-ans+MOD)%MOD<<endl;
    }

}
