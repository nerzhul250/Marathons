#include <iostream>

typedef long long int ll;

using namespace std;

ll n,m,t,comb[40][40];

ll combF(ll w, ll r){
    if(w<r)return 0;
    if(r==0)return 1;
    if(comb[w][r]!=0)return comb[w][r];
    return comb[w][r]=combF(w-1,r)+combF(w-1,r-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> t;
    ll sum=0;
    for(ll i=4;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(i+j==t){
                sum+=combF(n,i)*combF(m,j);
            }
        }
    }
    cout << sum << "\n";
}
