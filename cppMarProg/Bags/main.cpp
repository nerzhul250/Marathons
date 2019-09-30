#include <iostream>
#include <unordered_map>
#include <string.h>

using namespace std;

typedef long long int ll;
ll const MAXLEN=100005;
ll const MOD=4300000013L;
ll factorial[MAXLEN];
ll numberOfArrangements;
ll t[MAXLEN*4];
int arr[MAXLEN],totalSum;
unordered_map<ll,int> valtoNum;

ll mult(ll a, ll b){
    ll a1=a/2;
    ll a2=a-a1;
    ll b1=b/2;
    ll b2=b-b1;
    ll ans=(a1*b1)%MOD;
    ans+=(a1*b2)%MOD;
    ans+=(a2*b1)%MOD;
    ans+=(a2*b2)%MOD;
    return ans%MOD;
}

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2]+t[v*2+1];
    }
}

void update(int v, int tl, int tr, int l, int r, ll add) {
    if ( r<tl || l>tr)
        return;
    if (l<=tl && tr<=r) {
        t[v] += add;
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, r, add);
        update(v*2+1, tm+1, tr, l, r, add);
        t[v]=t[v*2]+t[v*2+1];
    }
}

ll get(int v, int tl, int tr,int l, int r) {
    if (r<tl || l>tr)
        return 0;
    if (tl>=l && tr<=r) {
        return t[v];
    } else {
        int tm = (tl + tr) / 2;
        return get(v*2, tl, tm,l,r)+ get(v*2+1, tm+1, tr,l,r);
    }
}

ll extended_euclidean(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll inverse(ll a){
    ll x, y;
    ll g = extended_euclidean(a,MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    factorial[0]=1;
    for(int i=1;i<=100000;i++){
        factorial[i]=(factorial[i-1]*((ll)i))%MOD;
    }
    int T;
    cin >> T;
    while(T--){
        memset(t,0,sizeof t);
        memset(arr,0,sizeof arr);
        valtoNum.clear();
        numberOfArrangements=1;
        totalSum=0;
        int N,M;
        cin >> N >> M;
        build(arr,1,0,N-1);
        for(int i=0;i<M;i++){
            string event;
            cin >> event;
            if(event[0]=='Q'){
                int F,T;
                cin >> F >> T;
                F--;
                T--;
                cout << get(1,0,N-1,F,T) << endl;
            }else if(event[0]=='W'){
                cout << numberOfArrangements << endl;
            }else if(event[0]=='U'){
                int D,B;
                cin >> D >> B;
                D--;
                update(1,0,N-1,D,D,B);
                if(arr[D]!=0){
                    ll oldVal=arr[D];
                    ll newVal=arr[D]+B;
                    arr[D]+=B;
                    numberOfArrangements=mult(numberOfArrangements,factorial[valtoNum[oldVal]]);
                    numberOfArrangements=mult(numberOfArrangements,factorial[valtoNum[newVal]]);
                    valtoNum[oldVal]=valtoNum[oldVal]-1;
                    if(valtoNum.find(newVal)!=valtoNum.end()){
                        valtoNum[newVal]=valtoNum[newVal]+1;
                    }else{
                        valtoNum[newVal]=1;
                    }
                    numberOfArrangements=mult(numberOfArrangements,inverse(factorial[valtoNum[oldVal]]));
                    numberOfArrangements=mult(numberOfArrangements,inverse(factorial[valtoNum[newVal]]));
                }else{
                    int oldVal=totalSum;
                    int newVal=totalSum+1;
                    totalSum++;
                    numberOfArrangements=mult(numberOfArrangements,factorial[newVal]);
                    numberOfArrangements=mult(numberOfArrangements,inverse(factorial[oldVal]));

                    arr[D]=B;
                    if(valtoNum.find(B)!=valtoNum.end()){
                        valtoNum[B]=valtoNum[B]+1;
                    }else{
                        valtoNum[B]=1;
                    }

                    numberOfArrangements=mult(numberOfArrangements,factorial[valtoNum[B]-1]);
                    numberOfArrangements=mult(numberOfArrangements,inverse(factorial[valtoNum[B]]));
                }
            }
        }
    }
    return 0;
}
