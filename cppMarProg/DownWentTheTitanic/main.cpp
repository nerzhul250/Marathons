#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char symbols[35][35];
int const INF=1e9;
int X,Y,P;
int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

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

void connect(int ori, int orj, int desi, int desj){
    if(desi>=0 && desi<X && desj>=0 && desj<Y){
        int VOin=ori*Y+orj+1;
        int VOout=ori*Y+orj+1+X*Y;
        int VDin=desi*Y+desj+1;
        int VDout=desi*Y+desj+1+X*Y;

        adj[VOout].push_back(VDin);
        adj[VDin].push_back(VOout);
        capacity[VOout][VDin]=INF;

        adj[VDout].push_back(VOin);
        adj[VOin].push_back(VDout);
        capacity[VDout][VOin]=INF;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >>X){
        cin >> Y >> P;
        n=X*Y*2+2;
        capacity.clear();
        adj.clear();
        for(int i=0;i<n;i++){
            capacity.push_back(vector<int>(n,0));
            adj.push_back(vector<int>(1,0));
            adj[i].clear();
        }
        for(int i=0;i<X;i++){
            char c;
            for(int j=0;j<Y;j++){
                cin >> c;
                symbols[i][j]=c;
            }
        }
        for(int i=0;i<X;i++){
            for(int j=0;j<Y;j++){
                int Vin=i*Y+j+1;
                int Vout=i*Y+j+1+X*Y;
                adj[Vin].push_back(Vout);
                adj[Vout].push_back(Vin);
                connect(i,j,i,j+1);
                connect(i,j,i+1,j);
                if(symbols[i][j]=='~'){
                    capacity[Vin][Vout]=0;
                }else if(symbols[i][j]=='*'){
                    capacity[Vin][Vout]=1;
                    capacity[0][Vin]=INF;
                    capacity[Vout][0]=INF;
                    adj[0].push_back(Vin);
                    adj[Vin].push_back(0);
                    adj[Vout].push_back(0);
                    adj[0].push_back(Vout);
                }else if(symbols[i][j]=='.'){
                    capacity[Vin][Vout]=1;
                }else if(symbols[i][j]=='@'){
                    capacity[Vin][Vout]=INF;
                }else if(symbols[i][j]=='#'){
                    capacity[Vin][Vout]=INF;
                    capacity[Vout][X*Y*2+1]=P;
                    capacity[X*Y*2+1][Vin]=P;
                    adj[Vout].push_back(X*Y*2+1);
                    adj[X*Y*2+1].push_back(Vout);
                    adj[X*Y*2+1].push_back(Vin);
                    adj[Vin].push_back(X*Y*2+1);
                }
            }
        }
        int answer=maxflow(0,X*Y*2+1);
        cout << answer << "\n";
    }
    return 0;
}
