#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 60
#define forn(x,n) for(int x = 0; x < n; ++x)

using namespace std;


typedef long long int ll;

ll adjMatrix[SIZE][SIZE];
ll MOD=7+1e9;
int NN;

void mul(ll a[SIZE][SIZE],ll b[SIZE][SIZE]){
    ll res[SIZE][SIZE]={{0}};
    forn(i,NN) forn(k,NN) forn(j,NN) res[i][j]+=(a[i][k]*b[k][j])%MOD;
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


    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    ll n;
    int m,k;
    cin >> n >> m >> k;
    NN=m;
    for(int i=0;i<NN;i++){
        for(int j=0;j<NN;j++){
            adjMatrix[i][j]=1;
        }
    }

    for(int i=0;i<k;i++){
        string s;
        cin >> s;
        int left=0,up=0;
        if(s[0]>='a' && s[0]<='z'){
            left=s[0]-'a';
        }else{
            left=s[0]-'A'+26;
        }
        if(s[1]>='a' && s[1]<='z'){
            up=s[1]-'a';
        }else{
            up=s[1]-'A'+26;
        }
        adjMatrix[left][up]=0;
    }

    if(n==1){
        cout << m<<endl;
        return 0;
    }

    ll res[SIZE][SIZE];
    powmat(adjMatrix,n-1,res);
    ll sum=0;
    forn(i,NN){
        forn(j,NN){
            sum+=res[i][j];
            sum=sum%MOD;
        }
    }
    cout << sum << endl;
    return 0;
}
