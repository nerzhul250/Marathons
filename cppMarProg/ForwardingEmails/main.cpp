#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

const int MAXN=50005;

vector<int> g2[MAXN];
set<int> checkConnection [MAXN];
int nodeCnt[MAXN];
int nodeMin[MAXN];
int visited[MAXN];
int dp[MAXN];
int N;

vector<int> g[MAXN];
int d[MAXN],low[MAXN],scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;

void tarjan(int u){
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  const vector<int> &out = g[u];
  for (int k=0, m=out.size(); k<m; ++k){
    const int &v = out[k];
    if (d[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }else if (stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }
  if (d[u] == low[u]){
    int v;
    int cnt=0;
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
      nodeMin[current_scc]=min(nodeMin[current_scc],v);
      cnt++;
    }while (u != v);
    nodeCnt[current_scc]=cnt;
    current_scc++;
  }
}

void init_everything(int N){
    fore(i,0,N){
        g[i].clear();
        g2[i].clear();
        d[i]=-1;
        scc[i]=-1;
        stacked[i]=false;
        visited[i]=0;
        checkConnection[i].clear();
        nodeMin[i]=100000000;
        dp[i]=-1;
    }
    ticks=0;
    current_scc=0;
    while(!s.empty())s.pop();
 }


int longestPath(int u){
    if(dp[u]!=-1)return dp[u];
    if(g2[u].size()==0)return nodeCnt[u];
    int &r=dp[u];
    for(int v : g2[u]){
        r=max(r,longestPath(v));
    }
    r=r+nodeCnt[u];
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    fore(t,1,T+1){
        cin >> N;
        init_everything(N);
        fore(i,0,N){
            int u,v;
            cin >> u >> v;
            u--;
            v--;
            g[u].pb(v);
        }
        fore(i,0,N)if(scc[i]==-1)tarjan(i);
        fore(i,0,N){
            for(int u : g[i]){
                if(scc[i]!=scc[u] && checkConnection[scc[i]].count(scc[u])==0){
                    g2[scc[i]].pb(scc[u]);
                    checkConnection[scc[i]].insert(scc[u]);
                }
            }
        }
        int longPath=0;
        int vertex=-1;
        fore(i,0,current_scc){
            if(longestPath(i)>longPath){
                longPath=longestPath(i);
                vertex=nodeMin[i]+1;
            }else if(longestPath(i)==longPath){
                vertex=min(vertex,nodeMin[i]+1);
            }
        }
        cout << "Case "<<t<<": " <<vertex<<"\n";
    }

    return 0;
}
