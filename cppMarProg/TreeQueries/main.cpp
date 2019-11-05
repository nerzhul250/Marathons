#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,up) for(int i=low;i<up;i++)


using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

int const MAXN=10+1e5;
vector<int> g[MAXN];
int timeIn[MAXN],sz[MAXN],A[MAXN],ap[MAXN],color[MAXN],cnt[MAXN],id=0,n,nq,sq;

struct qu{int l,r,id,k;};

qu qs[MAXN];
ll ans[MAXN];

bool qcomp(const qu &a, const qu &b){
    if(a.l/sq!=b.l/sq) return a.l<b.l;
    return (a.l/sq)&1?a.r<b.r:a.r>b.r;
}


int dfs(int v, int par){
    timeIn[v]=id;
    A[id]=color[v];
    id++;
    for(int u : g[v]){
        if(u!=par){
            sz[v]+=dfs(u,v);
        }
    }
    sz[v]++;
    return sz[v];
}


void init(){
    cin >> n>> nq;
    for(int i=0;i<n;i++){
        int c;
        cin >> c;
        color[i]=c;
    }
    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,-1);
    for(int i=0;i<nq;i++){
        int v,k;
        cin >> v >> k;
        v--;
        qu thQuery;
        thQuery.k=k;
        thQuery.l=timeIn[v];
        thQuery.r=timeIn[v]+sz[v];
        qs[i]=thQuery;
    }
}

int get_ans(int k){
    return cnt[k];
}
void add(int pos){
    ap[A[pos]]++;
    cnt[ap[A[pos]]]++;
}

void rem(int pos){
    cnt[ap[A[pos]]]--;
    ap[A[pos]]--;
}

void mos(){
    init();
    fore(i,0,nq)qs[i].id=i;
    sq=sqrt(n)+.5;
    sort(qs,qs+nq,qcomp);
    int l=0,r=0;
    fore(i,0,nq){
        qu q=qs[i];
        while(l>q.l)add(--l);
        while(r<q.r)add(r++);
        while(l<q.l)rem(l++);
        while(r>q.r)rem(--r);
        ans[q.id]=get_ans(q.k);
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
    mos();
    fore(i,0,nq)cout << ans[i]<<"\n";
}
