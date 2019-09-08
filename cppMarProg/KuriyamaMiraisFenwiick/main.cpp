#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef vector<ll> vi;

int n,m;

class FenwickTree {
private: vi ft;
public: FenwickTree(int n) { ft.assign(n + 1, 0); }
int LSOne(int b){return (b&-b);}
ll rsq(int b) {
    ll sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}
ll rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
}
void adjust(int k, ll v) {
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v;
}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    ll arr[n+5];
    FenwickTree ft1(n);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        ft1.adjust(i,arr[i]);
    }
    sort(arr+1,arr+n+1);
    FenwickTree ft2(n);
    for(int i=1;i<=n;i++){
        ft2.adjust(i,arr[i]);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int t,l,r;
        cin >> t >> l >>r;
        if(t==1){
            cout << ft1.rsq(l,r) << "\n";
        }else{
            cout << ft2.rsq(l,r) << "\n";
        }
    }
    return 0;
}
