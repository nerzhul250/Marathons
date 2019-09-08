#include <iostream>
#include <algorithm>

using namespace std;

typedef long long int ll;

int n,q;
ll tarbol[800000],arr[200005],arr2[200005];


void build(ll a[], int v, int tl, int tr,ll t[]) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm,t);
        build(a, v*2+1, tm+1, tr,t);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, ll add,ll t[]) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), add,t);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, add,t);
    }
}

ll get(int v, int tl, int tr, int pos,ll t[]) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos,t);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos,t);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for(int i=0;i<n;i++)cin >> arr[i];
    sort(arr,arr+n);
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        update(1,0,n-1,l,r,1,tarbol);
    }
    for(int i=0;i<n;i++){
        arr2[i]=get(1,0,n-1,i,tarbol);
    }
    sort(arr2,arr2+n);
    ll sum=0;
    for(int i=n-1;i>=0;i--){
        sum+=arr[i]*arr2[i];
    }
    cout << sum << "\n";
}
