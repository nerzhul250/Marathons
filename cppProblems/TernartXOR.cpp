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
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		int phase=0;
		vector<int>ans1,ans2;
		fore(i,0,n){
			if(phase==0){
				if(s[i]=='2'){
					ans1.pb(1);
					ans2.pb(1);
				}else if(s[i]=='1'){
					ans1.pb(1);
					ans2.pb(0);
					phase=1;
				}else if(s[i]=='0'){
					ans1.pb(0);
					ans2.pb(0);
				}
			}else{
				if(s[i]=='2'){
					ans1.pb(0);
					ans2.pb(2);
				}else if(s[i]=='1'){
					ans1.pb(0);
					ans2.pb(1);
				}else if(s[i]=='0'){
					ans1.pb(0);
					ans2.pb(0);
				}
			}
		}
		fore(i,0,n){
			if(i==n-1){
				cout <<ans1[i] << "\n";
			}else{
				cout << ans1[i];
			}
		}
		fore(i,0,n){
			if(i==n-1){
				cout <<ans2[i] << "\n";
			}else{
				cout << ans2[i];
			}
		}
	}	
    return 0;
}
