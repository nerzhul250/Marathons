#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int arr[55];
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >>n;
		fore(i,0,n)cin>>arr[i];
		sort(begin(arr),begin(arr)+n);
		int rem1=0,rem0=0,close=0;
		fore(i,0,n){
			if(arr[i]%2==0){
				rem0++;
			}else{
				rem1++;
			}
			if(i && abs(arr[i]-arr[i-1])==1){
				close++;
			}
		}
		if(rem1%2==0 && rem0%2==0){
			cout << "YES\n";
		}else if(rem1%2!=0 && rem0%2!=0){
			if(close>0){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}else{
			cout << "NO\n";
		}
	}
    return 0;
}
