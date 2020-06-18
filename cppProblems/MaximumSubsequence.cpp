#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
 
int main(){FIN;
	while(1){
		int n,k; cin>>n>>k;
		if(n+k==0)break;
		vector<ll> pos,neg;
		vector<ll> all;
		fore(i,0,n){
			ll x; cin>>x;
			if(x>0){ pos.pb(x);}
			else if(x<0){neg.pb(x);}
			all.pb(x);
		}
		sort(ALL(all)); reverse(ALL(all));
		sort(ALL(pos)); sort(ALL(neg));
		reverse(ALL(pos));
		vector<ll> sp(SZ(pos)),sn(SZ(neg));
		vector<double> mp(SZ(pos)),mn(SZ(neg));
 
 
		fore(i,0,SZ(pos)){
			sp[i]=pos[i]; if(i)sp[i]+=sp[i-1];
			mp[i]=log(pos[i]); if(i)mp[i]+=mp[i-1];
		}
 
		fore(i,0,SZ(neg)){
			sn[i]=neg[i]; if(i)sn[i]+=sn[i-1];
			mn[i]=log(abs(neg[i])); if(i)mn[i]+=mn[i-1];
		}
 
 
		pair<double,ll> ans={-1e18,-1e18};
		//usar cantidad par de negativos
		for(int am=0;am<=k&&am<=SZ(neg);am+=2){
			int rem=k-am;
			if(SZ(pos)>=rem){
				double lg=0;
				ll ss=0;
				if(rem) ss+=sp[rem-1],lg+=mp[rem-1];
				if(am) ss+=sn[am-1],lg+=mn[am-1];
				pair<double,ll> now={lg,ss};
				ans=max(ans,now);
			}
		}
		//como uso cantidad impar de negativos, tengo que usar un 0, me quedo con lo mejor
 
		ll zz=0;
		fore(i,0,k) zz+=all[i];
		if(ans.fst==-1e18) ans.snd=zz;
		cout<<ans.snd<<"\n";
	}
}
