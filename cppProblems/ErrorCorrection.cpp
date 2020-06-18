#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
//Solves MAXflow in O(V^2 * E)
//O(E* sqrt(V)) if graph is unitary hehe (unit capacities)
//O(E * log(v) ) if graph is maybe... a dag or bipartite?
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
string words[505];
vector<int> g[505];
int visited[505];
int color[505];
void bfs(int node){
	visited[node]=1;
	color[node]=0;
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(!visited[v]){
				visited[v]=1;
				color[v]=1-color[u];
				q.push(v);
			}
		}
	}
	return ;
}
bool neigh(int a,int b){
	int tot_diffs = 0;
	fore(k,0,SZ(words[a]))if(words[a][k] != words[b][k])tot_diffs++;
	return tot_diffs == 2;
}
int main(){FIN;
	int N;
	cin >> N;
	fore(i,0,N){
		cin >> words[i];
	}
	fore(i,0,N-1){
		fore(j,i+1,N){
			if(neigh(i,j)){
				g[i].pb(j);
				g[j].pb(i);
			}
		}
	}
	fore(i,0,N){
		if(!visited[i]){
			bfs(i);
		}
	}
	Dinic din(N+2,N,N+1);
	fore(i,0,N){
		if(color[i]==0){
			for(int u:g[i]){
				din.add_edge(i,u,1);
			}
		}
		if(color[i]==0){
			din.add_edge(N,i,1);
		}else{
			din.add_edge(i,N+1,1);
		}
	}
	cout << N-din.flow()<<"\n";
    return 0;
}
