#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int visits[85][85][85];
int dp[85][85][85],n;
vector<int> adjList [85];

void dfs(int s,int r,vector<int> & pos,int visitados[85]){
   // cout << s<< endl;
    pos.push_back(s);
    visitados[s]=1;
    for(int i=0;i<adjList[s].size();i++){
        if(adjList[s][i]!=r && visitados[adjList[s][i]]==0){
            dfs(adjList[s][i],r,pos,visitados);
        }
    }
}

int minMoves(int s, int r1, int r2){
    visits[s][r1][r2]=1;
    if(dp[s][r1][r2]!=0)return dp[s][r1][r2];
    vector<int> posMovSqr;
    int visitados[85];
    memset(visitados,0,sizeof visitados);
    //cout << "init " << endl;
    dfs(s,r2,posMovSqr,visitados);
    //cout << "fin " << endl;
    if(posMovSqr.size()==1)return 1;
    int minimum=1e9;
    for(int i=0;i<posMovSqr.size();i++){
        for(int j=1;j<=n;j++){
            if(posMovSqr[i]!=j && visits[posMovSqr[i]][j][r2]==0 && j!=r2){
               // cout << s << " " << r1 << " " << r2 << endl;
                minimum=min(minimum,minMoves(posMovSqr[i],j,r2)+1);
            }
        }
    }
    memset(visitados,0,sizeof visitados);
    posMovSqr.clear();
   // cout << "init " << endl;
    dfs(s,r1,posMovSqr,visitados);
    //cout << "fin" << endl;
    if(posMovSqr.size()==1)return 1;
    for(int i=0;i<posMovSqr.size();i++){
        for(int j=1;j<=n;j++){
            if(posMovSqr[i]!=j && visits[posMovSqr[i]][r1][j]==0 && j!=r1){
                minimum=min(minimum,minMoves(posMovSqr[i],r1,j)+1);
            }
        }
    }
    visits[s][r1][r2]=0;
    return dp[s][r1][r2]=minimum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int r,h,m;
    cin >> r >> h >> m;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin >>a >>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    cout << minMoves(r,h,m) << "\n";
    return 0;
}
