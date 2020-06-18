#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int costs[205][205];
vector<int> adjList[205];
int cliqueSz;
int currClique;
vector<int> cliques[205];
int n,m;
int visited[205];
void dfs(int u){
	visited[u]=1;
	cliques[cliqueSz].pb(u);
	for(int v:adjList[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}
int dp[(1<<22)+5];
int go(int mask){
	if(mask==((1<<cliques[currClique].size())-1))return 0;
	int &r=dp[mask];
	if(r!=-1)return r;
	r=1e8;
	int index=0;
	while((1<<index)&mask)index++;
	fore(i,index+1,cliques[currClique].size()){
		if(((1<<i)&mask)==0){
			r=min(r,costs[cliques[currClique][index]][cliques[currClique][i]]+go(mask|(1<<index)|(1<<i)));
		}
	}
	return r;
}
int main(){FIN;
	cin >> n >>m;
	fore(i,0,m){
		int p,q,c;
		cin >> p >> q >> c;
		p--;
		q--;
		costs[p][q]=c;
		costs[q][p]=c;
		adjList[p].pb(q);
		adjList[q].pb(p);
	}
	bool possible=true;
	fore(i,0,n){
		if(!visited[i]){
			dfs(i);
			possible&=((cliques[cliqueSz].size()%2)==0);
			cliqueSz++;
		}
	}
	if(possible){
		int cost=0;
		fore(i,0,cliqueSz){
			currClique=i;
			fore(msk,0,(1<<cliques[currClique].size()))dp[msk]=-1;
			cost+=go(0);
		}
		cout << cost<<"\n";
	}else{
		cout <<"impossible\n";
	}
    return 0;
}
