#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SIZE 5
#define forn(x,n) for(int x = 0; x < n; ++x)
#define SZ(s) int(s.size())
using namespace std;
typedef long long int ll;
const ll mod=7+1e9;
int NN;
void mul(ll a[SIZE][SIZE], ll b[SIZE][SIZE]){
    ll res[SIZE][SIZE]={{0}};
    forn(i,NN) forn(j,NN) forn(k,NN) res[i][j]+=(a[i][k]*b[k][j])%mod;
    forn(i,NN) forn(j,NN) a[i][j]=res[i][j]%mod;
}
void powmat(ll a[SIZE][SIZE],ll n,ll res[SIZE][SIZE]){
    forn(i,NN) forn (j,NN) res[i][j]=(i==j);
    while(n){
        if(n&1)mul(res,a),n--;
        else mul(a,a),n/=2;
    }
}
int main(){FIN;
	int t;
	cin >> t;
	NN=2;
	ll m[SIZE][SIZE]={{0}};
	ll res[SIZE][SIZE]={{0}};
	while(t--){
		ll a,n;
		cin >> a >> n;
		if(n==0){
			cout << "2\n";
		}else if(abs(n)==1){
			cout << ((a%mod)+mod)%mod<<"\n";
		}else{
			m[0][0]=a%mod;m[0][1]=-1;
			m[1][0]=1;m[1][1]=0;
			powmat(m,abs(n)-1,res);
			ll answer=((res[0][0]*(a%mod)+res[0][1]*2)%mod + mod)%mod;
			cout << answer<< "\n";
		}
	}
    return 0;
}
