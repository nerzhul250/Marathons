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
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >>n;
		vector<ii> events;
		fore(i,0,n){
			int l,r;
			cin >> l >> r;
			events.pb(ii(l,0));
			events.pb(ii(r,1));
		}
		sort(ALL(events));
		int left=-1;
		int right=-1;
		fore(i,0,events.size()){
			if(events[i].ss==1){
				left=events[i].ff;
				break;				
			}
		}
		for(int i=events.size()-1;i>=0;i--){
			if(events[i].ss==0){
				right=events[i].ff;
				break;
			}
		}
		if(left<=right){
			cout << right-left << "\n";
		}else{
			cout << "0\n";
		}
	}
    return 0;
}
