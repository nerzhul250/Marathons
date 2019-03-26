#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

const int MAXV=55;
const int INF=1e9;

vector<int> adjList[MAXV],p;
int res[MAXV][MAXV], x[505],y[505];
int n,m,u,v,c,mf,f;

void augment(int node, int minEdge){
    if(node==1){
        f=minEdge; return;
    }else if(p[node]!=-1){
        augment(p[node],min(minEdge,res[p[node]][node]));
        res[p[node]][node]-=f; res[node][p[node]]+=f;
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    while(!(n==0 &&m==0)){
        for (int i=0;i<MAXV;i++){
                adjList[i].clear();
            for (int j=0;j<MAXV;j++){
                res[i][j]=0;
            }
        }
        for (int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&c);
            x[i]=u;y[i]=v;
            res[u][v]=c;
            res[v][u]=c;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        mf=0;
        while(1){
            f=0;
            bitset<MAXV> vis; vis[1]=true;
            queue<int> q; q.push(1);
            p.assign(MAXV,-1);
            while(!q.empty()){
                u=q.front(); q.pop();
                if(u==2)break;
                for (int j=0;j<(int)adjList[u].size();j++){
                    v=adjList[u][j];
                    if(res[u][v]>0 && !vis[v]){
                        vis[v]=true, q.push(v); p[v]=u;
                    }
                }
            }
            augment(2,INF);
            if(f==0)break;
            mf+=f;
        }

        bitset<MAXV> vis; vis[1]=true;
        queue<int> q; q.push(1);
        while(!q.empty()){
            u=q.front(); q.pop();
            for (int j=0;j<(int)adjList[u].size();j++){
                v=adjList[u][j];
                if(res[u][v]>0 && !vis[v]){
                    vis[v]=true, q.push(v);
                }
            }
        }

        for (int i=0;i<m;i++){
            if((vis[x[i]]&&!vis[y[i]])||(!vis[x[i]]&&vis[y[i]]))printf("%d %d\n",x[i],y[i]);
        }
        scanf("%d %d",&n,&m);
        if(!(n==0 && m==0))printf("\n");
    }
}
