#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef pair<string,string> ii;

vector<string> blocks;
int main(){FIN;
	int n,m;
	cin >> n >> m;
	fore(i,0,n){
		string s;
		cin >> s;
		blocks.pb(s);
	}
	vector<ii> doubPalin;
	vector<string> singlePalin;
	for(int i=0;i<blocks.size();i++){
		bool found=false;
		for(int j=i+1; j<blocks.size();j++){
			reverse(ALL(blocks[j]));
			if(blocks[i]==blocks[j]){
				reverse(ALL(blocks[j]));
				doubPalin.pb(ii(blocks[i],blocks[j]));
				blocks.erase(blocks.begin()+j);
				found=true;
				break;
			}
			reverse(ALL(blocks[j]));
		}
		string aux=blocks[i];
		reverse(ALL(blocks[i]));
		if(!found && blocks[i]==aux){
			singlePalin.pb(blocks[i]);
		}
		reverse(ALL(blocks[i]));
	}
	cout << doubPalin.size()*2*m + (singlePalin.size()?m:0) << "\n";
	string ans=(singlePalin.size()?singlePalin[0]:"");
	fore(i,0,doubPalin.size()){
		ans=doubPalin[i].ff+ans+doubPalin[i].ss;
	}
	cout << ans << "\n";
    return 0;
}

