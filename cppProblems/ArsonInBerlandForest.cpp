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
int n,m;
vector<vector<char>> forest;
int pos[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};
int main(){FIN;
	cin >> n >> m;
	forest.pb(vector<char>());
	fore(j,0,m+2){
		forest[0].pb('.');
	}
	fore(i,0,n){
		forest.pb(vector<char>());
		forest[i+1].pb('.');
		fore(j,0,m){
			char c;
			cin >> c;
			forest[i+1].pb(c);
		}
		forest[i+1].pb('.');
	}
	forest.pb(vector<char>());
	fore(j,0,m+2){
		forest[n+1].pb('.');
	}
	n+=2;
	m+=2;
	queue<pair<int,ii>> q;
	vector<vector<int>> visited;
	fore(i,0,n){
		visited.pb(vector<int>(m,0));
	}
	fore(i,0,n){
		fore(j,0,m){
			if(forest[i][j]=='.'){
				q.push({-1,ii(i,j)});
				visited[i][j]=1;
			}
		}
	}
	vector<pair<int,ii>> events;
	int max_time=-1;
	while(!q.empty()){
		ii u=q.front().ss;
		int time=q.front().ff;
		q.pop();
		fore(k,0,8){
			int ni=pos[k][0]+u.ff;
			int nj=pos[k][1]+u.ss;
			if(ni>=0 && ni<n && nj>=0 && nj<m){
				if(forest[ni][nj]=='X' && !visited[ni][nj]){
					visited[ni][nj]=1;
					q.push({time+1,ii(ni,nj)});
					events.pb({time+1,ii(ni,nj)});
					max_time=max(max_time,time+1);
				}
			}
		}
	}
	unordered_map<int,set<ii>> mp;
	vector<ii> comparatorXD;
	fore(i,0,events.size()){
		comparatorXD.pb(events[i].ss);
		mp[events[i].ff].insert(events[i].ss);
	}
	//sort(ALL(comparatorXD));
	int l=0;
	int r=max_time;
	int ans=-1;
	while(l<=r){
		int mid=(l+r)/2;
		bool possible=true;
		fore(i,0,n){
			fore(j,0,m){
				visited[i][j]=0;
			}
		}
		queue<pair<int,ii>> q;
		//vector<ii> comparatorxd;
		int cnt=0;
		for(int i=max_time;i>=mid;i--){
			for(ii e:mp[i]){
				if(i==mid){
					q.push({i,e});
				}
				cnt++;
				//comparatorxd.pb(e);
				visited[e.ff][e.ss]=1;
			}
		}
		while(!q.empty()){
			ii u=q.front().ss;
			int time=q.front().ff;
			q.pop();
			if(time==0)continue;
			fore(k,0,8){
				int ni=pos[k][0]+u.ff;
				int nj=pos[k][1]+u.ss;
				if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj]){
					visited[ni][nj]=1;
					cnt++;
					//comparatorxd.pb(ii(ni,nj));
					q.push({time-1,ii(ni,nj)});
				}
			}
		}
		if(cnt!=comparatorXD.size()){
			possible=false;
		}
		if(possible){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	char table[n][m];
	fore(i,0,n){
		fore(j,0,m){
			table[i][j]='.';
		}
	}
	fore(i,ans,max_time+1){
		for(ii e:mp[i]){
			table[e.ff][e.ss]='X';
		}
	}
	cout << ans<<"\n";
	fore(i,1,n-1){
		fore(j,1,m-1){
			cout << table[i][j];
		}
		cout << "\n";
	}
    return 0;
}
