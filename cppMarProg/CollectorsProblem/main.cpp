#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int const INF= 1e9;
int n,N,M;
vector<vector<int>> capacity (36,vector<int>(36,0));
vector<vector<int>> adj(36,vector<int>());

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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T,orr;
    cin >> T;
    orr=T;
    while(T--){
        cin >> N >> M;
        n=N+M+1;
        int cards[15][30]={{0}};
        fill(adj.begin(),adj.begin()+n,vector<int>());
        fill(capacity.begin(),capacity.begin()+n,vector<int>(n,0));
        for(int i=0;i<N;i++){
            int k;
            cin >> k;
            for(int j=0;j<k;j++){
                int cat;
                cin >> cat;
                cards[i][cat-1]++;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i==0){
                    adj[N+j].push_back(N+M);
                    adj[N+M].push_back(N+j);
                    capacity[N+j][N+M]=1;
                }
                adj[i].push_back(N+j);
                adj[N+j].push_back(i);
                capacity[i][N+j]=(i==0?cards[i][j]:max(0,cards[i][j]-1));
                if(i!=0 && cards[i][j]==0)capacity[N+j][i]=1;
            }
        }

        int mf=maxflow(0,N+M);

        cout <<"Case #" <<orr-T <<": "<< mf << "\n";

    }



    return 0;
}
