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
int gcd(int a,int b){return a?gcd(b%a,a):b;}
int values[1005];
int parent[1005];
vector<int> sons[1005];
int n;
map<int,int> factors(int x){
	map<int,int> mp;
	for(int i=2;i*i<=x;i++){
		while(x%i==0){
			x/=i;
			mp[i]++;
		}
	}
	if(x>1)mp[x]++;
	return mp;
}
int main(){FIN;
	/*
	freopen("divisibility-tree.in","r",stdin);
	freopen("divisibility-tree.out","w",stdout);
	*/
	
	cin >> n;
	fore(i,0,n){
		int p,a;
		cin >> p >> a;
		values[i]=a;
		if(p!=-1){
			p--;
			parent[i]=p;
			sons[p].pb(i);
		}else{
			parent[i]=p;
		}
	}
	
	if(n==1){
		cout << values[0]<<"\n";
		return 0;
	}
	
	for(int u=n-1;u>0;u--){
		if(values[parent[u]]==-1){
			values[parent[u]]=values[u];
		}else{
			values[parent[u]]=gcd(values[parent[u]],values[u]);
		}
	}
	values[0]=1;
	for(int u=0;u<n;u++){
		map<int,int> mp1=factors(values[u]);
		for(int v:sons[u]){
			if(values[u]==values[v]){
				fore(i,0,n){
					if(i==n-1)cout << "-1"<<"\n";
					else cout << "-1"<<" ";
				}
				exit(0);
			}
			if(sons[v].size()==0)continue;
			map<int,int> mp2=factors(values[v]);
			int bigger=0;
			int val=1;
			for(auto f:mp2){
				int cant=0;
				if(!bigger && f.ss>mp1[f.ff]){
					bigger=1;
					cant=mp1[f.ff]+1;
				}else{
					cant=mp1[f.ff];
				}
				fore(i,0,cant)val*=f.ff;
			}
			values[v]=val;
		}
	}
	
	fore(i,0,n){
		if(i==n-1)cout << values[i]<<"\n";
		else cout << values[i]<<" ";
	}
	return 0;
}

