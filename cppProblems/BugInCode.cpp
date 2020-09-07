#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 3e5;
int freq[N+5];
map<ii,int> pairs;
int main(){FIN;
	int n,p; cin>>n>>p;
	fore(i,0,n){
		int a,b; 
		cin>>a>>b;
		if(a>b)swap(a,b);
		pairs[{a,b}]++;
		freq[a]++; freq[b]++;
	}
	ll cnt=0;
	for(int i =1; i<=n;i++)if(freq[i]>=p)cnt++;
	ll ans = (cnt*(cnt-1))/2; //parejas validas (v,v)
	ans += cnt*(n-cnt); // parejas validas (v,nv)
	
	vector<int> sorted;
	for(int i = 1; i<=n;i++){
		if(freq[i]<p){
			sorted.pb(freq[i]);
		}
	}
	sort(ALL(sorted));
	fore(i,0,sorted.size()){
		int required=p-sorted[i];
		auto it=lower_bound(sorted.begin()+i+1,sorted.end(),required);
		if(it!=sorted.end())ans+=(sorted.end()-it);
	}
	for(auto it=pairs.begin();it!=pairs.end();it++){
		ii u=it->ff;
		int fr=it->ss;
		if(freq[u.ff]+freq[u.ss]>=p && freq[u.ff]+freq[u.ss]-fr<p)ans--;
	}
	cout<<ans<<"\n";
	return 0;
}
