#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long int ll;
typedef ll tf;
const tf INF=1e18;
struct MCF{
	int n;
	vector<tf> prio,curflow,prevedge,prevnode,pot;
	priority_queue<ll,vector<ll>,greater<ll>> q;
	struct edge{int to, rev; tf f, cap, cost;};
	vector<vector<edge>> g;
	MCF(int n):n(n),prio(n),curflow(n),prevedge(n),prevnode(n),pot(n),g(n){}
	void add_edge(int s, int t, tf cap, tf cost) {
		g[s].pb((edge){t,SZ(g[t]),0,cap,cost});
		g[t].pb((edge){s,SZ(g[s])-1,0,0,-cost});
	}
	pair<tf,tf> get_flow(int s, int t) {
		tf flow=0, flowcost=0;
		while(1){
			q.push(s);
			fill(ALL(prio),INF); 
			prio[s]=0; curflow[s]=INF;
			while(!q.empty()) {
				ll cur=q.top();
				int d=cur>>32, u=cur;
				q.pop();
				if(d!=prio[u]) continue;
				for(int i=0; i<SZ(g[u]); ++i) {
					edge &e=g[u][i];
					int v=e.to;
					if(e.cap<=e.f) continue;
					tf nprio=prio[u]+e.cost+pot[u]-pot[v];
					if(prio[v]>nprio) {
						prio[v]=nprio;
						q.push(((ll)nprio<<32)+v);
						prevnode[v]=u; prevedge[v]=i;
						curflow[v]=min(curflow[u], e.cap-e.f);
					}
				}
			}
			if(prio[t]==INF) break;
			fore(i,0,n) pot[i]+=prio[i];
			tf df=min(curflow[t], INF-flow);
			flow+=df;
			for(int v=t; v!=s; v=prevnode[v]) {
				edge &e=g[prevnode[v]][prevedge[v]];
				e.f+=df; g[v][e.rev].f-=df;
				flowcost+=df*e.cost;
			}
		}
		return {flow,flowcost};
	}
};

char theWall[10][1005];
int main(){FIN;
	int n;
	while(cin >> n){
		if(n==0)break;
		MCF mcf(10*n+2);
		int s=10*n,t=10*n+1;
		fore(i,0,5)fore(j,0,n)cin >> theWall[i][j];
		fore(i,0,5){
			fore(j,0,n){
				int v=i*n+j,vr=i*n+j+1,vd=(i+1)*n+j;
				if(j==0 && theWall[i][j]=='@'){
					mcf.add_edge(s,v<<1,INF,0);
					mcf.add_edge(v<<1,(v<<1)|1,1,0);
				}else{
					mcf.add_edge(v<<1,(v<<1)|1,1,theWall[i][j]-'0');
				}
				if(j==n-1){
					mcf.add_edge((v<<1)|1,t,INF,0);
				}
				if(j+1<n){
					mcf.add_edge((v<<1)|1,vr<<1,INF,0);
					mcf.add_edge((vr<<1)|1,v<<1,INF,0);
				}
				if(i+1<5){
					mcf.add_edge((v<<1)|1,vd<<1,INF,0);
					mcf.add_edge((vd<<1)|1,v<<1,INF,0);
				}
			}
		}
		cout << mcf.get_flow(s,t).ss<<"\n";
	}
    return 0;
}
