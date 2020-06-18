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
int main(){FIN;
	int n,m;
	cin >> n >> m;
	queue<ii> q;
	set<ll> visited;
	fore(i,0,n){
		ll tree;
		cin >> tree;
		visited.insert(tree);
		q.push(ii(tree,0));
	}
	ll res=0;
	vector<ll> people;
	while(m){
		ii node=q.front();
		q.pop();
		if(m && visited.count(node.ff-1)==0){
			visited.insert(node.ff-1);
			m--;
			q.push(ii(node.ff-1,node.ss+1));
			people.pb(node.ff-1);
			res+=node.ss+1;
		}
		if(m && visited.count(node.ff+1)==0){
			visited.insert(node.ff+1);
			m--;
			q.push(ii(node.ff+1,node.ss+1));
			people.pb(node.ff+1);
			res+=node.ss+1;
		}
	}
	cout << res << "\n";
	fore(i,0,people.size()){
		if(i==SZ(people)-1){
			cout << people[i] << "\n";
		}else{
			cout << people[i] << " ";
		}
	}
    return 0;
}
