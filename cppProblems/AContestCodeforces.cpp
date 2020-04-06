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

vector<ii> lets;
int colors[205];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n){
		char c;
		cin >> c;
		lets.pb(ii(c-'a',i));
	}
	sort(lets.begin(),lets.end());
	ii ref=lets[0];
	colors[ref.ss]=0;
	vector<ii> ones;
	fore(i,1,n){
		if(ref.ss<lets[i].ss){
			ref=lets[i];
			colors[ref.ss]=0;		
		}else{
			colors[lets[i].ss]=1;
			ones.pb(ii(lets[i].ss,i));
		}
	}
	sort(ones.begin(),ones.end());
	bool possible=true;
	fore(i,0,ones.size()-1){
		if(ones[i].ss>ones[i+1].ss){
			possible=false;
			break;
		}
	}
	if(possible){
		cout << "YES\n";
		fore(i,0,n){
			if(i==n-1){
				cout << colors[i] << "\n";
			}else{
				cout << colors[i];
			}
		}
	}else{
		cout << "NO\n";
	}
	return 0;
}
