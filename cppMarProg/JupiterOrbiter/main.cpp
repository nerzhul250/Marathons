#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long int ll;
const int INF=1e9;
int sensors[105],queuesCapacities[35];

template <class T> struct Edge {
    int from, to, index;
    T cap, flow;

    Edge(int from, int to, T cap, T flow, int index): from(from), to(to), cap(cap), flow(flow), index(index) {}
};

template <class T> struct PushRelabel {
    int n;
    vector <vector <Edge <T>>> adj;
    vector <T> excess;
    vector <int> dist, count;
    vector <bool> active;
    vector <vector <int>> B;
    int b;
    queue <int> Q;

    PushRelabel (int n): n(n), adj(n) {}

    void AddEdge (int from, int to, T cap) {
        adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
        if (from == to) {
            adj[from].back().index++;
        }
        adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));

    }

    void Enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < n) {
            active[v] = true;
            B[dist[v]].push_back(v);
            b = max(b, dist[v]);
        }
    }

    void Push (Edge <T> &e) {
        T amt = min(excess[e.from], e.cap - e.flow);
        if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
            e.flow += amt;
            adj[e.to][e.index].flow -= amt;
            excess[e.to] += amt;
            excess[e.from] -= amt;
             Enqueue(e.to);
        }

    }

    void Gap (int k) {
        for (int v = 0; v < n; v++) if (dist[v] >= k) {
            count[dist[v]]--;
            dist[v] = max(dist[v], n);
            count[dist[v]]++;
            Enqueue(v);
        }
    }

    void Relabel (int v) {
        count[dist[v]]--;
        dist[v] = n;
        for (auto e: adj[v]) if (e.cap - e.flow > 0) {
            dist[v] = min(dist[v], dist[e.to] + 1);
        }
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v) {
        for (auto &e: adj[v]) {
            if (excess[v] > 0) {
                Push(e);
            } else {
                break;
            }
        }

        if (excess[v] > 0) {
            if (count[dist[v]] == 1) {
                Gap(dist[v]);
            } else {
                Relabel(v);
            }
        }
    }

    T GetMaxFlow (int s, int t) {
        dist = vector <int>(n, 0), excess = vector<T>(n, 0), count = vector <int>(n + 1, 0), active = vector <bool>(n, false), B = vector <vector <int>>(n), b = 0;

        for (auto &e: adj[s]) {
            excess[s] += e.cap;
        }
        count[0] = n;
        Enqueue(s);
        active[t] = true;
        while (b >= 0) {
            if (!B[b].empty()) {
                int v = B[b].back();
                B[b].pop_back();
                active[v] = false;
                Discharge(v);
            } else {
                b--;
            }
        }
        return excess[t];
    }
};


int main()
{
    int N,Q,S,n;
    while(cin >> N){
        cin >> Q >> S;
        n=N*(2*Q+1)+2;
        for(int i=0;i<S;i++){
            cin >>sensors[i];
        }
        for(int i=0;i<Q;i++){
            cin >>queuesCapacities[i];
        }
        PushRelabel<ll> maxFlowGraph(n);
        ll sum=0;
        for(int i=0;i<N;i++){
            int d;
            cin >> d;
            for(int j=1;j<=Q;j++){
                maxFlowGraph.AddEdge(i*(2*Q+1)+j,i*(2*Q+1)+j+Q,queuesCapacities[j-1]);
                maxFlowGraph.AddEdge(i*(2*Q+1)+j+Q,i*(2*Q+1)+2*Q+1,INF);
                if(i!=0)maxFlowGraph.AddEdge((i-1)*(2*Q+1)+j+Q,i*(2*Q+1)+j,INF);
            }
            maxFlowGraph.AddEdge(i*(2*Q+1)+2*Q+1,N*(2*Q+1)+1,d);
            for(int j=0;j<S;j++){
                int a;
                cin >> a;
                sum+=a;
                maxFlowGraph.AddEdge(0,i*(2*Q+1)+sensors[j],a);
            }
        }
        ll maxFlow=maxFlowGraph.GetMaxFlow(0,N*(2*Q+1)+1);
        if(maxFlow==sum){
            cout << "possible\n";
        }else{
            cout << "impossible\n";
        }
    }
    return 0;
}
