#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int> ii;
int arr[200005],rightPos[200005],extracted[200005];
int main(){FIN;
	int n,K;
	cin >> n >> K;
	fore(i,0,n){
		cin >> arr[i];
		rightPos[arr[i]]=i;
	}
	vector<int> ans;
	fore(i,0,n){
		if(extracted[arr[i]])continue;
		while(ans.size()!=0 && ans.back()>arr[i] && rightPos[ans.back()]>i){			
			extracted[ans.back()]=0;
			ans.pop_back();
		}
		ans.pb(arr[i]);
		extracted[arr[i]]=1;
	}
	fore(i,0,K){
		if(i==K-1)cout << ans[i]<<"\n";
		else cout << ans[i]<<" ";
	}
    return 0;
}
