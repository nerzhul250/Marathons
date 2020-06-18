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
int militar[1005],human[1005],visited[1005][1005];
vector<ii> adjList[1005];
int main(){FIN;
	int N,W,C,H,M;
	cin >> N>>W>>C>>H>>M;
	fore(i,0,H){
		int u;
		cin >>u;
		human[u]=1;
	}
	fore(i,0,M){
		int u;
		cin >>u;
		militar[u]=1;
	}
	fore(i,0,W){
		int s,c,t;
		cin >>s >> c >>t;
		adjList[s].pb(ii(t,c));
	}
	queue<ii> q;
	fore(i,0,N){
		fore(j,i+1,N){
			if((human[i] && !human[j]) || (!human[i] && human[j])){
				q.push(ii(i,j));
				visited[i][j]=1;
			}
		}
	}
	bool possible=false;
	while(!q.empty()){
		ii s=q.front();
		q.pop();
		if(militar[s.ff] && militar[s.ss]){
			possible=true;
			break;
		}
		for(ii e1:adjList[s.ff]){
			for(ii e2:adjList[s.ss]){
				int t1=e1.ff;
				int t2=e2.ff;
				if(t1>t2)swap(t1,t2);
				if(e1.ss==e2.ss && !visited[t1][t2]){
					visited[t1][t2]=1;
					q.push(ii(t1,t2));
				}
			}
		}
	}
	if(possible){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
    return 0;
}
