#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef pair<int,int> ii;

template <class T> struct Edge {
    int from, to, index;
    T cap, flow;

    Edge(int from, int to, T cap, T flow, int index): from(from), to(to), cap(cap), flow(flow), index(index) {}
};

template <class T> struct PushRelabel {
    int n;
    vector <vector <Edge <T>>> adj;
    vector <T> excess;
    vector <int> dist, count;
    vector <bool> active;
    vector <vector <int>> B;
    int b;
    queue <int> Q;

    PushRelabel (int n): n(n), adj(n) {}

    void AddEdge (int from, int to, T cap) {
        adj[from].push_back(Edge <T>(from, to, cap, 0, adj[to].size()));
        if (from == to) {
            adj[from].back().index++;
        }
        adj[to].push_back(Edge <T>(to, from, 0, 0, adj[from].size() - 1));

    }

    void Enqueue (int v) {
        if (!active[v] && excess[v] > 0 && dist[v] < n) {
            active[v] = true;
            B[dist[v]].push_back(v);
            b = max(b, dist[v]);
        }
    }

    void Push (Edge <T> &e) {
        T amt = min(excess[e.from], e.cap - e.flow);
        if (dist[e.from] == dist[e.to] + 1 && amt > T(0)) {
            e.flow += amt;
            adj[e.to][e.index].flow -= amt;
            excess[e.to] += amt;
            excess[e.from] -= amt;
            Enqueue(e.to);
        }

    }

    void Gap (int k) {
        for (int v = 0; v < n; v++) if (dist[v] >= k) {
            count[dist[v]]--;
            dist[v] = max(dist[v], n);
            count[dist[v]]++;
            Enqueue(v);
        }
    }

    void Relabel (int v) {
        count[dist[v]]--;
        dist[v] = n;
        for (auto e: adj[v]) if (e.cap - e.flow > 0) {
            dist[v] = min(dist[v], dist[e.to] + 1);
        }
        count[dist[v]]++;
        Enqueue(v);
    }

    void Discharge(int v) {
        for (auto &e: adj[v]) {
            if (excess[v] > 0) {
                Push(e);
            } else {
                break;
            }
        }

        if (excess[v] > 0) {
            if (count[dist[v]] == 1) {
                Gap(dist[v]);
            } else {
                Relabel(v);
            }
        }
    }

    T GetMaxFlow (int s, int t) {
        dist = vector <int>(n, 0), excess = vector<T>(n, 0), count = vector <int>(n + 1, 0), active = vector <bool>(n, false), B = vector <vector <int>>(n), b = 0;

        for (auto &e: adj[s]) {
            excess[s] += e.cap;
        }
        count[0] = n;
        Enqueue(s);
        active[t] = true;
        while (b >= 0) {
            if (!B[b].empty()) {
                int v = B[b].back();
                B[b].pop_back();
                active[v] = false;
                Discharge(v);
            } else {
                b--;
            }
        }
        return excess[t];
    }
};

void addToPoints(vector<ii>& points,ii thePoint){
	if(points.size()!=0 && points.back().ss==thePoint.ff){
		ii theSecondPoint=points.back();
		points.pop_back();
		points.pb({theSecondPoint.ff,thePoint.ss});
	}else{
		points.pb(thePoint);
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,t=0;
    while(cin >> n){
        if(n==0)break;
        t++;
        cin >> m;    
        int sum=0;
        vector<pair<ii,int>> monkeys;
        vector<int> intervalPoints;
        set<int> theSet;
        for(int i=0;i<n;i++){
            int v,a,b;
            cin >> v >> a >> b;
            monkeys.pb({{a,b},v});
            if(theSet.find(a)==theSet.end())intervalPoints.pb(a);
            theSet.insert(a);
            if(theSet.find(b-1)==theSet.end())intervalPoints.pb(b-1);
            theSet.insert(b-1);
            sum+=v;
        }
        sort(intervalPoints.begin(),intervalPoints.end());
        int siguiente=-1;
        vector<pair<ii,int>> intervals;
        fore(i,0,intervalPoints.size()){
			int endPoint=intervalPoints[i];
			if(siguiente!=-1){
				if(siguiente!=endPoint)intervals.pb({{siguiente,endPoint},endPoint-siguiente});
			}
			siguiente=endPoint+1;
			intervals.pb({{endPoint,siguiente},siguiente-endPoint});
		}
        PushRelabel<int> mfGraph(n+intervals.size()+2);
        for(int i=0;i<n;i++){
            mfGraph.AddEdge(0,i+1,monkeys[i].ss);
            fore(j,0,intervals.size()){
				if(i==0)mfGraph.AddEdge(n+j+1,1+n+intervals.size(),m*intervals[j].ss);
				if(monkeys[i].ff.ff<=intervals[j].ff.ff && intervals[j].ff.ss<=monkeys[i].ff.ss){
					mfGraph.AddEdge(i+1,n+j+1,intervals[j].ss);
				}
			}
        }
        int maxFlow=mfGraph.GetMaxFlow(0,1+n+intervals.size());
        if(maxFlow==sum){
            cout << "Case "<<t<<": Yes\n";
            for(int i=0;i<n;i++){
                vector<ii> points;
                fore(j,0,mfGraph.adj[i+1].size()){
					//cout <<i<<" "<<j<<" here"<<endl;
					int intervalIndex=mfGraph.adj[i+1][j].to-n-1;
					ii theInterval=intervals[intervalIndex].ff;
					int momentsRem=intervals[intervalIndex].ss;
					int flow=mfGraph.adj[i+1][j].flow;
					int cap=mfGraph.adj[i+1][j].cap;
					//cout << theInterval.ff<<" "<<theInterval.ss<<" "<<momentsRem<<" "<<flow<<" "<<cap<<endl;
					if(flow>0){
						if(flow<momentsRem){
							int leftEnd=theInterval.ss-momentsRem;
							int rightEnd=leftEnd+flow;
							intervals[intervalIndex].ss=intervals[intervalIndex].ss-flow;
							addToPoints(points,ii(leftEnd,rightEnd));
						}else if(flow==momentsRem){
							int leftEnd=theInterval.ss-momentsRem;
							int rightEnd=leftEnd+flow;
							intervals[intervalIndex].ss=intervals[intervalIndex].ff.ss-intervals[intervalIndex].ff.ff;
							addToPoints(points,ii(leftEnd,rightEnd));
						}else if(flow>momentsRem){
							if(flow==intervals[intervalIndex].ff.ss-intervals[intervalIndex].ff.ff){
								int leftEnd=theInterval.ff;
								int rightEnd=theInterval.ss;
								addToPoints(points,ii(leftEnd,rightEnd));
							}else{
								int remFlow=flow-momentsRem;
								addToPoints(points,ii(intervals[intervalIndex].ff.ff,intervals[intervalIndex].ff.ff+remFlow));
								addToPoints(points,ii(intervals[intervalIndex].ff.ss-momentsRem,intervals[intervalIndex].ff.ss));
								intervals[intervalIndex].ss=intervals[intervalIndex].ff.ss-(intervals[intervalIndex].ff.ff+remFlow);
							}
						}
					}
				}
                cout << points.size();
                for(int k=0;k<points.size();k++){
                    cout << " (" << points[k].first << "," << points[k].second << ")";
                }
                cout << "\n";
            }
        }else{
            cout << "Case "<<t<<": No\n";
        }
    }
    return 0;
}
