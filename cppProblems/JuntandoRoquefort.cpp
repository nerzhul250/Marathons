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
int parent[10005];
int value[10005];
int main(){FIN;
	int N,D;
	cin >> N >> D;
	vector<int> maximo;
	fore(i,0,D)maximo.pb(0);
	fore(i,0,N)cin >> value[i];
	fore(i,0,N){
		cin >> parent[i];
		if(parent[i]!=-1)parent[i]--;
	}
	fore(i,0,N){
		int cnt=1;
		int curr=i;
		vector<int> path;
		path.pb(value[curr]);
		while(cnt<D && parent[curr]!=-1){
			cnt++;
			curr=parent[curr];
			path.pb(value[curr]);
		}
		if(cnt==D){
			reverse(ALL(path));
			if(path>maximo)maximo=path;
		}
	}
	fore(i,0,maximo.size()){
		if(i==maximo.size()-1)cout << maximo[i]<<"\n";
		else cout << maximo[i]<<" ";
	}
    return 0;
}
