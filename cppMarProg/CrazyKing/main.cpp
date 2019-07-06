#include <iostream>
#include <queue>

using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;

const int INF =1e9;

int M,N;
string line;
char board[105][105];
vector<ii> AdjList[10005];

void setUpInvalidTerrain(int i,int j){
    if(i>=0 && i<M && j>=0 && j<N && board[i][j]=='.'){
        board[i][j]='*';
    }
}

void setUpNeighbors(int node, int i,int j){
    if(i>=0 && i<M && j>=0 && j<N && board[i][j]!='*' &&board[i][j]!='Z'){
        AdjList[node].push_back(ii(N*i+j,-1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        cin >> M >> N;
        for(int i=0;i<M;i++){
            cin >> line;
            for(int j=0;j<N;j++){
                board[i][j]=line[j];
                AdjList[N*i+j].clear();
            }
        }
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]=='Z'){
                    setUpInvalidTerrain(i+2,j-1);
                    setUpInvalidTerrain(i+2,j+1);
                    setUpInvalidTerrain(i+1,j-2);
                    setUpInvalidTerrain(i+1,j+2);
                    setUpInvalidTerrain(i-1,j+2);
                    setUpInvalidTerrain(i-1,j-2);
                    setUpInvalidTerrain(i-2,j-1);
                    setUpInvalidTerrain(i-2,j+1);
                }
            }
        }

        int s=0;
        int destination=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                if(board[i][j]=='A')s=N*i+j;
                if(board[i][j]=='B')destination=N*i+j;
                if(board[i][j]!='*' &&board[i][j]!='Z'){
                    setUpNeighbors(N*i+j,i+1,j);
                    setUpNeighbors(N*i+j,i-1,j);
                    setUpNeighbors(N*i+j,i,j+1);
                    setUpNeighbors(N*i+j,i,j-1);
                    setUpNeighbors(N*i+j,i+1,j+1);
                    setUpNeighbors(N*i+j,i-1,j+1);
                    setUpNeighbors(N*i+j,i-1,j-1);
                    setUpNeighbors(N*i+j,i+1,j-1);
                }
            }
        }



        vi d(10005, INF); d[s] = 0; // distance from source s to s is 0
        queue<int> q; q.push(s); // start from source
        while (!q.empty()) {
        int u = q.front(); q.pop(); // queue: layer by layer!
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j]; // for each neighbor of u
        if (d[v.first] == INF) { // if v.first is unvisited + reachable
        d[v.first] = d[u] + 1; // make d[v.first] != INF to flag it
        q.push(v.first); // enqueue v.first for the next iteration
        } } }

        if(d[destination]==INF){
            cout << "King Peter, you can't go now!\n";
        }else{
            cout << "Minimal possible length of a trip is "<<d[destination]<<"\n";
        }
    }
    return 0;
}
