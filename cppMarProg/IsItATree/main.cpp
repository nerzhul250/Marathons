#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

vi adjList[10005];
int visited[10005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int N,M;
    cin >> N>>M;
    for(int i=0;i<M;i++){
        int u,v;
        cin >> u>>v;
        u--;
        v--;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    int isTree=1;
    queue<ii> cola;
    cola.push({0,-1});
    visited[0]=1;
    while(!cola.empty() && isTree){
        ii u=cola.front();cola.pop();
        for(int v : adjList[u.ff]){
            if(v!=u.ss){
                if(visited[v]){
                    isTree=0;
                    break;
                }else{
                    visited[v]=1;
                    cola.push({v,u.ff});
                }
            }
        }
    }

    for(int i=0;i<N;i++){
        if(!visited[i]){
            isTree=0;
            break;
        }
    }

    if(isTree){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }

}
