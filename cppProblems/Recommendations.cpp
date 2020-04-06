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

ll cat[200005],times[200005];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n){
		cin >> cat[i];
	}
	fore(i,0,n){
		cin >> times[i];
	}
	
	map<ll,vector<ll>>valores;
	fore(i,0,n)valores[cat[i]].pb(times[i]);
	
	multiset<ll> actual;
	ll suma=0;
	ll minimo=0;
	
	ll vlr=(valores.begin())->ff;
	ll lstVl=(valores.rbegin())->ff;
	while(vlr<=lstVl || actual.size()!=0){
		//cout << vlr<<endl;
		if(vlr<=lstVl)for(int val : valores[vlr]){actual.insert(val);suma+=val;}
		if(actual.size()==0){
			vlr=(valores.upper_bound(vlr))->ff;
			continue;
		}
		suma-=(*actual.rbegin());
		minimo+=suma;
		actual.erase(--actual.end());
		vlr++;
	}
	cout << minimo<<"\n";
    return 0;
}

