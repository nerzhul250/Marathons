#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,end=b;i<end;i++)
#define ALL(s) s.begin(),s.end()
#define SZ(s) int(s.size())
#define pb push_back
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
ii stations [1005];
int Co2PerDist [105];
vector<ii> graph [1005];
 
int dist (int i, int j){
	int x1 = stations[i].first;
	int y1 = stations[i].second;
	int x2 = stations[j].first;
	int y2 = stations[j].second;
 
	return (int)(ceil(sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2))));
}
 
int dp[1005][105];
int solve (int station, int kilAvailable){
	if (kilAvailable < 0)
		return 1e9;
	if (station == 1004)
		return 0;
	//if(kilAvailable-dist(station,1004)<0)
	//	return 1e9;
	int &r = dp[station][kilAvailable];
	if (r != -1) return r;
	r = 1e9;
	for(ii goTo : graph[station]){
		r= min(r,solve(goTo.first, kilAvailable - dist(station,goTo.first))
					+ dist(station,goTo.first) * Co2PerDist[goTo.second]); 
	}
	return r;
}
 
int main()
{FIN;
 
	int xs, ys, xd, yd;
	cin >> xs >> ys >> xd >> yd;
	stations[0] = {xs,ys};
	stations[1004] = {xd, yd};
 
	int maxDist;
	cin >> maxDist;
	cin >> Co2PerDist[0];
 
	int T;
	cin >> T;
	fore(i,0,T)
		cin >> Co2PerDist[i+1];
	
	int N;
	cin >> N;
	fore(i,0,N){
		graph[0].pb({i+1, 0});
		int xi, yi, li;
		cin >> xi >> yi >> li;
		stations[i+1] = {xi, yi};
		fore(k,0,li){
			int j, mj;
			cin >> j >> mj;
			graph[i+1].pb({j+1, mj});
			graph[j+1].pb({i+1, mj}); 
		}
		graph[i+1].pb({1004, 0});
	}
	graph[0].pb({1004, 0});
	memset(dp, -1, sizeof dp);
	int ans = solve(0, maxDist);
	ans = ans == 1e9 ? -1 : ans;
	cout << ans << "\n";
	return 0;
}
