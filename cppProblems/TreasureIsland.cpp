#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
const int INF=1e9;

vector<unordered_map<int,int>> capacity;
vector<int> adj[1000005];
int n, m;

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
    vector<int> parent(2*n*m+2);
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

int dx[2]={1,0};
int dy[2]={0,1};
int vin(int i, int j){return (i*m+j)<<1;}
int vout(int i, int j){return ((i*m+j)<<1)|1;}

int main(){FIN;
	cin >> n >> m;
	char theMap[n+1][m+1];
	int s=2*n*m,t=2*n*m+1;
	fore(i,0,2*n*m+2){capacity.pb(unordered_map<int,int>());}
	fore(i,0,n)fore(j,0,m)cin >> theMap[i][j];
	fore(i,0,n){
		fore(j,0,m){
			if(i==0 && j==0){
				capacity[s][vout(i,j)]=INF;
				adj[s].pb(vout(i,j));
				adj[vout(i,j)].pb(s);
			}else if(i==n-1 && j==m-1){
				capacity[vin(i,j)][t]=INF;
				adj[vin(i,j)].pb(t);
				adj[t].pb(vin(i,j));				
			}else{
				capacity[vin(i,j)][vout(i,j)]=1;
				adj[vin(i,j)].pb(vout(i,j));
				adj[vout(i,j)].pb(vin(i,j));
			}
			fore(k,0,2){
				int io=i+dy[k];
				int jo=j+dx[k];
				if(io>=0 && io<n && jo>=0 && jo<m && theMap[io][jo]!='#'){					
					capacity[vout(i,j)][vin(io,jo)]=1;
					adj[vout(i,j)].pb(vin(io,jo));
					adj[vin(io,jo)].pb(vout(i,j));
				}
			}
		}
	}
	cout << maxflow(s,t)<<"\n";
    return 0;
}
