#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define forn(x,n) for(int x = 0; x < n; ++x)
#define SIZE 350

using namespace std;

typedef long long int ll;

int NN;
const ll MOD=1e6;
void mul(ll a[SIZE][SIZE], ll b[SIZE][SIZE]){
    ll res[SIZE][SIZE]={{0}};
    forn(i,NN) forn(j,NN) forn(k,NN) res[i][j]+=(a[i][k]*b[k][j])%MOD;
    forn(i,NN) forn(j,NN) a[i][j]=res[i][j]%MOD;
}
void powmat(ll a[SIZE][SIZE],ll n,ll res[SIZE][SIZE]){
    forn(i,NN) forn (j,NN) res[i][j]=(i==j);
    while(n){
        if(n&1)mul(res,a),n--;
        else mul(a,a),n/=2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    NN=2;
    ll N,K,L;
    cin >> N >> K >> L;
    ll res[SIZE][SIZE],a[SIZE][SIZE];
    a[0][0]=K%MOD;a[0][1]=L%MOD;
    a[1][0]=1;a[1][1]=0;
    powmat(a,N/5,res);
    string ans=to_string(res[0][0]);
    int missing=6-ans.size();
    forn(i,missing){
		ans="0"+ans;
	}
	cout << ans <<"\n";
    return 0;
}
