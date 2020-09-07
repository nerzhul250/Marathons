#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
 
using namespace std;
 
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
 
int main(){FIN;
	vector<vector<string>>hh(20),mm(20);
	vector<int> nums = {6,2,5,5,4,5,6,3,7,6};
	for(int i = 0; i<24; i++){
		int num = i;
		int cant = 0;
		fore(j,0,2){
			cant += nums[num%10];
			num/=10;
		}
		if(i<10){
			hh[cant].pb("0"+to_string(i));
		}else{
			hh[cant].pb(to_string(i));
		}
	}
	for(int i = 0; i<60; i++){
		int num = i;
		int cant = 0;
		fore(j,0,2){
			cant += nums[num%10];
			num/=10;
		}
		if(i<10)
			mm[cant].pb("0"+to_string(i));
		else
			mm[cant].pb(to_string(i));
	}
 
	int n;cin>>n;
	bool can=false;
	string ans = "";
	for(int i = 1;i<20 && !can;i++){
		for(int j=1;j<20 && !can;j++){
			if(sz(hh[i])>0 && sz(mm[j])>0 && i+j == n){
//                cout<<i<<" "<<j<<"\n";
				can=true;
				ans = hh[i][0]+":"+mm[j][0];
 
			}
		}
	}
	if(can){
		cout<<ans<<"\n";
	}else{
		cout<<"Impossible\n";
	}
	return 0;
}
