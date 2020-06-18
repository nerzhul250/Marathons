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
typedef long long int ll;
char table[1005][1005];
int F[1005][1005];
int pos[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
int visited[1005][1005];
bool isWave(int i,int j){
	fore(k,0,4){
		int ni=pos[k][0]+i,nj=pos[k][1]+j;
		if(ni>=0 && ni<n && nj>=0 && nj<m && table[i][j]==table[ni][nj]){
			return true;
		}
	}
	return false;
}
int main(){FIN;
	int T;
	cin >> n >> m >> T;
	fore(i,0,n){
		fore(j,0,m){
			cin >> table[i][j];
		}
	}
	
	queue<ii> q;
	fore(i,0,n){
		fore(j,0,m){
			F[i][j]=1e8;
			if(isWave(i,j)){
				visited[i][j]=1;
				F[i][j]=0;
				q.push(ii(i,j));
			}
		}
	}
	while(!q.empty()){
		ii now=q.front();
		q.pop();
		int i=now.ff;
		int j=now.ss;
		fore(k,0,4){
			int ni=pos[k][0]+i,nj=pos[k][1]+j;
			if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj]){
				F[ni][nj]=F[i][j]+1;
				visited[ni][nj]=1;
				q.push(ii(ni,nj));
			}
		}
	}
	fore(t,0,T){
		int i,j;
		ll p;
		cin >> i >> j >> p;
		i--;
		j--;
		if(F[i][j]==0){
			ll rem=p-F[i][j];
			if(rem%2==0){
				cout << table[i][j]<<"\n";
			}else{
				int ans=table[i][j]-'0';
				cout << 1-ans<<"\n";
			}
		}else if(F[i][j]==1e8){
			cout << table[i][j]<<"\n";
		}else{
			if(p<=F[i][j]){
				cout << table[i][j]<<"\n";	
			}else{
				ll rem=p-F[i][j];
				if(rem%2==0){
					cout << table[i][j]<<"\n";
				}else{
					int ans=table[i][j]-'0';
					cout << 1-ans<<"\n";
				}
			}
		}
	}
    return 0;
}

