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
typedef pair<ll,ll> ii;

ll oblig[200005],type[200005],tasksCnt[5];
int main(){FIN;
	ll m;
	cin >> m;
	while(m--){
		ll n,T,a,b;
		cin >> n >> T >> a >> b;
		fore(i,0,n){
			cin >> type[i];
			tasksCnt[type[i]]++;
		}
		fore(i,0,n)cin >> oblig[i];
		vector<ii> problems;
		fore(i,0,n)problems.pb(ii(oblig[i],type[i]));
		sort(ALL(problems));
		ll reqTime=0;
		ll maxSolved=0;
		fore(i,0,n){
			if(i!=0 && problems[i-1].ff==problems[i].ff){				
				reqTime+=(problems[i].ss?b:a);
				tasksCnt[problems[i].ss]--;
				continue;
			}
			ll remTime=problems[i].ff-1-reqTime;
			if(remTime>0){				
				ll maxA=min(remTime/a,tasksCnt[0]);
				remTime-=maxA*a;
				ll maxB=min(remTime/b,tasksCnt[1]);
				maxSolved=max(maxSolved,i+maxA+maxB);
			}else if(remTime==0){
				maxSolved=max(maxSolved,(ll)i);
			}
			reqTime+=(problems[i].ss?b:a);
			tasksCnt[problems[i].ss]--;
		}
		ll remTime=T-reqTime;
		if(remTime>=0){
			maxSolved=n;
		}
		cout << maxSolved << "\n";
	}
    return 0;
}
