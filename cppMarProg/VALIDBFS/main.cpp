#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;

unordered_set<int> adjList[200005];
int visited[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifdef LOCAL
     freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif
    int n;
    cin >> n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        adjList[x].insert(y);
        adjList[y].insert(x);
    }

    vector<int> toCheck;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        a--;
        toCheck.pb(a);
    }
    queue<int> cola;
    int index=0;
    cola.push(0);
    visited[0]=1;
    int possible=1;
    if(toCheck[index]!=0)possible=0;
    index++;
    while(!cola.empty() &&possible){
        int u=cola.front();cola.pop();
        int cnt=0;
        while(adjList[u].find(toCheck[index])!=adjList[u].end() && !visited[toCheck[index]]){
            visited[toCheck[index]]=1;
            cola.push(toCheck[index]);
            cnt++;
            index++;
        }
        if(u==0){
            if(cnt!=adjList[u].size())possible=0;
        }else{
            if(cnt!=adjList[u].size()-1)possible=0;
        }
    }
    if(possible){
        cout << "Yes\n";
    }else{
        cout << "No\n";
    }
}
