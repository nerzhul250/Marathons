#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;


struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

const int MAXN=1010;
int n,m;
vector<int>reachableNodes;
set<int> g[MAXN];
vector<int> tsort(){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*n,0);
	fore(i,0,n)for(int j:g[i])d[j]++;
	fore(i,0,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		for(int i : g[x]){
			d[i]--;
			if(!d[i])q.push(-i);
		}
	}
	return r;  // if not DAG it will have less than n elements
}
const int INF=1e9;
int adjMatrix[505][505];

int main(){FIN;
	cin >> n >> m;
	fore(i,0,m){
		int x,y;
		cin >> x >>y;
		g[x].insert(y);
	}
	reachableNodes=tsort();
	n=reachableNodes.size();
	Dinic din=Dinic(n*2+2,n*2,n*2+1);
	fore(i,0,n){
		fore(j,0,n){
			if(i==j){
				adjMatrix[i][j]=0;
			}else{
				adjMatrix[i][j]=INF;
			}
		}
	}
	fore(i,0,n){
		din.add_edge(n*2,i<<1,1);
		din.add_edge((i<<1)|1,n*2+1,1);
		fore(j,0,n){
			if(g[reachableNodes[i]].count(reachableNodes[j])){
				adjMatrix[i][j]=1;
			}
		}
	}
	
	fore(k,0,n)fore(i,0,n)if(adjMatrix[i][k]<INF)fore(j,0,n)if(adjMatrix[k][j]<INF)
		adjMatrix[i][j]=min(adjMatrix[i][j],adjMatrix[i][k]+adjMatrix[k][j]);
	
	fore(i,0,n){
		fore(j,0,n){
			if(adjMatrix[i][j]<INF && i!=j){
				din.add_edge(i<<1,(j<<1)|1,1);
			}
		}
	}
	
	int val=n-din.flow();
	cout <<val<<"\n";
    return 0;
}
