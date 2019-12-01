#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;


int visited[200005],minimo=1e9,maximo=-1;
vector<int> adjList[200005];



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int n,m;
    cin >> n>> m;
    fore(i,0,n){
        int u,v;
        cin >> u>>v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    fore(){
    }

    return 0;
}
