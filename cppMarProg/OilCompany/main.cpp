#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF=1e9;
int n,W,H;
vector<vector<int>> capacity (410,vector<int>(410,0));
vector<vector<int>> adj(410,vector<int>());

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void connect(int io,int jo,int id,int jd,int o){
    if(id<H && jd<W){
        int vo=io*W+jo+1;
        int vd=id*W+jd+1;
        adj[vo].push_back(vd);
        adj[vd].push_back(vo);
        if(o==0){
            capacity[vo][vd]=INF;
        }else{
            capacity[vd][vo]=INF;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int t=1;t<=N;t++){
        cin >> W >> H;
        n=W*H+2;
        fill(capacity.begin(),capacity.begin()+n,vector<int>(n,0));
        fill(adj.begin(),adj.begin()+n,vector<int>());
        int bset=1;
        int sum=0;
        for(int i=0;i<H;i++){
            bset=1-bset;
            int bset2=1-bset;
            for(int j=0;j<W;j++){
                bset2=1-bset2;
                int val;
                cin >> val;
                sum+=val;
                int v=i*W+j+1;
                if(bset2==0){
                    adj[0].push_back(v);
                    adj[v].push_back(0);
                    capacity[0][v]=val;
                }else{
                    adj[W*H+1].push_back(v);
                    adj[v].push_back(W*H+1);
                    capacity[v][W*H+1]=val;
                }
                connect(i,j,i+1,j,bset2);
                connect(i,j,i,j+1,bset2);
            }
        }
        int mf=maxflow(0,W*H+1);
        cout <<"Case "<<t<<": "<< sum-mf << "\n";
    }

    return 0;
}
