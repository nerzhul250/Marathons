#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef pair<int, int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define INF 1000000000
vector<ii> AdjList [5005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    int orgT=T;
    while(T--){
		int N,R;
		cin >> N >> R;
		fore(i,0,N)AdjList[i].clear();
		fore(i,0,R){
			int u,v,w;
			cin >> u >> v >> w;
			u--;
			v--;
			AdjList[u].pb({v,w});
			AdjList[v].pb({u,w});
		}
		int dis[2][N+5];
		fore(i,0,N){
			dis[0][i]=INF;
			dis[1][i]=INF;
		}
		dis[0][0]=0;
		priority_queue< iii, vector<iii>, greater<iii> > pq; pq.push(iii(0,ii(0,0)));
		//t,d,u
		while (!pq.empty()) {
			iii front = pq.top(); pq.pop();
			int t = front.ff, d = front.ss.ff, u=front.ss.ss;
			cout << t <<" "<<d << " "<<u<<endl;
			if(d>dis[t][u])continue;
			for (int j = 0; j < (int)AdjList[u].size(); j++) {
			  ii v = AdjList[u][j];
			  int alt=v.ss+d;
			  if(alt<dis[0][v.ff]){
				  dis[1][v.ff]=dis[0][v.ff];
				  pq.push(iii(1,ii(dis[1][v.ff],v.ff)));
				  dis[0][v.ff]=alt;
				  pq.push(iii(0,ii(dis[0][v.ff],v.ff)));
			  }else if(alt>dis[0][v.ff] && alt<dis[1][v.ff]){
				  dis[1][v.ff]=alt;
				  pq.push(iii(1,ii(dis[1][v.ff],v.ff)));
			  }
			} 
		}
		cout <<"Case "<<orgT-T<<": "<< dis[1][N-1] <<"\n";
	}
    return 0;
}
