#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef vector<int> vi;
typedef long long int ll;
ll _sieve_size;
bitset<1000010> bs;
vi primes;

void sieve(ll upperbound){
    _sieve_size=upperbound+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2;i<=_sieve_size;i++){
        if(bs[i]){
            for(ll j=i*i;j<=_sieve_size;j+=i)bs[j]=0;
            primes.push_back((int)i);
        }
    }
}

int gcd(int a,int b){return a==0?b:gcd(b%a,a);}
ll primeFactors(ll N){
    ll ans=1;
    ll PF_idx=0,PF=primes[PF_idx];
    while(PF*PF<=N){
        ll sum=0;
        while(N%PF==0){N/=PF;sum++;}
        ans*=(sum+1);
        PF=primes[++PF_idx];
    }
    if(N!=1)ans*=2;
    return ans;
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

    int T;
    cin >> T;
    sieve(1000000);
    while(T--){
        int a,b;
        cin >> a >> b;
        ll mcd=gcd(a,b);
        cout << primeFactors(mcd)<<endl;
    }
}
