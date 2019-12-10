#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef vector<int> vi;

vi adjList[200005];
vector<pair<int,bool>> intervals;
int visited[200005];

void bfs(int source){
	queue<int> q;
	int minimo=source;
	int maximo=source;
	q.push(source);
	visited[source]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v : adjList[u]){
			if(!visited[v]){
				visited[v]=1;
				minimo=min(v,minimo);
				maximo=max(v,maximo);
				q.push(v);
			}
		}
	}
	intervals.pb({minimo,false});
	intervals.pb({maximo,true});
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin >> n>>m;
    fore(i,0,m){
		int u,v;
		cin >> u>>v;
		u--;
		v--;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	fore(i,0,n){
		if(!visited[i]){
			bfs(i);
		}
	}
	sort(intervals.begin(),intervals.end());
	int sum=0;
	int cnt=0;
	int ans=0;
	for(auto p : intervals){
		//cout << p.ff << " "<<p.ss<<"\n";
		if(p.ss){
			sum--;
			if(sum==0){
				ans+=cnt-1;
				cnt=0;
			}
		}else{
			sum++;
			cnt++;
		}
	}
	cout << ans << "\n";
}
