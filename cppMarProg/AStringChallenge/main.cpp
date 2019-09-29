#include <iostream>
#include <string.h>
using namespace std;
typedef long long int ll;
#define SIZE 30
#define forn(x,n) for(int x = 0; x < n; ++x)
ll base[30],MOD=7+1e9;
int NN;
void mul(ll a[SIZE][SIZE], ll b[SIZE][SIZE]){
    ll res[SIZE][SIZE]={{0}};
    forn(i,NN) forn(j,NN) forn(k,NN) res[i][j]+=(a[i][k]*b[k][j])%MOD;
    forn(i,NN) forn(j,NN) a[i][j]=(res[i][j])%MOD;
}

void powmat(ll a[SIZE][SIZE],ll n,ll res[SIZE][SIZE]){
    forn(i,NN) forn (j,NN) res[i][j]=(i==j);
    while(n){
        if(n&1)mul(res,a),n--;
        mul(a,a),n/=2;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    NN=26;
    while(T--){
        string S;
        cin >> S;
        memset(base,0,sizeof base);
        for(int i=0;i<S.size();i++)base[S[i]-'a']++;
        int K;
        ll N,a[SIZE][SIZE],res[SIZE][SIZE];
        for(int i=0;i<SIZE;i++) for(int j=0;j<SIZE;j++)a[i][j]=0;
        for(int i=0;i<SIZE;i++) for(int j=0;j<SIZE;j++)res[i][j]=0;
        cin >> K >> N;
        int used[30];
        memset(used,0,sizeof used);
        for(int i=0;i<K;i++){
            string ant,cons;
            cin >> ant >> cons;
            used[ant[0]-'a']=1;
            for(int j=0;j<cons.size();j++){
                a[cons[j]-'a'][ant[0]-'a']++;
            }
        }

        for(int i=0;i<26;i++){
            if(!used[i]){
                a[i][i]=1;
            }
        }

        powmat(a,N,res);

        ll length=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                length+=(res[i][j]*base[j])%MOD;
            }
            length%=MOD;
        }

        cout << length << "\n";
    }
    return 0;
}
