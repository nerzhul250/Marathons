#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF=1e9;
int n,sensors[105],queuesCapacities[35];
vector<vector<int>> capacity,adj;

int bfs(int s, int t,vector<int>& parent){
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<int,int>> q;
    q.push({s,INF});
    while(!q.empty()){
        int cur=q.front().first;
        int flow= q.front().second;
        q.pop();

        for(int next : adj[cur]){
            if(parent[next]==-1 && capacity[cur][next]){
                parent[next]=cur;
                int new_flow=min(flow,capacity[cur][next]);
                if(next==t)return new_flow;
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}

int maxflow(int s, int t){
    int flow=0;
    vector<int> parent(n);
    int new_flow;
    while(new_flow=bfs(s,t,parent)){
        flow+=new_flow;
        int cur=t;
        while(cur!=s){
            int prev=parent[cur];
            capacity[prev][cur]-=new_flow;
            capacity[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}

int main()
{
    int N,Q,S;
    while(cin >> N){
        cin >> Q >> S;
        n=Q+3;
        adj.clear();
        for(int i=0;i<Q+3;i++)adj.push_back(vector<int>(1)),adj[i].clear();
        adj[Q+1].push_back(Q+2);
        adj[Q+2].push_back(Q+1);
        for(int i=1;i<=S;i++){
            int q;
            cin >> q;
            sensors[i]=q;
        }
        for(int i=1;i<=Q;i++){
            int capa;
            cin >> capa;
            adj[i].push_back(Q+1);
            adj[Q+1].push_back(i);
            adj[0].push_back(i);
            adj[i].push_back(0);
            queuesCapacities[i]=capa;
        }
        int sum=0;
        int actualSum=0;
        capacity.clear();
        for(int j=0;j<Q+3;j++)capacity.push_back(vector<int>(Q+3,0));
        for(int i=0;i<N;i++){
            int d;
            cin >> d;
            capacity[Q+1][Q+2]=d;
            capacity[Q+2][Q+1]=0;
            for(int j=1;j<=S;j++){
                int a;
                cin >> a;
                sum+=a;
                capacity[sensors[j]][Q+1]=min(queuesCapacities[sensors[j]],a+capacity[sensors[j]][Q+1]);
                capacity[Q+1][sensors[j]]=0;
            }
            for(int j=1;j<=Q;j++){
                capacity[0][j]=INF;
                capacity[j][0]=0;
            }
            int maximumFlow=maxflow(0,Q+2);
            actualSum+=maximumFlow;
        }
        if(actualSum==sum){
            cout<<"possible\n";
        }else{
            cout << "impossible\n";
        }
    }
    return 0;
}
