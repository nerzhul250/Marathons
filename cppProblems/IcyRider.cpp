#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
const int INF=1e9;
int main(){FIN;
	int n,m;
	cin >> n >> m;
	vector<int> assigns(m+1,INF);
	vector<pair<vector<int>,int>> events;
	fore(i,0,n){
		int k, maximo;
		cin >> k >> maximo;
		events.pb({vector<int>(),maximo});
		fore(j,0,k){
			int person;
			cin >> person;
			events[i].ff.pb(person);
			assigns[person]=min(assigns[person],maximo);
		}
	}
	bool possible=true;
	fore(i,0,n){
		int maximo=-1;
		for(int per:events[i].ff){
			maximo=max(maximo,assigns[per]);
		}
		if(maximo!=events[i].ss){
			possible=false;
			break;
		}
	}
	if(possible){
		cout << "Good memory\n";
		fore(i,1,m+1){
			if(i==m)cout << assigns[i]<<"\n";
			else cout << assigns[i]<<" ";
		}
	}else{
		cout << "Poor memory\n";
	}
    return 0;
}
