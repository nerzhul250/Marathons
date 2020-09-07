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
ii islands[200005];
ll match[200005];
ll bridges[200005];
map<ll,set<ii>> mp;
int main(){FIN;
	int n,m;
	cin >> n >> m;
	fore(i,0,n)match[i]=-1;	
	fore(i,0,n)cin >> islands[i].ff >> islands[i].ss;
	fore(i,0,m)cin >> bridges[i];
	vector<ii> intervals;
	fore(i,0,n-1)intervals.pb(ii(islands[i+1].ff-islands[i].ss,islands[i+1].ss-islands[i].ff));
	fore(i,0,m){
		mp[bridges[i]].insert(ii(1,i));
	}
	fore(i,0,n-1){
		mp[intervals[i].ff].insert(ii(0,i));
		mp[intervals[i].ss].insert(ii(2,i));
	}
	set<ii> ides;
	for(auto it=mp.begin();it!=mp.end();it++){
		set<ii> st=it->ss;
		for(auto it2=st.begin();it2!=st.end();it2++){
			ii v=*it2;
			if(v.ff==0){
				ides.insert(ii(intervals[v.ss].ss,v.ss));
			}else if(v.ff==1){
				if(ides.size()!=0){
					match[(*ides.begin()).ss]=v.ss;
					ides.erase(ides.begin());
				}
			}else if(v.ff==2){
				if(match[v.ss]==-1){
					cout << "No\n";
					return 0;
				}
			}
		}
	}
	cout << "Yes\n";
	fore(i,0,n-1){
		cout << match[i]+1<<" ";
	}
	cout << "\n";
    return 0;
}
