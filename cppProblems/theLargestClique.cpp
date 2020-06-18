#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

/* Complexity: O(E + V)
 Tarjan's algorithm for finding strongly connected
components.
 *d[i] = Discovery time of node i. (Initialize to -1)
 *low[i] = Lowest discovery time reachable from node
 i. (Doesn't need to be initialized)
 *scc[i] = Strongly connected component of node i. (Doesn't
 need to be initialized)
 *s = Stack used by the algorithm (Initialize to an empty
 stack)
 *stacked[i] = True if i was pushed into s. (Initialize to
 false)
 *ticks = Clock used for discovery times (Initialize to 0)
 *current_scc = ID of the current_scc being discovered
 (Initialize to 0)
*/
const int MAXN=1005;
vector<int> g[MAXN];
set<int> gScc[MAXN];
int d[MAXN], low[MAXN], scc[MAXN], sccSize[MAXN];
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
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
      sccSize[current_scc]++;
    }while (u != v);
    current_scc++;
  }
}
void init_tarjan(){
	memset(d,-1,sizeof d);
	while(!s.empty())s.pop();
	memset(stacked,0,sizeof stacked);
	memset(sccSize,0,sizeof sccSize);
	ticks=0;
	current_scc=0;
}
int dp[MAXN];
int largestClique(int u){
	if(dp[u]!=-1)return dp[u];
	int maximum=0;
	for(int v:gScc[u]){
		maximum=max(maximum,largestClique(v));
	}
	return dp[u]=maximum+sccSize[u];
}

int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		fore(i,0,n){
			g[i].clear();
			gScc[i].clear();
		}
		fore(i,0,m){
			int u,v;
			cin >> u >> v;
			u--,v--;
			g[u].pb(v);
		}
		init_tarjan();
		fore(i,0,n)if(d[i]==-1)tarjan(i);
		fore(u,0,n){
			for(int v:g[u]){
				if(scc[u]!=scc[v]){
					gScc[scc[u]].insert(scc[v]);
				}
			}
		}
		memset(dp,-1,sizeof dp);
		int maximum=0;
		//cout << current_scc<<"\n";
		fore(i,0,current_scc){
			if(dp[i]==-1){
				largestClique(i);
			}
			maximum=max(maximum,dp[i]);
		}
		cout << maximum << "\n";
	}
    return 0;
}
