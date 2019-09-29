#include <iostream>

using namespace std;

typedef long long int ll;
ll const MAXLEN=100005;
ll t[MAXLEN*4];

void build(ll a[], int v, int tl, int tr) {
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
    cout << "Hello world!" << endl;
    return 0;
}
