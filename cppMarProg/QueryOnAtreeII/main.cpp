#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

string op;
int T,a,b,c,k,timer,N,l,tin[10009],tout[10009];
vi sum[10009],up[10009],
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
    int ancestor=lca(a,b);
    int u=a;
    int currentSum=0;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],ancestor)){
            currentSum+=sum[u][i];
            u = up[u][i];
        }
    }
    currentSum+=sum[u][0];


    u=b;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],ancestor)){
            currentSum+=sum[u][i];
            u = up[u][i];
        }
    }
    currentSum+=sum[u][0];

    return currentSum;
}

int kth(){
    k--;
    if(k==0)return a;
    int ancestor=lca(a,b);
    int u=a;
    int currentK=0;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],ancestor)){
            currentK+=(1<<i);
            u = up[u][i];
        }
    }
    currentK+=1;
    if(k<=currentK){
        u=a;
        currentK=1;
        int i=0;
        while(currentK!=k){
            if(currentK+(i<<i)==k){
                return up[up[u][0]][i];
            }else if(currentK+(1<<i)<k){
                i++;
            }else{
                i--;
                currentK+=(1<<i);
                u=up[u][i];
                i=0;
            }
        }
        return up[u][i];
    }else{

    }
}

int main()
{
    l=ceil(log2(10009));
    for(int i=0;i<10009;i++){
        up[i].assign(l+1,0);
        sum[i].assign(l+1,0);
    }
    cin >> T;
    while(T--){
        cin >> N;
        l=ceil(log2(N));
        for(int i=1;i<=N;i++){
            adjList[i].clear();
        }
        for(int i=0;i<N-1;i++){
            cin >> a >> b >> c;
            adjList[a]=ii(b,c);
            adjList[b]=ii(a,c);
        }
        dfs(1,1,0);
        cin >> op;
        while(!(op=="DONE")){
            cin >> a >> b;
            if(op=="DIST"){
                cout << dist() << endl;
            }else{
                cin >> k;
                cout << kth() << endl;
            }
            cin >> op;
        }
    }
    return 0;
}
