#include<bits/stdc++.h>
#define INF 1000000100

using namespace std;

const int MAX_N=100005;
int R[MAX_N],dp[MAX_N],E[MAX_N],N,M,tree[MAX_N*4+5],C[MAX_N];
vector<int> stores[MAX_N];
int findMaxLevel(int str,int curl){
    if(str>=E[N]-E[curl-1])return N;
    if(str<E[curl]-E[curl-1])return -1;
    int i=curl,j=N,mid;
    bool found=false;
    while(i<=j && !found){
        mid=(i+j)/2;
        if(E[mid]-E[curl-1]==str){
            found=true;
        }else if(str<E[mid]-E[curl-1]){
            j=mid-1;
        }else{
            i=mid+1;
        }
    }
    while(str<E[mid]-E[curl-1])mid--;
    return mid;
}
void init(int node, int a, int b ){
   if(a==b){
      tree[node]=0;
      return;
   }
   init(2*node+1, a, (a+b)/2 );
   init(2*node+2, (a+b)/2+1, b );
   tree[node]=min( tree[2*node+1], tree[2*node+2] );
}

int query(int node, int a, int b, int p, int q){
   if(q<a || b<p)return INF;
   if(a>=p && b<=q) return tree[node];
   int v1=2*node+1;
   int v2=2*node+2;
   return min( query(v1, a, (a+b)/2, p, q), query(v2, (a+b)/2+1, b, p, q ) );
}

void update(int node,int a,int b,int p,int val){
   if(b<p || p<a)return;
   if(a==b){
      tree[node]=val;
      return;
   }
   update(2*node+1, a, (a+b)/2, p, val);
   update(2*node+2, (a+b)/2+1, b, p, val);
   tree[node] =min( tree[2*node+1], tree[2*node+2] );
}

int main()
{
    int l,s,minimo;
    while(scanf("%d %d",&N,&M)==2){
        for (int i=1;i<=N;i++){scanf("%d",&E[i]);E[i]+=E[i-1];stores[i].clear();}
        for (int i=0;i<M;i++){
            scanf("%d %d %d",&l,&s,&C[i]);
            R[i]=findMaxLevel(s,l);
            if(R[i]!=-l)stores[l].push_back(i);
        }
        init(0,1,N+1);
        dp[N+1]=0;
        update(0,1,N+1,N+1,dp[N+1]);
        for (int i=N;i>=1;i--){
            dp[i]=INF;
            for(int j=0;j<stores[i].size();j++){
                int p=stores[i][j];
                minimo=query(0,1,N+1,i+1,R[p]+1);
                dp[i]=min(dp[i],minimo+C[p]);
            }
            update(0,1,N+1,i,dp[i]);
        }
        if(dp[1]>=INF){
            printf("%d\n",-1);
        }else{
            printf("%d\n",dp[1]);
        }
    }
    return 0;
}
