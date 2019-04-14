#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;
const int MAXV=2060, MAXC=31,MAXN=35,INF=1e9;
int costs[MAXC],res[MAXV][MAXV];
char theMap[MAXN][MAXN],aux;
vector<int> adjList[MAXV],p;
int n,m,c,mf,f,u,v;

int source(){
    return 2*(n+2)*(m+2)+1;
}
int sink(){
    return 2*(n+2)*(m+2)+2;
}
int Vin(int i,int j){
    return j+1+i*(n+2);
}
int Vout(int i,int j){
    return j+1+i*(n+2)+(m+2)*(n+2);
}

void augment(int node, int minEdge){
    if(node==source()){
        f=minEdge; return;
    }else if(p[node]!=-1){
        augment(p[node],min(minEdge,res[p[node]][node]));
        res[p[node]][node]-=f; res[node][p[node]]+=f;
    }
}

void setUp(int i,int j,int i1, int j1){
     res[Vout(i,j)][Vin(i1,j1)]=INF;
     adjList[Vout(i,j)].push_back(Vin(i1,j1));
     adjList[Vin(i1,j1)].push_back(Vout(i,j));
     if(i>0 && i<m+1 && j>0 && j<n+1 && theMap[i-1][j-1]>='a'&&theMap[i-1][j-1]<='z'){
         res[Vin(i,j)][Vout(i,j)]=costs[theMap[i-1][j-1]-'a'];
     }else{
         res[Vin(i,j)][Vout(i,j)]=INF;
     }
     adjList[Vin(i,j)].push_back(Vout(i,j));
     adjList[Vout(i,j)].push_back(Vin(i,j));
}

bool check(int i,int j){
    return i>=0 && i<m+2 && j>=0 && j<n+2;
}

int main()
{
    scanf("%d %d %d",&n,&m,&c);
    scanf("%c",&aux);
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf("%c",&theMap[i][j]);
        }
        scanf("%c",&aux);
    }
    for (int i=0;i<c;i++){
        scanf("%d",&costs[i]);
    }
    for (int i=0;i<m+2;i++){
        for (int j=0;j<n+2;j++){
            if(i==0 || j==0 || i==m+1 || j==n+1){
                res[Vout(i,j)][source()]=INF;
                adjList[Vout(i,j)].push_back(source());
                adjList[source()].push_back(Vout(i,j));

                res[source()][Vin(i,j)]=INF;
                adjList[source()].push_back(Vin(i,j));
                adjList[Vin(i,j)].push_back(source());
            }
            if(i>0 && i<m+1 && j>0 && j<n+1 && theMap[i-1][j-1]=='B'){
                res[Vout(i,j)][sink()]=INF;
                adjList[Vout(i,j)].push_back(sink());
                adjList[sink()].push_back(Vout(i,j));

                res[sink()][Vin(i,j)]=INF;
                adjList[sink()].push_back(Vin(i,j));
                adjList[Vin(i,j)].push_back(sink());
            }
            if(check(i+1,j))setUp(i,j,i+1,j);
            if(check(i-1,j))setUp(i,j,i-1,j);
            if(check(i,j+1))setUp(i,j,i,j+1);
            if(check(i,j-1))setUp(i,j,i,j-1);
        }
    }

    mf=0;
    while(1){
        f=0;
        bitset<MAXV> vis; vis[source()]=true;
        queue<int> q; q.push(source());
        p.assign(MAXV,-1);
        while(!q.empty()){
            u=q.front(); q.pop();
            if(u==sink())break;
            for (int j=0;j<(int)adjList[u].size();j++){
                v=adjList[u][j];
                if(res[u][v]>0 && !vis[v]){
                    vis[v]=true, q.push(v); p[v]=u;
                }
            }
        }
        augment(sink(),INF);
        if(f==0)break;
        mf+=f;
    }
    if(mf>=INF){
        printf("-1\n");
    }else{
        printf("%d\n",mf);
    }

    return 0;
}
