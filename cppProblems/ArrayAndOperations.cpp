#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long int ll;
const int INF=1e9;
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
int nodes;
map<int,int> mp[105];
map<int,int> mp2[105];
int main(){FIN;
	int n,m;
	cin >> n >> m;
	fore(i,0,n){
		int x;
		cin >> x;
		for(int j=2;j*j<=x;j++){
			while(x%j==0){
				mp[i][j]++;
				x/=j;
			}
		}
		if(x>1)mp[i][x]++;
		nodes+=mp[i].size();
	}
	nodes+=2;
	Dinic din(nodes,nodes-2,nodes-1);
	int index=0;
	fore(i,0,n){
		if(i%2==0){
			for(auto it=mp[i].begin();it!=mp[i].end();it++){
				mp2[i][it->ff]=index;
				din.add_edge(index,nodes-1,it->ss);
				index++;
			}
		}else{
			for(auto it=mp[i].begin();it!=mp[i].end();it++){
				mp2[i][it->ff]=index;
				din.add_edge(nodes-2,index,it->ss);
				index++;
			}
		}
	}
	fore(i,0,m){
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		if(a%2==0)swap(a,b);
		for(auto it=mp[a].begin();it!=mp[a].end();it++){
			if(mp[b].count(it->ff)){
				din.add_edge(mp2[a][it->ff],mp2[b][it->ff],INF);
			}
		}
	}
	cout << din.flow()<<"\n";
    return 0;
}
