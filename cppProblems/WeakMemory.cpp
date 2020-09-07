#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
class UnionFind {                                // OOP style
private:
  vi p, rank, setSize;                           // vi p is the key part
  int numSets;
public:
  UnionFind(int N) {
    p.assign(N, 0); for (int i = 0; i < N; ++i) p[i] = i;
    rank.assign(N, 0);                           // optional speedup
    setSize.assign(N, 1);                        // optional feature
    numSets = N;                                 // optional feature
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  int numDisjointSets() { return numSets; }      // optional
  int sizeOfSet(int i) { return setSize[findSet(i)]; } // optional

  void unionSet(int i, int j) {
    if (isSameSet(i, j)) return;                 // i and j are in same set
    int x = findSet(i), y = findSet(j);          // find both rep items
    if (rank[x] > rank[y]) swap(x, y);           // keep x 'shorter' than y
    p[x] = y;                                    // set x under y
    if (rank[x] == rank[y]) ++rank[y];           // optional speedup
    setSize[y] += setSize[x];                    // combine set sizes at y
    --numSets;                                   // a union reduces numSets
  }
};
const int MAXN=100005;
const int MAXM=200005;
ii values[MAXN];
vector<int> g[MAXN];
int main(){FIN;	
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> volunteers;
	fore(i,0,k){
		int nam;
		cin >> nam;
		nam--;
		volunteers.pb(nam);
	}
	fore(i,0,m){
		int u,v;
		cin >> u >> v;
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	int s,t;
	cin >> s >> t;
	s--;t--;
	volunteers.pb(s);volunteers.pb(t);
	int l=1,r=n;
	int minimo=-1;
	while(l<=r){
		int m=(l+r)/2;
		fore(i,0,n)values[i]=ii(-1,-1);
		queue<ii> q;
		fore(i,0,volunteers.size()){
			q.push(ii(volunteers[i],0));
			values[volunteers[i]]=ii(volunteers[i],0);
		}
		UnionFind uf(n);
		while(!q.empty()){
			ii u=q.front();
			q.pop();
			for(int v:g[u.ff]){
				if(values[v].ff==-1){
					values[v]=ii(values[u.ff].ff,u.ss+1);
					q.push(ii(v,u.ss+1));
				}else if(values[v].ss+u.ss+1<=m){
					uf.unionSet(values[v].ff,values[u.ff].ff);
				}
			}
		}
		if(uf.isSameSet(s,t)){
			minimo=(minimo==-1?m:min(minimo,m));
			r=m-1;
		}else{
			l=m+1;
		}
	}
	cout << minimo << "\n";
    return 0;
}
