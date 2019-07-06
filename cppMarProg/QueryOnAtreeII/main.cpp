#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

string op;
int T,a,b,c,k,timer,N,l,tin[10009],tout[10009];
vi sum[10009],up[10009];
vector<ii> adjList[10009];

void dfs(int v,int p,int edgy)
{
    tin[v] = ++timer;
    up[v][0]=p;
    sum[v][0]=edgy;
    for (int i = 1; i <= l; ++i){
        up[v][i]=up[up[v][i-1]][i-1];
        sum[v][i]=sum[v][i-1]+sum[up[v][i-1]][i-1];
    }

    for (ii e : adjList[v]) {
        if (e.first!=p)
            dfs(e.first,v,e.second);
    }

    tout[v] = ++timer;
}

bool is_ancestor(int u, int v)
{
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
int dist(){
    if(a==b)return 0;

    int ancestor=lca(a,b);

    int u=a;
    int currentSum=0;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],b)){
            currentSum+=sum[u][i];
            u = up[u][i];
        }
    }
    if(ancestor!=a)currentSum+=sum[u][0];

    u=b;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],a)){
            currentSum+=sum[u][i];
            u = up[u][i];
        }
    }
   if(ancestor!=b)currentSum+=sum[u][0];

    return currentSum;
}

int kth(){
    k--;
    if(k==0)return a;
    int ancestor=lca(a,b);
    int u=a;
    int currentK=0;
    if(ancestor==a){
        u=b;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i],a)){
                currentK+=(1<<i);
                u = up[u][i];
            }
        }
        currentK+=1;
        k=currentK-k;

        if(k==0)return b;

        u=b;
        int power=1;
        int index=0;
        while(power<=k){
            if((power&k)!=0){
                u=up[u][index];
            }
            index++;
            power=power<<1;
        }
        return u;
    }

    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],b)){
            currentK+=(1<<i);
            u = up[u][i];
        }
    }
    currentK+=1;
    if(k==currentK){
        return up[u][0];
    }else if(k<currentK){
        u=a;
        int power=1;
        int index=0;
        while(power<=k){
            if((power&k)!=0){
                u=up[u][index];
            }
            index++;
            power=power<<1;
        }
        return u;
    }else{
        k-=currentK;
        currentK=0;
        u=b;
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i],a)){
                currentK+=(1<<i);
                u = up[u][i];
            }
        }
        currentK+=1;
        k=currentK-k;

        if(k==0)return b;

        u=b;
        int power=1;
        int index=0;
        while(power<=k){
            if((power&k)!=0){
                u=up[u][index];
            }
            index++;
            power=power<<1;
        }
        return u;
    }
}

int main()
{
    cin >> T;
    while(T--){
        cin >> N;
        l=ceil(log2(N));
        for(int i=0;i<N;i++){
            up[i].assign(l+1,0);
            sum[i].assign(l+1,0);
        }
        for(int i=0;i<N;i++){
            adjList[i].clear();
        }
        for(int i=0;i<N-1;i++){
            cin >> a >> b >> c;
            a--;
            b--;
            adjList[a].push_back(ii(b,c));
            adjList[b].push_back(ii(a,c));
        }
        dfs(0,0,0);
        cin >> op;
        while(!(op=="DONE")){
            cin >> a >> b;
            a--;
            b--;
            if(op=="DIST"){
                cout << dist() << endl;
            }else{
                cin >> k;
                cout << kth()+1 << endl;
            }
            cin >> op;
        }
    }
    return 0;
}
