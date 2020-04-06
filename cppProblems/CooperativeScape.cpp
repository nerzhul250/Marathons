#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

const int INF = 1000*1000*1000;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int r,c;

int vin(int i, int j){return (i*c+j)<<1;}
int vout(int i,int j){return ((i*c+j)<<1)|1;}
bool check(int i,int j){return i>=0 && j>=0 && i<r && j<c;}

struct rib {
    int b, u, c, f;
    size_t back;
};

void add_rib (vector < vector<rib> > & g, int a, int b, int u, int c) {
    rib r1 = { b, u, c, 0, g[b].size() };
    rib r2 = { a, 0, -c, 0, g[a].size() };
    g[a].push_back (r1);
    g[b].push_back (r2);
}

int main(){FIN;
	cin >> r >> c;
	int n=r*c*2+2,k=2;
    vector < vector<rib> > g (n);
    int s=r*c*2, t=r*c*2+1;
	
	fore(i,0,r){
		fore(j,0,c){
			fore(k,0,4){
				int io=i+dy[k];
				int jo=j+dx[k];
				if(check(io,jo))add_rib(g,vout(i,j),vin(io,jo),1,0);
			}
			char c;
			cin >>c;
			if(c=='.'){
				add_rib(g,vin(i,j),vout(i,j),1,1);
			}else if(c=='F'){
				add_rib(g,vin(i,j),vout(i,j),2,1);
				add_rib(g,vout(i,j),t,2,0);
			}else if(c=='B' || c=='C'){
				add_rib(g,s,vin(i,j),1,0);
				add_rib(g,vin(i,j),vout(i,j),1,0);
			}
		}
	}
	
	int flow = 0,  cost = 0;
    while (flow < k) {
		vector<int> id (n, 0);
        vector<int> d (n, INF);
        vector<int> q (n);
        vector<int> p (n);
        vector<size_t> p_rib (n);
        int qh=0, qt=0;
        q[qt++] = s;
        d[s] = 0;
        while (qh != qt) {
            int v = q[qh++];
            id[v] = 2;
            if (qh == n)  qh = 0;
            for (size_t i=0; i<g[v].size(); ++i) {
                rib & r = g[v][i];
                if (r.f < r.u && d[v] + r.c < d[r.b]) {
                    d[r.b] = d[v] + r.c;
                    if (id[r.b] == 0) {
                        q[qt++] = r.b;
                        if (qt == n)  qt = 0;
                    }
                    else if (id[r.b] == 2) {
                        if (--qh == -1)  qh = n-1;
                        q[qh] = r.b;
                    }
                    id[r.b] = 1;
                    p[r.b] = v;
                    p_rib[r.b] = i;
                }
            }
        }
        if (d[t] == INF)  break;
        int addflow = k - flow;
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_rib[v];
            addflow = min (addflow, g[pv][pr].u - g[pv][pr].f);
        }
        for (int v=t; v!=s; v=p[v]) {
            int pv = p[v];  size_t pr = p_rib[v],  r = g[pv][pr].back;
            g[pv][pr].f += addflow;
            g[v][r].f -= addflow;
            cost += g[pv][pr].c * addflow;
        }
        flow += addflow;
	}
	
	if(flow!=2){
		cout << "-1\n";
	}else{
		cout << cost << "\n";
	}
	
    return 0;
}
