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
int ass[500005];
int freq[500005];
vector<int> g[500005];
int n,m;
int main(){FIN;
	cin >> n >> m;
	fore(i,0,m){
		int a,b;
		cin >> a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
	}
	vector<ii> orders;
	set<int>valid;
	fore(i,0,n){
		int nam;
		cin >> nam;
		orders.pb(ii(nam,i));
		valid.insert(i+1);
	}
	sort(ALL(orders));
	bool possible=true;
	fore(i,0,n){
		for(int v:g[orders[i].ss]){
			if(ass[v]!=0){
				valid.erase(ass[v]);
			}
		}
		if((*valid.begin())!=orders[i].ff){
			possible=false;
			break;
		}else{
			ass[orders[i].ss]=orders[i].ff;
		}
		for(int v:g[orders[i].ss]){
			if(ass[v]!=0){
				valid.insert(ass[v]);
			}
		}
	}
	if(possible){
		fore(i,0,n){
			if(i==n-1)cout <<orders[i].ss+1<<"\n";
			else cout << orders[i].ss+1<<" ";
		}
	}else{
		cout << "-1\n";
	}
	
    return 0;
}
