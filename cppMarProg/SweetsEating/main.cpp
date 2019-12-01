#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef long long int ll;
typedef vector<ll> vi;

int LSOne(int b){
    return b & -b;
}

class FenwickTree {
private: vi ft; // recall that vi is: typedef vector<int> vi;
public: FenwickTree(int n) { ft.assign(n + 1, 0); } // init n + 1 zeroes
ll rsq(int b) { // returns RSQ(1, b)
ll sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
return sum; } // note: LSOne(S) (S & (-S))
ll rsq(int a, int b) { // returns RSQ(a, b)
return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }
// adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
void adjust(int k, ll v) { // note: n = ft.size() - 1
for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int n,m;
    cin >> n >> m;
    FenwickTree ft(n);
    vector<ll> theSweets;
    fore(i,0,n){
        ll sweet;
        cin >> sweet;
        theSweets.pb(sweet);
    }
    sort(theSweets.begin(),theSweets.end());
    fore(i,0,n)ft.adjust(i+1,theSweets[i]);
    ll theAnswer[n+5];
    fore(i,1,n+1){
        theAnswer[i]=ft.rsq(i);
        theAnswer[i]+=(i-m>0?theAnswer[i-m]:0);
        if(i==n){
            cout << theAnswer[i]<<"\n";
        }else{
            cout << theAnswer[i]<<" ";
        }
    }
    return 0;
}
