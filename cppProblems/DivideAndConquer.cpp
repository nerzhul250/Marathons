#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef __int128 ll;

long long int b1,d1;
ll b,d;
int main(){FIN;
	cin >> b1 >> d1;
	b=b1;
	d=d1;
	vector<ll> cycle;
	cycle.pb(1);
	ll current=b%d;
	while(current!=1){
		assert(current>0);
		cycle.pb(current);
		current=(current*b)%d;
	}
	if(cycle.size()%2==0){
		bool sePuede=true;
		fore(i,cycle.size()/2,cycle.size()){
			if(cycle[i]!=((d-1)*cycle[i-(cycle.size()/2)])%d)sePuede=false;
		}
		if(sePuede){
			cout << "yes\n";
		}else{
			cout << "no\n";
		}
	}else{
		cout <<"no\n";
	}
    return 0;
}
