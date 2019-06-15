#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

//LOWEST COMMON ancestor and MAX EDGE BETWEEN TWO NODES IN A TREE
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

struct Edge
{
    int v;
    int u;
    int c;
    int t;
    int j;
};

auto cmp = [](Edge &a, Edge &b) { return a.c>b.c;};
priority_queue<Edge,vector<Edge>, decltype(cmp)> pq(cmp);
vector<Edge> AdjList [100006];
map<int,map<int,int>>roads;
vi taken; // global boolean flag to avoid cycle

int timer,l;
vi tin, tout, up [100006],maxEdge[100006];


int N,R,Q,A,B,C,x,y,LCA;

void process(int vtx) { // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        Edge v = AdjList[vtx][j];
        if (!taken[v.u]) pq.push(v);
} }

void dfs(int v, int p,int edgy)
{
    tin[v] = ++timer;
    up[v][0]=p;
    maxEdge[v][0]=edgy;
    for (int i = 1; i <= l; ++i){
        up[v][i]=up[up[v][i-1]][i-1];
        maxEdge[v][i]=max(maxEdge[v][i-1],maxEdge[up[v][i-1]][i-1]);
    }

    for (Edge e : AdjList[v]) {
        if (e.t==1)
            dfs(e.u,v,e.c);
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

int maxEdgeF(int u,int uAncestor){
    if(u==uAncestor)return -1;
    int maxEdgy=maxEdge[u][0];
    for (int i = l; i >= 0; --i) {
        if (!is_ancestor(up[u][i],uAncestor)){
            if(maxEdge[u][i]>maxEdgy)maxEdgy=maxEdge[u][i];
            u = up[u][i];
        }
    }
    if(maxEdge[u][0]>maxEdgy)maxEdgy=maxEdge[u][0];
    return maxEdgy;
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    tin.assign(100006,0);
    tout.assign(100006,0);
    l = ceil(log2(100006));
    for(int i=0;i<100006;i++){
        up[i].assign(l+1,0);
        maxEdge[i].assign(l+1,0);
    }
    while(scanf("%d %d", &N, &R) != EOF){

        for(int i=0;i<N;i++){
            AdjList[i].clear();
        }

        for(int i=0;i<R;i++){
            scanf("%d %d %d",&A,&B,&C);
            A--;
            B--;
            roads[A][B]=C;
            Edge temp = {A,B,C,0,AdjList[A].size()};
            AdjList[A].push_back(temp);
            temp = {B,A,C,0,AdjList[B].size()};
            AdjList[B].push_back(temp);
        }

        taken.assign(N, 0); // no vertex is taken at the beginning
        process(0); // take vertex 0 and process all edges incident to vertex 0
        int mst_cost = 0;
        while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
            Edge front = pq.top(); pq.pop();
            x = front.u, y = front.c; // negate the id and weight again
            if (!taken[x]){
                mst_cost += y, process(x); // take u, process all edges incident to u
                AdjList[front.v][front.j].t=1;
            } // we have not connected this vertex yet
        } // each edge is in pq only once!


        timer = 0;
        l = ceil(log2(N));

        dfs(0,0,0);

        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            scanf("%d %d",&A,&B);
            A--;
            B--;
            LCA=lca(A,B);
            printf("%d\n",mst_cost + roads[A][B]-(max(maxEdgeF(A,LCA),maxEdgeF(B,LCA))));
        }
    }
    return 0;
}
