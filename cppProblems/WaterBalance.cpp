#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef pair<double,int> di;

int main(){FIN;
	int n;
	cin >>n;
	vector<di> tanks;
	fore(i,0,n){
		int a;
		cin >> a;
		double v=a;
		int sz=1;
		while(!tanks.empty() && tanks.back().ff>v){
			v=(v*sz+tanks.back().ff*tanks.back().ss)/(sz+tanks.back().ss);
			sz+=tanks.back().ss;
			tanks.pop_back();
		}
		tanks.pb(di(v,sz));
	}
	cout << fixed;
	cout << setprecision(9);
	fore(i,0,tanks.size()){
		fore(j,0,tanks[i].ss){
			cout << tanks[i].ff<<"\n";
		}
	}
    return 0;
}
