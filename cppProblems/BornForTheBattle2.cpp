/*
 * c.cpp
 *
 *  Created on: Sep 5, 2014
 *      Author: ghooo
 */

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz(v) ((ll)v.size())
#define rep(i,m) for(int i=0;i<(int)(m);++i)
#define repe(i,n,m) for(int i=n;i<=(int)(m);++i)
#define rep2(i,n,m) for(int i=n;i<(int)(m);i++)
#define For(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define reset(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define dot(a,b) ((conj(a)*(b)).X)
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)
#define clrq(x) while(!x.empty()) x.pop();
#define clrvv(v) rep(i,sz(v))v[i].clear();
#define debug(x) cerr << #x << ": " << x << endl;
#define debugv(v) cerr << #v << ": ";For(it,v)cerr <<(*it)<<", "; cerr<<endl;

typedef stringstream ss;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vii;
typedef long double ld;
typedef complex<double> point;
typedef pair<point, point> segment;
typedef pair<double, point> circle;
typedef vector<point> polygon;
typedef unsigned long long ull;
typedef long long ll;

//==============================================================
// handling triples
typedef pair<ll,pair<ll,ll> > triple;
#define tfirst first
#define tsecond second.first
#define tthird second.second
#define mt(x,y,z) mp(x,mp(y,z))
//---------------------------------------------------------------

const int oo = (int) 1e9+10;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
vector<vector<pii> > adj;
vector<triple> edges;
int n, m;
vector<int> modifiedDijkstra(int f){
 vector<int> dist(n,oo);
 priority_queue<pii> pq;
 pq.push(mp(0,f));
 dist[f] = 0;
 vector<bool> vis(n,false);
 while(!pq.empty()){
  int cur = pq.top().second, curC = -pq.top().first;
  pq.pop();
  if(vis[cur])continue;
  vis[cur]=true;
  if(curC != dist[cur]) continue;
  rep(i,sz(adj[cur])){
   int nxt = adj[cur][i].first, nxtC = max(adj[cur][i].second,curC);
   if(vis[nxt])continue;
   if(nxtC < dist[nxt]){
    pq.push(mp(-nxtC,nxt));
    dist[nxt] = nxtC;
   }
  }
 }
 return dist;
}
int main(){
ios_base::sync_with_stdio(false);
 cin >> n >> m;
 if(n == 1){
  cout << 0 << endl;
  return 0;
 }
 int a, b, c;
 adj.clear();
 edges.clear();
 adj.resize(n);
 rep(i,m){
  cin >> a >> b >> c;
  a--,b--;
  adj[a].pb(mp(b,c));
  adj[b].pb(mp(a,c));
  edges.pb(mt(a,b,c));
 }
 vector<int> d1 = modifiedDijkstra(0), dn = modifiedDijkstra(n-1);
 int ans = oo;
 rep(i,sz(edges)){
  int c = edges[i].tthird, u = edges[i].tfirst, v = edges[i].tsecond;
  if(c >= d1[u] && c >= dn[v]) ans = min(ans,max(d1[u],dn[v]));
  if(c >= d1[v] && c >= dn[u]) ans = min(ans,max(d1[v],dn[u]));
 }
 cout << (ans==oo?-1:ans) << endl;
 return 0;
}
