#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


vector<int> adjList [85];int n;
int parents[85];
int dfs(int node,int visited[85]){
    visited[node]=1;
    int maximum=0;
    for(int i=0;i<adjList[node].size();i++){
        if(visited[adjList[node][i]]==0){
            maximum=max(maximum,dfs(adjList[node][i],visited)+1);
        }
    }
    return maximum;
}

void dfs2(int node, int visited[85])
{
    visited[node] = 1;
    for(int i=0;i < adjList[node].size();i++)
    {
        if(visited[adjList[node][i]] == 0){
            parents[adjList[node][i]] = node;
            dfs2(adjList[node][i], visited);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int r,h,m;
    cin >> r >> h >> m;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >>a >>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int minimum=1e9,visited[85];
    int root =1e9;
    for(int i=1;i<=n;i++){
        memset(visited,0,sizeof visited);
        int current = dfs(i,visited);
        if(minimum > current)
        {
            root = i;
        }
        minimum=min(minimum,current);
    }
    memset(visited,0,sizeof visited);
    dfs2(root, visited);

    int currentNode = parents[r];
    while(currentNode!=0&&currentNode != root && currentNode != h && currentNode != m)
    {
        currentNode= parents[currentNode];
    }
    if(currentNode == h || currentNode == m){
        int dist=0;
        while(currentNode!=root){
            dist++;
            currentNode=parents[currentNode];
        }
        minimum=minimum-dist;
    }else{
        minimum++;
    }
    cout << minimum << "\n";
    return 0;
}
