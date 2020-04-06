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

const ll INF=1e16;
const int MAXN=505;

ll g[MAXN][MAXN];int n;
void floyd(){ // O(n^3) . Replaces g with min distances
	fore(k,0,n){
		fore(i,0,n){
			fore(j,0,n){
				g[i][j]=max(g[i][j],min(g[i][k],g[k][j]));
			}
		}
	}
}
int m;
ll d[MAXN][MAXN];
int main(){FIN;
	cin >> n>>m;
	fore(i,0,m){
		vector<ll> pref;
		fore(j,0,n){
			ll rank;
			cin >> rank;
			pref.pb(rank);
		}
		fore(j,0,n){
			fore(k,0,n){
				if(pref[k]!=0 && pref[j]!=0){
					if(pref[j]>pref[k])d[k][j]++;
				}else if(pref[k]!=0){
					d[k][j]++;
				}
			}
		}
	}
	fore(i,0,n)fore(j,0,n)g[i][j]=0;
	fore(i,0,n)fore(j,0,n)if(d[i][j]>d[j][i])g[i][j]=d[i][j];
	floyd();
	vector<int> ans;
	fore(i,0,n){
		bool most=true;
		fore(j,0,n){
			if(g[i][j]<g[j][i]){
				most=false;
				break;
			}
		}
		if(most){
			ans.pb(i+1);
		}
	}
	fore(i,0,ans.size()){
		if(i==ans.size()-1){
			cout << ans[i] << "\n";
		}else{
			cout << ans[i] << " ";
		}
	}
    return 0;
}
