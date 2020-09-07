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
typedef pair<int,int> ii;
const int MAXN=200005;
int color[MAXN];
vector<ii> g[MAXN];
vector<int> cnt0;
vector<int> cnt1;
void dfs(int u){
	if(color[u]){
		cnt1.pb(u+1);
	}else{cnt0.pb(u+1);}
	
	for(ii v:g[u]){
		if(color[v.ff]==-1){
			if(v.ss==1){
				color[v.ff]=1-color[u];
			}else{
				color[v.ff]=color[u];
			}
			dfs(v.ff);
		}
	}
}
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int N;
		cin >> N;
		fore(i,0,N)g[i].clear();
		map<int,vector<ii>> mp;
		fore(i,0,2){
			fore(j,0,N){
				int nam;
				cin >> nam;
				mp[nam].pb(ii(i,j));
			}
		}
		bool possible=true;
		for(auto it=mp.begin();it!=mp.end() && possible;it++){
			if((it->ss).size()!=2){
				cout << "-1\n";
				possible=false;
			}
		}
		if(possible){
			for(auto it=mp.begin();it!=mp.end() && possible;it++){
				ii pos1=(it->ss)[0];
				ii pos2=(it->ss)[1];
				if(pos1.ss!=pos2.ss){
					if(pos1.ff==pos2.ff){
						g[pos1.ss].pb(ii(pos2.ss,1));
						g[pos2.ss].pb(ii(pos1.ss,1));
					}else{
						g[pos1.ss].pb(ii(pos2.ss,0));
						g[pos2.ss].pb(ii(pos1.ss,0));
					}
				}
			}
			fore(i,0,N)color[i]=-1;
			vector<int> ans;
			fore(i,0,N){
				if(color[i]==-1){
					color[i]=0;
					cnt0.clear();
					cnt1.clear();
					dfs(i);
					//cout << cnt0.size() << " "<<cnt1.size()<<endl;
					if(cnt1.size()<cnt0.size()){
						for(auto e:cnt1){
							ans.pb(e);
						}
					}else{
						for(auto e:cnt0){
							ans.pb(e);
						}
					}
				}
			}
			cout << ans.size()<<"\n";
			for(auto e:ans){
				cout << e << " ";
			}
			cout << "\n";
		}
	}
    return 0;
}
