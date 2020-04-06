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
ll lengths[100005];
int main(){FIN;
	ll n,m;
	cin >> n>>m;
	ll sum=0;
	fore(i,0,m){cin >> lengths[i];sum+=lengths[i];}
	if(sum<n){
		cout << "-1\n";
	}else{
		vector<ii> positions;//pos,length
		ll rightEnd=-1;
		fore(i,0,m){
			rightEnd=max(rightEnd,i+lengths[i]);
			if(rightEnd>n)break;
			positions.pb(ii(i,lengths[i]));
		}
		if(rightEnd>n){
			cout << "-1\n";
		}else{
			int index=m-1;
			positions[index].ff=n-positions[index].ss;
			index--;
			while(positions[index].ff+positions[index].ss<positions[index+1].ff){
				positions[index].ff=positions[index+1].ff-positions[index].ss;
				index--;
			}
			fore(i,0,m){
				if(i==m-1){
					cout << positions[i].ff+1<<"\n";
				}else{
					cout << positions[i].ff+1<<" ";
				}
			}
		}
	}
	
    return 0;
}

