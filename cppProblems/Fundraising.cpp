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

const int MAXN=100005;
ll ftArr[MAXN+10];
ll ft[MAXN+10];
void upd(int i0, ll v){
	ftArr[i0]=v;
	for(int i=i0;i<=MAXN;i+=i&-i)ft[i]=max(ft[i],v);
}
ll get(int i0){
	ll r=0;
	for(int i=i0;i;i-=i&-i)r=max(ft[i],r);
	return r;
}


map<ii,ll> persons;
set<ll> richness;
map<ll,ll> richnessToIndex;
vector<ii> orderedPeople;
ll peopToDon[100005];
int richnessSize;
int n;

int main(){FIN;
	cin >> n;
	fore(i,0,n){
		int B,F,D;
		cin >> B >> F >> D;
		persons[ii(B,F)]+=D;
		richness.insert(F);
	}
	richness.insert(0);
	int index=richness.size();
	richnessSize=index;
	for(auto it=richness.begin();it!=richness.end();it++){
		richnessToIndex[*it]=index;
		index--;
	}
	index=1;
	orderedPeople.pb(ii(0,0));
	peopToDon[0]=0;
	for(auto it=persons.begin();it!=persons.end();it++){
		orderedPeople.pb(it->ff);
		peopToDon[index]=it->ss;
		index++;
	}
	n=index;
	ll firsto=orderedPeople[n-1].ff;
	vector<ii> toUpdate;
	for(int i=n-1;i>=0;i--){
		if(orderedPeople[i].ff!=firsto){
			firsto=orderedPeople[i].ff;
			for(auto el : toUpdate)upd(el.ff,el.ss);
			toUpdate.clear();
		}
		index=richnessToIndex[orderedPeople[i].ss];
		toUpdate.pb(ii(index,max(ftArr[index],get(index-1)+peopToDon[i])));
	}
	cout << get(richnessSize) << "\n";
	return 0;
}
