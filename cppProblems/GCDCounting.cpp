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
map<int,ii> dp[MAXN];
vector<int> g[MAXN];
set<int> factors[MAXN];
void dfs(int u, int p){
	for(int v:g[u])if(v!=p)dfs(v,u);
	for(int f:factors[u]){
		int max1=0;
		int max2=0;
		for(int v:g[u]){
			if(v!=p && dp[v].count(f)){
				int val=dp[v][f].ff;
				assert(val>0);
				if(val>=max1){
					max2=max1;
					max1=val;
				}else if(val>max2){
					max2=val;
				}
			}
		}
		if(max2==0){
			dp[u][f]=ii(max1+1,0);
		}else{
			dp[u][f]=ii(max1+1,max2+1);
		}
	}
	return ;
}
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n){
		int num;
		cin >> num;
		for(int j=2;j*j<=num;j++){
			if(num%j==0){
				factors[i].insert(j);
				while(num%j==0){
					num/=j;
				}
			}
		}
		if(num>1)factors[i].insert(num);
	}
	fore(i,0,n-1){
		int x,y;
		cin >> x >> y;
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(0,-1);
	int maximo=0;
	fore(u,0,n){
		for(auto it=dp[u].begin();it!=dp[u].end();it++){
			ii v=it->ss;
			//cout << v.ff << " "<<v.ss<<endl;
			if(v.ss==0){
				maximo=max(maximo,v.ff);
			}else{
				maximo=max(maximo,v.ff+v.ss-1);
			}
		}
	}
	cout << maximo<<"\n";
    return 0;
}
