#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;i++)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef long long int ll;

int N;
int totalNodes;
map<string,int> topicToIndex;
vector<vector<int>> teachersTopics;
map<vector<int>,int> setToIndex;


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

int main(){FIN;
	cin >> N;
	fore(i,0,N)teachersTopics.pb(vector<int>());
	fore(i,0,N){
		int A;
		cin >> A;
		totalNodes+=(1<<A);
		fore(j,0,A){
			string s;
			cin >> s;
			if(!topicToIndex.count(s))topicToIndex[s]=topicToIndex.size();
			teachersTopics[i].pb(topicToIndex[s]);
		}
		sort(ALL(teachersTopics[i]));
	}
	totalNodes*=2;
	Dinic din=Dinic(totalNodes+2,totalNodes,totalNodes+1);
	if(!setToIndex.count(vector<int>()))setToIndex[vector<int>()]=setToIndex.size();
	fore(i,0,N){
		vector<int> topics=teachersTopics[i];
		fore(mask,1,(1<<topics.size())){
			vector<int> aux;
			fore(j,0,topics.size())if(((1<<j)&mask)!=0)aux.pb(topics[j]);
			if(!setToIndex.count(aux))setToIndex[aux]=setToIndex.size();
			fore(mask2,0,(1<<aux.size())){
				if(__builtin_popcount(mask2)+1==__builtin_popcount(mask)){
					vector<int> aux2;
					fore(j,0,aux.size())if(((1<<j)&mask2)!=0)aux2.pb(aux[j]);
					if(!setToIndex.count(aux2))setToIndex[aux2]=setToIndex.size();
					din.add_edge((setToIndex[aux2]<<1),(setToIndex[aux]<<1)|1,1);
				}
			}
		}
	}
	fore(i,0,setToIndex.size()){
		din.add_edge(totalNodes,i<<1,1);
		din.add_edge((i<<1)|1,totalNodes+1,1);
	}
	int flow=din.flow();
	cout << setToIndex.size()-flow << "\n";
    return 0;
}
