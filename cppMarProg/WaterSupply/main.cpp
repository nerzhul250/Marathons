#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector<int> vi;

vi AdjList [1005];
vi AdjListSCCFathers[1005];
int adjMatrix[1005][1005],N,M,container0;
unordered_map<int,int> vertToSCC;

int const UNVISITED=-1;
int dfsNumberCounter,numSCC;
vi dfs_num, dfs_low, S, visited; // global variables

void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == UNVISITED)
            tarjanSCC(v);
        if (visited[v]) // condition for update
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }

    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        ++numSCC;
        while (1) {
            int v = S.back(); S.pop_back(); visited[v] = 0;
            vertToSCC[v]=numSCC-1;
            if(v==0)container0=numSCC-1;
            if (u == v) break;
        }
    }
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> N){
        cin >> M;
        for(int i=0;i<N+1;i++){
            AdjList[i].clear();
            AdjListSCCFathers[i].clear();
            for(int j=0;j<N+1;j++){
                adjMatrix[i][j]=0;
            }
        }
        vertToSCC.clear();
        for(int i=0;i<M;i++){
            int a,b;
            cin >> a >> b;
            AdjList[a].push_back(b);
        }
        int V=N+1;
        dfs_num.assign(V, UNVISITED); dfs_low.assign(V, 0); visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;
        for (int i = 0; i < V; i++)
            if (dfs_num[i] == UNVISITED)
                tarjanSCC(i);

        for(int i=0;i<V;i++){
            for(int j=0;j<AdjList[i].size();j++){
                int scc1=vertToSCC[i];
                int scc2=vertToSCC[AdjList[i][j]];
                if(scc1!=scc2 && adjMatrix[scc1][scc2]==0){
                    AdjListSCCFathers[scc2].push_back(scc1);
                    adjMatrix[scc1][scc2]=1;
                }
            }
        }
        int counter=0;
        for(int i=0;i<numSCC;i++){
            if(AdjListSCCFathers[i].size()==0 && i!=container0){
                counter++;
            }
        }
        cout << counter << "\n";
    }
    return 0;
}
