#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

double EPS = 1e-9;

const int MAXR=35,MAXC=35,INF=1e9,MAXV=910;
int sufLight[MAXR][MAXC];
int B,H,R,C;
double accLight[MAXR][MAXC],srcBulbs[MAXR][MAXC];

int res[MAXV][MAXV];
vector<int> adjList[MAXV],p;
int u,v,mf,f;


void augment(int node, int minEdge){
    if(node==0){
        f=minEdge; return;
    }else if(p[node]!=-1){
        augment(p[node],min(minEdge,res[p[node]][node]));
        res[p[node]][node]-=f; res[node][p[node]]+=f;
    }
}

void setUp(int r,int c,int r1, int c1){
    adjList[c+1+r*C].push_back(c1+1+r1*C);
    if(sufLight[r][c]==1 && sufLight[r1][c1]==1){
        res[c+1+r*C][c1+1+r1*C]=43;
    }else{
        res[c+1+r*C][c1+1+r1*C]=11;
    }
}

bool check(int r,int c){
    return r>=0 && r<R && c>=0 && c<C;
}

double computeLight(double s,double x,double y,double z){
    return s/(x*x+y*y+z*z);
}

int main(){

    char dig;
    scanf("%d",&B);
    scanf("%d",&H);
    scanf("%d %d",&R,&C);
    scanf("%c",&dig);


    for (int r=0;r<R;r++){
        for (int c=0;c<C;c++){
            scanf("%c",&dig);
            srcBulbs[r][c]=dig-'0';
        }
        scanf("%c",&dig);
    }

    for (int r=0;r<R;r++){
        for (int c=0;c<C;c++){
            for (int r1=0;r1<R;r1++){
                for (int c1=0;c1<C;c1++){
                    accLight[r1][c1]+=computeLight(srcBulbs[r][c],r-r1,c-c1,H);
                }
            }
        }
    }

    for (int r=0;r<R;r++){
        for (int c=0;c<C;c++){
            if(accLight[r][c]>=B+EPS)sufLight[r][c]=1;
        }
    }

    for (int r=0;r<R;r++){
        for (int c=0;c<C;c++){
            if(r==0 || r==R-1 || c==0 || c==C-1){
                adjList[c+1+r*C].push_back(0);
                adjList[0].push_back(c+1+r*C);
                res[c+1+r*C][0]=INF;
                res[0][c+1+r*C]=INF;
            }else if(sufLight[r][c]==0){
                adjList[c+1+r*C].push_back(R*C+1);
                adjList[R*C+1].push_back(c+1+r*C);
                res[c+1+r*C][R*C+1]=INF;
                res[R*C+1][c+1+r*C]=INF;
            }
            if(check(r+1,c))setUp(r,c,r+1,c);
            if(check(r-1,c))setUp(r,c,r-1,c);
            if(check(r,c+1))setUp(r,c,r,c+1);
            if(check(r,c-1))setUp(r,c,r,c-1);
        }
    }

    mf=0;
    while(1){
        f=0;
        bitset<MAXV> vis; vis[0]=true;
        queue<int> q; q.push(0);
        p.assign(MAXV,-1);
        while(!q.empty()){
            u=q.front(); q.pop();
            if(u==R*C+1)break;
            for (int j=0;j<(int)adjList[u].size();j++){
                v=adjList[u][j];
                if(res[u][v]>0 && !vis[v]){
                    vis[v]=true, q.push(v); p[v]=u;
                }
            }
        }
        augment(R*C+1,INF);
        if(f==0)break;
        mf+=f;
    }

    printf("%d\n",mf);

    return 0;
}
