#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;


const ll INF=1e15;

int N,M,fathers[100005];

vii AdjList[100005];

void printPath(int u){
    if(u!=0){printPath(fathers[u]);}
    if(u==N-1){
        cout << N << "\n";
    }else{
        cout << u+1 << " ";
    }
}

int main()
{
    cin >> N >> M;
    for(int j=0;j<M;j++){
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        AdjList[a].push_back(ii(b,w));
        AdjList[b].push_back(ii(a,w));
    }
    int V=N;
    int s=0;
    vll dist(V, INF); dist[s] = 0; // INF = 1B to avoid overflow
    priority_queue< ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

    while (!pq.empty()) { // main loop
    ii front = pq.top(); pq.pop(); // greedy: get shortest unvisited vertex
    int d = front.first, u = front.second;
    if (d > dist[u]) continue; // this is a very important check
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j]; // all outgoing edges from u
    if (dist[u] + v.second < dist[v.first]) {
    dist[v.first] = dist[u] + v.second; // relax operation
    fathers[v.first]=u;
    pq.push(ii(dist[v.first], v.first));
    } } } // this variant can cause duplicate items in the priority queue
    if(dist[N-1]==INF){
        cout << "-1\n";
    }else{
        printPath(N-1);
    }
    return 0;
}
