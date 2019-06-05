#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <functional>

//LOWEST COMMON ancestor and MAX EDGE BETWEEN TWO NODES IN A TREE
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;

struct Edge
{
    int u;
    int c;
    int t;
};

/*vector<Edge> AdjList [100006];
vi taken; // global boolean flag to avoid cycle

int N,R,Q,A,B,C,u,w;

void process(int vtx) { // so, we use -ve sign to reverse the sort order
    taken[vtx] = 1;
    for (int j = 0; j < (int)AdjList[vtx].size(); j++) {
        ii v = AdjList[vtx][j].first;
        if (!taken[v.first]) pq.push(ii(ii(ii(-v.second,j),AdjList[vtx][j].second),vtx));
} }*/

int main()
{
    auto cmp = [](Edge &a, Edge &b) { return a.c>b.c;};
    priority_queue<Edge,vector<Edge>, decltype(cmp)> pq(cmp);

    cin >> N >> R;
    for(int i=0;i<R;i++){
        cin >> A >> B >> C;
        AdjList[A-1].push_back(ii(ii(B-1,C),0));
        AdjList[B-1].push_back(ii(ii(A-1,C),0));
    }
    taken.assign(N, 0); // no vertex is taken at the beginning
    process(0); // take vertex 0 and process all edges incident to vertex 0
    mst_cost = 0;
    while (!pq.empty()) { // repeat until V vertices (E=V-1 edges) are taken
        ii front = pq.top(); pq.pop();
        u = -front.first.first.second, w = -front.first.first.first; // negate the id and weight again
        if (!taken[u]){
            mst_cost += w, process(u); // take u, process all edges incident to u

        } // we have not connected this vertex yet
    } // each edge is in pq only once!
    printf("MST cost = %d (Prim’s)\n", mst_cost);



    cin >> Q;
    for(int i=0;i<Q;i++){

    }
    return 0;
}
