#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef long long int ll;

const int MAXN=100005;

vector<int> g[MAXN];

set<int> g2[MAXN];
int sizeSCC[MAXN];

int d[MAXN], low[MAXN], scc[MAXN];
bool stacked[MAXN];
stack<int> s;
int ticks, current_scc;
void tarjan(int u){
  d[u] = low[u] = ticks++;
  s.push(u);
  stacked[u] = true;
  const vector<int> &out = g[u];
  for (int k=0, m=out.size(); k<m; ++k){
    const int &v = out[k];
    if (d[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    }else if (stacked[v]){
      low[u] = min(low[u], low[v]);
    }
  }
  if (d[u] == low[u]){
    int v;
    int cnt=0;
    do{
      v = s.top();
      s.pop();
      stacked[v] = false;
      scc[v] = current_scc;
      cnt++;
    }while (u != v);
    sizeSCC[current_scc]=cnt;
    current_scc++;
  }
}
void init_tarjan(){
	memset(d,-1,sizeof d);
	while(!s.empty())s.pop();
	memset(stacked,0,sizeof stacked);
	ticks=0;
	current_scc=0;
}


vector<int> tsort(int n){  // lexicographically smallest topological sort
	vector<int> r;priority_queue<int> q;
	vector<int> d(2*n,0);
	fore(i,0,n)for(int j:g2[i])d[j]++;
	fore(i,0,n)if(!d[i])q.push(-i);
	while(!q.empty()){
		int x=-q.top();q.pop();r.pb(x);
		for(int i:g2[x]){
			d[i]--;
			if(!d[i])q.push(-i);
		}
	}
	return r;  // if not DAG it will have less than n elements
}

int n,m;
int acumNodesSCC[MAXN];
int main(){FIN;
	cin >> n >> m;
	fore(i,0,m){
		int x,y;
		cin >> x >> y;
		g[x].pb(y);
	}
	init_tarjan();
	fore(i,0,n){
		if(d[i]==-1){
			tarjan(i);//flag
		}
	}
	fore(i,0,n){
		for(int u : g[i]){
			if(scc[i]!=scc[u]){
				g2[scc[i]].insert(scc[u]);
			}
		}
	}
	vector<int> orderedSCC=tsort(current_scc);
	int sum=0;
	for(int com : orderedSCC){
		sum+=sizeSCC[com];
		acumNodesSCC[com]=sum;
	}
	ll maxNum=0;
	fore(i,0,n){
		maxNum+=n;
		maxNum-=acumNodesSCC[scc[i]];
		for(int u:g[i])if(scc[i]!=scc[u])maxNum--;
	}
	cout << maxNum << "\n";
    return 0;
}

