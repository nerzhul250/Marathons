#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
int q[100005];
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		fore(i,0,n){
			cin >> q[i];
		}
		int arr[n];
		set<int> can;
		fore(i,1,n+1){
			can.insert(i);
		}
		int prev=-1;
		fore(i,0,n){
			arr[i]=-1;
			if(q[i]!=prev){
				prev=q[i];
				arr[i]=q[i];
				can.erase(q[i]);
			}
		}
		
		fore(i,0,n){
			if(arr[i]==-1){
				arr[i]=*can.begin();
				can.erase(can.begin());		
			}
		}
		int maxi=arr[0];
		bool possible=true;
		fore(i,0,n){
			maxi=max(maxi,arr[i]);
			if(q[i]!=maxi){
				possible=false;
				break;
			}
		}
		if(possible){
			fore(i,0,n){
				if(i==n-1)cout << arr[i]<<"\n";
				else cout << arr[i]<<" ";
			}
		}else{
			cout << "-1\n";
		}
	}
    return 0;
}

