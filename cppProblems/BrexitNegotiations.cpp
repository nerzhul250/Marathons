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
const int MAXN=400005;
vector<int> g[MAXN];int n;
int minutes[400005];
int main(){FIN;
	cin >> n;
	fore(i,0,n){
		int d;
		cin >> minutes[i] >> d;
		fore(j,0,d){
			int v;
			cin >>v;
			v--;
			g[i].pb(v);
		}
	}
	int maximum=-1;
	int currK=n-1;
	priority_queue<ii> q;
	vector<int> d(2*n,0);
	fore(i,0,n)fore(j,0,g[i].size())d[g[i][j]]++;
	fore(i,0,n)if(!d[i])q.push(ii(-minutes[i],i));
	while(!q.empty()){
		ii e=q.top();q.pop();
		int x=e.ss;
		maximum=max(maximum,currK+(-1*e.ff));
		currK--;
		fore(i,0,g[x].size()){
			d[g[x][i]]--;
			if(!d[g[x][i]])q.push(ii(-minutes[g[x][i]],g[x][i]));
		}
	}
	cout << maximum << "\n";
    return 0;
}
