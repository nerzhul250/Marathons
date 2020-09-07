#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#define SIZE 105
#define forn(x,n) for(int x = 0; x < n; ++x)
using namespace std;
typedef long long int ll;
const int MAXN=50005;
const ll MOD=7+1e9;

int NN;
void mul(ll a[SIZE][SIZE], ll b[SIZE][SIZE]){
    ll res[SIZE][SIZE]={{0}};
    forn(i,NN) forn(j,NN) forn(k,NN) res[i][j]+=(a[i][k]*b[k][j])%MOD;
    forn(i,NN) forn(j,NN) a[i][j]=res[i][j]%MOD;
}
void powmat(ll a[SIZE][SIZE],int n,ll res[SIZE][SIZE]){
    forn(i,NN) forn (j,NN) res[i][j]=(i==j);
    while(n){
        if(n&1)mul(res,a),n--;
        else mul(a,a),n/=2;
    }
}
int digits[MAXN];
ll a[SIZE][SIZE],res[SIZE][SIZE];
int main(){FIN;	
	int n,b,k,x;
	cin >> n >> b >> k >> x;
	fore(i,0,n)cin >> digits[i];
	fore(i,0,x)fore(j,0,n)a[i][(i*10+digits[j])%x]++;
	NN=x;
	powmat(a,b,res);
	cout << res[0][k]<<"\n";
    return 0;
}
