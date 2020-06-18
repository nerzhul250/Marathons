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
int board[1005][1005];
int visited[1005][1005];
int pos[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
int rows[1005],columns[1005];
void bfs(int i,int j){
	visited[i][j]=1;
	queue<ii> q;
	q.push(ii(i,j));
	while(!q.empty()){
		ii u=q.front();
		q.pop();
		fore(k,0,4){
			int ni=u.ff+pos[k][0],nj=u.ss+pos[k][1];
			if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj] && board[ni][nj]==1){
				visited[ni][nj]=1;
				q.push(ii(ni,nj));
			}
		}		
	}
	return ;
}
int main(){FIN;
	cin >>n>>m;
	int sum=0;
	fore(i,0,n){
		fore(j,0,m){
			char c;
			cin >>c;
			if(c=='#'){
				board[i][j]=1;
				sum++;
			}
		}
	}
	bool possible=true;
	fore(i,0,n){
		int flag=-1;
		fore(j,0,m){
			if(board[i][j]==1){
				if(flag==-1){
					flag=0;
				}else if(flag==1){
					possible=false;
				}
			}else{
				if(flag==0){
					flag=1;
				}
			}
		}
		if(flag>-1){
			rows[i]=1;
		}
		if(!possible)break;
	}
	fore(j,0,m){
		int flag=-1;
		fore(i,0,n){
			if(board[i][j]==1){
				if(flag==-1){
					flag=0;
				}else if(flag==1){
					possible=false;
				}
			}else{
				if(flag==0){
					flag=1;
				}
			}
		}
		if(flag>-1){
			columns[j]=1;
		}
		if(!possible)break;
	}
	
	fore(i,0,n){
		if(rows[i]==0){
			fore(j,0,m){
				if(columns[j]==0 || columns[j]==2){
					columns[j]=2;
					rows[i]=2;
				}
			}
		}
		if(rows[i]==0)possible=false;
	}
	fore(j,0,m){
		if(columns[j]==0){
			fore(i,0,n){
				if(rows[i]==0 || rows[i]==2){
					columns[j]=2;
					rows[i]=2;
				}
			}
		}
		if(columns[j]==0)possible=false;
	}
	if(possible){		
		int cnt=0;
		fore(i,0,n){
			fore(j,0,m){
				if(!visited[i][j] && board[i][j]==1){
					bfs(i,j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}else{
		cout  << "-1\n";
	}
    return 0;
}
