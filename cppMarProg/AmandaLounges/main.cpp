#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;

int n,m;
vi adjList[200005];
int color[200005],colorAux[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    memset(color,-1,sizeof color);
    int possible=1;
    int start=-1;
    cin >> n >> m;
    for(int i=0;i<m && possible;i++){
        int a,b,c;
        cin >> a >> b >> c;
        a--;
        b--;
        if(c==0){
            if(color[a]==1 || color[b]==1)possible=0;
            color[a]=0;
            color[b]=0;
            start=a;
        }else if(c==2){
            if(color[a]==0 || color[b]==0)possible=0;
            color[a]=1;
            color[b]=1;
            start=a;
        }
        adjList[a].pb(b);
        adjList[b].pb(a);
    }
    if(start==-1){
        start=0;
        color[]
    }else{
        queue<int> cola;
        int visited[n+5];
        memset(visited,0,sizeof visited);
        cola.push(start);
        while(!cola.empty()){
            int u=cola.front();cola.pop();
            for(int v : adjList[u]){
                if(!visited[v]){

                }
            }
        }
    }

}
