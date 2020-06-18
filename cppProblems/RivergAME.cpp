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
char table[15][15];
int wet_zones;
int wet_zone[15][15];
int pos[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int game_num;
vector<int> games[105];
map<ii,int> mp2ind;
int dp[(1<<24)+5];
int N;
int get_grundy(int gm,int mask){
	if(dp[mask]!=-1)return dp[mask];
	if(mask==0)return 0;
	set<int> grundies;
	fore(i,0,games[gm].size()){
		if((1<<i)&mask){
			int x=games[gm][i]/N;
			int y=games[gm][i]%N;
			int nmask=mask^(1<<i);
			fore(k,0,4){
				int nx=pos[k][0]+x;
				int ny=pos[k][1]+y;
				if(nx>=0 && nx<N && ny>=0 && ny<N){
					if(table[nx][ny]=='.' && wet_zone[x][y]==wet_zone[nx][ny] &&
						((1<<mp2ind[ii(nx,ny)])&nmask)){
						nmask^=(1<<mp2ind[ii(nx,ny)]);
					}
				} 
			}
			grundies.insert(get_grundy(gm,nmask));
		}
	}
	int ngrundy=0;
	while(grundies.count(ngrundy))ngrundy++;
	return dp[mask]=ngrundy;
}
void bfs_water(int x,int y){
	queue<ii> q;
	wet_zone[x][y]=wet_zones;
	q.push(ii(x,y));
	while(!q.empty()){
		ii u=q.front();
		q.pop();
		fore(k,0,4){
			int nx=u.ff+pos[k][0];
			int ny=u.ss+pos[k][1];
			if(nx>=0 && nx<N && ny>=0 && ny<N && wet_zone[nx][ny]==-1){
				if(table[nx][ny]=='*'){
					wet_zone[nx][ny]=wet_zones;
					q.push(ii(nx,ny));
				}else if(table[nx][ny]=='.'){//check
					wet_zone[nx][ny]=wet_zones;
				}
			}
		}
	}
	wet_zones++;
	return;
}
void bfs_shore(int x,int y){
	queue<ii> q;
	mp2ind[ii(x,y)]=games[game_num].size();
	games[game_num].pb(x*N+y);
	q.push(ii(x,y));
	while(!q.empty()){
		ii u=q.front();
		q.pop();
		fore(k,0,4){
			int nx=u.ff+pos[k][0];
			int ny=u.ss+pos[k][1];
			if(nx>=0 && nx<N && ny>=0 && ny<N){
				if(table[nx][ny]=='.' && wet_zone[u.ff][u.ss]==wet_zone[nx][ny]){
					if(mp2ind.count(ii(nx,ny))==0){
						mp2ind[ii(nx,ny)]=games[game_num].size();
						games[game_num].pb(nx*N+ny);
						q.push(ii(nx,ny));
					}
				}
			}
		}
	}
	game_num++;
	return;
}
int main(){FIN;
	cin >>N;
	fore(i,0,N){
		fore(j,0,N){
			cin >> table[i][j];
		}
	}
	memset(wet_zone,-1,sizeof wet_zone);
	fore(i,0,N){
		fore(j,0,N){
			if(wet_zone[i][j]==-1 && table[i][j]=='*'){
				bfs_water(i,j);
			}
		}
	}
	fore(i,0,N){
		fore(j,0,N){
			if(wet_zone[i][j]!=-1 && table[i][j]=='.' && mp2ind.count(ii(i,j))==0){
				bfs_shore(i,j);
			}
		}
	}
	int ans=0;
	fore(i,0,game_num){
		memset(dp,-1,sizeof dp);
		ans^=get_grundy(i,(1<<(games[i].size()))-1);
	}
	if(ans==0){
		cout << "Second player will win\n";
	}else{
		cout << "First player will win\n";
	}
    return 0;
}
