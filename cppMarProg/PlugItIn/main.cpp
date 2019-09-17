#include <iostream>
#include <vector>
#include <queue>

#define MAX 100001
#define NIL 0
#define INF (1<<28)


using namespace std;

vector< int > G[MAX];
int n, m,k, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] ∪ G1[G[1---n]] ∪ G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n >>k;
    for(int i=0;i<k;i++){
        int x,y;
        cin >> x >>y;
        x=x+n;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int originalMatching=hopcroft_karp();
    int maxMatching=originalMatching;
    int originalMatches[MAX];
    for(int i=0;i<=n+m+2;i++)originalMatches[i]=match[i];
    for(int i=n+1;i<=n+m;i++){
        if(G[i].size()>1){
            for(int j=0;j<G[i].size();j++){
                G[n+m+1].push_back(G[i][j]);
                G[n+m+2].push_back(G[i][j]);
                G[G[i][j]].push_back(n+m+1);
                G[G[i][j]].push_back(n+m+2);
            }
            maxMatching=max(maxMatching,originalMatching+hopcroft_karp());
            G[n+m+1].clear();
            G[n+m+2].clear();
            for(int j=0;j<G[i].size();j++){
                G[G[i][j]].erase(G[G[i][j]].end()-1);
                G[G[i][j]].erase(G[G[i][j]].end()-1);
            }
            for(int j=0;j<=n+m+2;j++)match[j]=originalMatches[j];
        }
    }
    cout <<  maxMatching<< "\n";
    return 0;
}
