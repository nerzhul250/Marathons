#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef vector<int> vi;

int tin[100005],tout[100005];
vi sum[100005],up[100005];
vector<int> adjList[100005];

int timer,l,N,Q;

void dfs(int v,int p)
{
    tin[v] = ++timer;
    up[v][0]=p;
    sum[v][0]=2;
    for (int i = 1; i <= l; ++i){
        up[v][i]=up[up[v][i-1]][i-1];
        sum[v][i]=sum[v][i-1]+sum[up[v][i-1]][i-1]-1;
    }
    for (int e : adjList[v]) {
        if (e!=p)dfs(e,v);
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

int dist(int a, int b){
    if(a==b)return 1;

    int ancestor=lca(a,b);

    int u=a;
    int currentSum=0;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],b)){
            currentSum+=sum[u][i];
            currentSum--;
            u = up[u][i];
        }
    }
    if(ancestor!=a)currentSum+=sum[u][0];

    u=b;
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],a)){
            currentSum+=sum[u][i];
            currentSum--;
            u = up[u][i];
        }
    }
   if(ancestor!=b)currentSum+=sum[u][0];

    return (ancestor!=b && ancestor!=a?currentSum-1:currentSum);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N>> Q;
    l=ceil(log2(N));
    for(int i=0;i<N;i++){
		up[i].assign(l+1,0);
		sum[i].assign(l+1,0);
    }
    
    fore(i,0,N-1){
		int U,V;
		cin >> U>>V;
		U--;
		V--;
		adjList[U].pb(V);
		adjList[V].pb(U);
	}
	
	dfs(0,0);
	
	fore(i,0,Q){
		int A,B,C,D;
		cin >> A>>B>>C>>D;
		A--,B--,D--,C--;
		int X=dist(A,B)+dist(C,D);
		int Y=min(dist(A,C)+dist(B,D),dist(A,D)+dist(B,C));
		if(Y>X){
			cout << "0\n";
		}else{
			cout << (X-Y+2)/2<<"\n";
		}
	}
	
    return 0;
}
