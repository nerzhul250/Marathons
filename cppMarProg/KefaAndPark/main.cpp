#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
int const INF=100005;
vector <int> AdjList[INF];
int acum[INF],hasCat[INF],safe[INF],n,m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> hasCat[i];
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        AdjList[x].push_back(y);
        AdjList[y].push_back(x);
    }
    int counter=0;
    if(hasCat[0])acum[0]=1;
    vi d(n, INF); d[0] = 0; // distance from source s to s is 0
    queue<int> q; q.push(0); // start from source
    while (!q.empty()) {
    int u = q.front(); q.pop(); // queue: layer by layer!
    if(((int)AdjList[u].size())==1 && u!=0 && safe[u]==0)counter++;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
    int v = AdjList[u][j]; // for each neighbor of u
    if (d[v] == INF) { // if v.first is unvisited + reachable
    d[v] = d[u] + 1; // make d[v.first] != INF to flag it
    q.push(v); // enqueue v.first for the next iteration
    safe[v]=safe[u];
    if(hasCat[u]&hasCat[v]){
        acum[v]=1+acum[u];
        if(acum[v]>m)safe[v]=1;
    }else{
        if(hasCat[v]){
            acum[v]=1;
        }
    }
    } } }
    cout << counter << "\n";
    return 0;
}
