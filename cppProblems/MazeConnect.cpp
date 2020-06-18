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
int table[1005][1005];
int pos[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};
int visited[1005][1005];
int cnt;
void bfs(int i,int j){
	visited[i][j]=1;
	queue<ii> q;
	q.push(ii(i,j));
	bool isOutside=false;
	while(!q.empty()){
		ii u=q.front();
		q.pop();
		fore(k,0,8){
			int ni=pos[k][0]+u.ff;
			int nj=pos[k][1]+u.ss;
			if(table[ni][nj]==1 && !visited[ni][nj]){
				if(k==4){
					if(table[ni][nj-1]!=2 ||table[ni+1][nj]!=2){						
						visited[ni][nj]=1;
						q.push(ii(ni,nj));
					}
				}else if(k==5){
					if(table[ni][nj+1]!=3 ||table[ni+1][nj]!=3){						
						visited[ni][nj]=1;
						q.push(ii(ni,nj));
					}
				}else if(k==6){
					if(table[ni-1][nj]!=2 ||table[ni][nj+1]!=2){						
						visited[ni][nj]=1;
						q.push(ii(ni,nj));
					}
				}else if(k==7){
					if(table[ni][nj-1]!=3 ||table[ni-1][nj]!=3){						
						visited[ni][nj]=1;
						q.push(ii(ni,nj));
					}
				}else{
					visited[ni][nj]=1;
					q.push(ii(ni,nj));
				}
			}else if(table[ni][nj]==0){
				if(k==4){
					if(table[ni][nj-1]!=2 ||table[ni+1][nj]!=2){						
						isOutside=true;
					}
				}else if(k==5){
					if(table[ni][nj+1]!=3 ||table[ni+1][nj]!=3){						
						isOutside=true;
					}
				}else if(k==6){
					if(table[ni-1][nj]!=2 ||table[ni][nj+1]!=2){						
						isOutside=true;
					}
				}else if(k==7){
					if(table[ni][nj-1]!=3 ||table[ni-1][nj]!=3){						
						isOutside=true;
					}
				}else{
					isOutside=true;
				}
			}
		}
	}
	if(!isOutside)cnt++;
}
int main(){FIN;
	int R,C;
	cin >> R >> C;
	fore(i,0,R){
		fore(j,0,C){
			char c;
			cin >> c;
			if(c=='.'){
				table[i+1][j+1]=1;	
			}else if(c=='\\'){
				table[i+1][j+1]=2;
			}else if(c=='/'){
				table[i+1][j+1]=3;
			}
			//cout << table[i+1][j+1];
		}
		//cout << endl;
	}
	fore(i,1,R+1){
		fore(j,1,C+1){
			if(table[i][j]==2 && table[i][j+1]==3 && table[i-1][j]==3 && table[i-1][j+1]==2){
				cnt++;
			}else if(table[i][j]==1 && !visited[i][j]){
				bfs(i,j);
			}
		}
	}
	cout << cnt << "\n";
    return 0;
}
