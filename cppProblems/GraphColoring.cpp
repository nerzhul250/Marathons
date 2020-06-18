#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,int> ii;
int color[5005];
vector<int> adjList[5005];
vector<int> components[5005][2];
int no_component;
int dp[5005][5005];
bool bfs(int u,int c){
	color[u]=c;
	components[no_component][c].pb(u);
	queue<ii> q;
	q.push(ii(u,c));
	while(!q.empty()){
		ii node=q.front();
		q.pop();
		for(int v:adjList[node.ff]){
			if(color[v]==node.ss){
				return false;
			}else if(color[v]==-1){
				color[v]=1-node.ss;
				components[no_component][color[v]].pb(v);
				q.push(ii(v,color[v]));
			}
		}
	}
	return true;
}
int main(){FIN;
	int n,m;
	cin >>n>>m;
	int n1,n2,n3;
	cin >>n1>>n2>>n3;
	int b=n2;
	fore(i,0,m){
		int u,v;
		cin >>u>>v;
		u--;
		v--;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	bool possible=true;
	memset(color,-1,sizeof color);
	fore(i,0,n){
		if(color[i]==-1){
			if(!bfs(i,0)){
				possible=false;
				break;
			}
			no_component++;
		}
	}
	if(possible){
		dp[no_component][0]=1;
		for(int com=no_component-1;com>=0;com--){
			fore(blacks,0,b+1){
				if(blacks-components[com][0].size()>=0){
					dp[com][blacks]=dp[com+1][blacks-components[com][0].size()];
				}
				if(blacks-components[com][1].size()>=0){
					dp[com][blacks]|=dp[com+1][blacks-components[com][1].size()];
				}
			}
		}
		if(dp[0][b]){
			cout << "YES\n";
			memset(color,0,sizeof color);
			int currb=b;
			fore(com,0,no_component){
				if(currb-components[com][0].size()>=0 &&
				   dp[com+1][currb-components[com][0].size()]){
					   currb-=components[com][0].size();
					   fore(i,0,components[com][0].size()){
						   color[components[com][0][i]]=1;
					   }
				}else{
				   currb-=components[com][1].size();
				   fore(i,0,components[com][1].size()){
					   color[components[com][1][i]]=1;
				   }
				}
			}
			fore(i,0,n){
				if(color[i]==1){
					cout << "2";
				}else{
					if(n1){
						cout << "1";
						n1--;
					}else{
						cout << "3";
					}
				}
			}
			cout  <<"\n";
		}else{
			cout <<"NO\n";
		}
	}else{
		cout <<"NO\n";
	}
    return 0;
}
