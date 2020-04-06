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

typedef pair<int,int> ii;

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

ii myVictims[60];
int myMurderers[60];

int main(){FIN;
	int N;
	cin >> N;
	n=N*2+2;
	int s=n-2;
	int t=n-1;
	fore(i,0,n)adj.pb(vector<int>());
	fore(i,0,N){
		cin >> myVictims[i].ff >> myVictims[i].ss;
		myVictims[i].ff--;
		myVictims[i].ss--;
		myMurderers[myVictims[i].ff]++;
		myMurderers[myVictims[i].ss]++;
		
		adj[s].pb(i);
		adj[i].pb(s);
		
		adj[i].pb(myVictims[i].ff+N);
		adj[myVictims[i].ff+N].pb(i);
		
		adj[i].pb(myVictims[i].ss+N);
		adj[myVictims[i].ss+N].pb(i);
		
		adj[i+N].pb(t);
		adj[t].pb(i+N);
	}
	int cnt=0;
	fore(werewolf,0,N){
		capacity.clear();
		fore(i,0,n)capacity.pb(vector<int>(n,0));
		int remVotes=0;
		fore(voter,0,N){
			if(voter != werewolf){
				if(myVictims[werewolf].ff==voter || myVictims[werewolf].ss==voter){
					capacity[voter+N][t]=max(myMurderers[werewolf]-2,0);
				}else{
					capacity[voter+N][t]=max(myMurderers[werewolf]-1,0);
				}
				if(myVictims[voter].ff!=werewolf && myVictims[voter].ss!=werewolf){					
					capacity[voter][myVictims[voter].ff+N]=1;
					capacity[voter][myVictims[voter].ss+N]=1;
					capacity[s][voter]=1;
					remVotes++;
				}
			}
		}
		int flow=maxflow(s,t);
		if(remVotes==flow)cnt++;
	}
	cout << N-cnt << "\n";
    return 0;
}
