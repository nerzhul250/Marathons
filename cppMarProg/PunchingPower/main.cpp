#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

vi match, vis; // global variables
vi AdjList [2005];
int color[2005],V,visited[2005];
map<ii,int> pToN;

int Aug(int l) { // return 1 if an augmenting path is found
if (vis[l]) return 0; // return 0 otherwise
vis[l] = 1;
for (int j = 0; j < (int)AdjList[l].size(); j++) {
int r = AdjList[l][j]; // edge weight not needed -> vector<vi> AdjList
if (match[r] == -1 || Aug(match[r])) {
match[r] = l; return 1; // found 1 matching
} }
return 0; // no matching
}

void setUpNeighbors(ii pos,int node,int type){
    if(visited[node])return;
    visited[node]=1;
    color[node]=type;
    ii g=ii(pos.first-1,pos.second);
    if(pToN.find(g)!=pToN.end()){
        AdjList[node].push_back(pToN[g]);
        setUpNeighbors(g,pToN[g],1-type);
    }
    g=ii(pos.first+1,pos.second);
    if(pToN.find(g)!=pToN.end()){
        AdjList[node].push_back(pToN[g]);
        setUpNeighbors(g,pToN[g],1-type);
    }
    g=ii(pos.first,pos.second-1);
    if(pToN.find(g)!=pToN.end()){
        AdjList[node].push_back(pToN[g]);
        setUpNeighbors(g,pToN[g],1-type);
    }
    g=ii(pos.first,pos.second+1);
    if(pToN.find(g)!=pToN.end()){
        AdjList[node].push_back(pToN[g]);
        setUpNeighbors(g,pToN[g],1-type);
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> V){
        pToN.clear();
        for(int i=0;i<V;i++){AdjList[i].clear();visited[i]=0;}
        for(int i=0;i<V;i++){
            int x,y;
            cin >> x >> y;
            pToN[ii(x,y)]=i;
        }
        setUpNeighbors(pToN.begin()->first,pToN.begin()->second,0);
         // build unweighted bipartite graph with directed edge left->right set
        int MCBM = 0;
        match.assign(V, -1); // V is the number of vertices in bipartite graph
        for (int l = 0; l < V; l++) { // n = size of the left set
            if(color[l]==0){
                vis.assign(V, 0); // reset before each recursion
                MCBM += Aug(l);
            }
        }
        cout << V-MCBM << "\n";
    }
    return 0;
}
