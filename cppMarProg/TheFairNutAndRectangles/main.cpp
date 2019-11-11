#include <bits/stdc++.h>

#define fore(i,low,n) for(int i=low;i<n;i++)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#include <assert.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> Line;
typedef pair<ll,ll> ii;

const ll inf = 2e18;

ll f(Line l, ll x){
    return l.first * x + l.second;
}

struct Node{
    int left, right;
    ll xl, xr;
    Line l;
};
vector<Node> nodes;

void init(ll xmin, ll xmax){
    nodes.push_back({-1,-1,xmin,xmax,{0,-inf}});
}

void insert(int n, Line newline){
    ll xl = nodes[n].xl, xr = nodes[n].xr;
    ll xm = (xl + xr) >> 1;

    Line llow = nodes[n].l, lhigh = newline;
    if( f(llow, xl) > f(lhigh,xl) ) swap(llow, lhigh);

    if( f(llow, xr) <= f(lhigh, xr) ){
        nodes[n].l = lhigh;
        return;
    }
    else if( f(llow, xm) < f(lhigh, xm) ){
        nodes[n].l = lhigh;
        if( nodes[n].right == -1 ){
            nodes[n].right = nodes.size();
            nodes.push_back({-1,-1,xm+1,xr,{0,-inf}});
        }
        insert(nodes[n].right, llow);
    }
    else{
        nodes[n].l = llow;
        if( nodes[n].left == -1 ){
            nodes[n].left = nodes.size();
            nodes.push_back({-1,-1,xl,xm,{0,-inf}});
        }
        insert(nodes[n].left, lhigh);
    }
}

ll get(int n, ll xq){
    if( n == -1 ) return -inf;
    ll xl = nodes[n].xl, xr = nodes[n].xr;
    ll xm = (xl + xr) >> 1;

    if( xq <= xm ) return max(f(nodes[n].l, xq), get(nodes[n].left, xq));
    else return max(f(nodes[n].l, xq), get(nodes[n].right, xq));
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
    int n;
    cin >> n;
    pair<ii,ll> rectangles[n+5];
    fore(i,0,n){
        ll x,y,a;
        cin >>x >>y>>a;
        rectangles[i]={{x,y},a};
    }
    sort(rectangles,rectangles+n);
    ll maximo=0;
    init(-1e12,1e12);
    fore(i,0,n){
        ll x=rectangles[i].ff.ff,y=rectangles[i].ff.ss,a=rectangles[i].ss;
        ll val=(i==0?0:get(0,-y))+x*y-a;
        assert(val>=0);
        maximo=max(maximo,val);
        insert(0,{x,val});
    }
    cout << maximo << endl;
    return 0;
}
