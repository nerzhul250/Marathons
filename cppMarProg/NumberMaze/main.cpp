#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF=100000000;

int N,M,arr[1005][1005];

vii AdjList[1000005];

void setUpNeighbors(int n,int i,int j){
    if(i>=0 && j>=0 && i<N && j<M){
        AdjList[n].push_back(ii(i*M+j,arr[i][j]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        cin >> N >> M;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                AdjList[i*M+j].clear();
                cin >> arr[i][j];
            }
        }
        AdjList[N*M].clear();

        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                setUpNeighbors(i*M+j,i+1,j);
                setUpNeighbors(i*M+j,i-1,j);
                setUpNeighbors(i*M+j,i,j+1);
                setUpNeighbors(i*M+j,i,j-1);
            }
        }

        setUpNeighbors(N*M,0,0);

        int V=N*M+1;
        int s=N*M;
        vi dist(V, INF); dist[s] = 0; // INF = 1B to avoid overflow
        priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

        while (!pq.empty()) { // main loop
        ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
        int d = front.first, u = front.second;
        if (d > dist[u]) continue; // this is a very important check
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j]; // all outgoing edges from u
        if (dist[u] + v.second < dist[v.first]) {
        dist[v.first] = dist[u] + v.second; // relax operation
        pq.push(ii(dist[v.first], v.first));
        } } } // this variant can cause duplicate items in the priority queue

        cout << dist[N*M-1]<<"\n";
    }

    return 0;
}
