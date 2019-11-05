#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int ll;

const ll N = 1000000;
ll lp[N+5];
vector<ll> pr;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    for (ll i=2; i<=N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back (i);
    }
    for (ll j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)lp[i * pr[j]] = pr[j];
    }



    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        ll prime;
        cin >> prime;
        ll littp=sqrt(prime);
        if(littp*littp==prime && lp[littp]==littp){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

}
