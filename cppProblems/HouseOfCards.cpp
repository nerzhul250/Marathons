#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int main(){FIN;
	string h;
	cin >> h;
	int mod8=0;
	fore(i,0,h.size()){
		mod8*=10;
		mod8+=(h[i]-'0');
		mod8=mod8%8;
	}
	vector<int> ans;
	int toSum=0;
	if(mod8==1){
		toSum=4;
	}else if(mod8==2){
		toSum=3;
	}else if(mod8==3){
		toSum=2;
	}else if(mod8==4){
		toSum=1;
	}else if(mod8==5){
		toSum=0;
	}else if(mod8==6){
		toSum=2;
	}else if(mod8==7){
		toSum=1;
	}else if(mod8==0){
		toSum=0;
	}
	for(int i=h.size()-1;i>=0;i--){
		int sum=(h[i]-'0')+toSum;
		if(sum>=10){
			toSum=sum/10;
			ans.pb(sum-10);
		}else{
			toSum=0;
			ans.pb(sum);
		}
	}
	if(toSum!=0){
		ans.pb(toSum);
	}
	reverse(ALL(ans));
	fore(i,0,ans.size()){
		if(i==ans.size()-1)cout <<ans[i]<<"\n";
		else cout << ans[i];
	}
    return 0;
}
