#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii;

const ll INF=1e15;

int n,m,k,startingTimes[1005],customers[1005],endTimes[1005];
ll distances[1005][1005];
map<ll,ll> dp[1005][1005];
vector<ii> AdjList [1005];

ll scheduling(int init,int fin,ll gt){
    if(init==fin && fin==k)return 0;
    if(!(init>=0 && fin<k))return 1e15;
    if(dp[init][fin].find(gt)!=dp[init][fin].end())return dp[init][fin][gt];

    gt=max(gt,(ll)endTimes[fin]);
    ll gta=gt,maximum=0;

    int previouseNode=0;
    for(int i=init;i<=fin;i++){
        ll timetaken=distances[previouseNode][customers[i]];
        gt+=timetaken;
        maximum=max(maximum,gt-startingTimes[i]);
        previouseNode=customers[i];
    }
    gt+=distances[previouseNode][0];

    return dp[init][fin][gt]=min(scheduling(init,fin+1,gta),max(scheduling(fin+1,fin+1,gt),maximum));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<m;i++){
        int u,v,d;
        cin >> u >> v >> d;
        u--;
        v--;
        AdjList[u].push_back(ii(v,d));
        AdjList[v].push_back(ii(u,d));
    }

    for(int i=0;i<n;i++){
        vector<ll> dist(n, INF); dist[i] = 0; // INF = 1B to avoid overflow
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>> > pq; pq.push(ii(0,i));
        while (!pq.empty()) { // main loop
        ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // this is a ve ry important check
        for (int k = 0; k < (int)AdjList[u].size(); k++) {
        ii v = AdjList[u][k]; // all outgoing edges from u
        if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second; // relax operation
        pq.push(ii(dist[v.first], v.first));
        }}} // this variant can cause duplicate items in the priority queue
        for(int j=0;j<n;j++){
            distances[i][j]=dist[j];
        }
    }


    cin >> k;

    for(int i=0;i<k;i++){
        cin >> startingTimes[i] >> customers[i] >> endTimes[i];
        customers[i]--;
    }

    cout << scheduling(0,0,endTimes[0])<<"\n";

}
