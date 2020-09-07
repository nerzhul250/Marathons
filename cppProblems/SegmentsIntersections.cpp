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
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n;
		ll k;
		cin >> n >>k;
		ll l1,r1,l2,r2;
		cin >> l1>>r1;
		cin >> l2 >> r2;
		ll minCost=1e18;
		ll left=max(l1,l2);
		ll right=min(r1,r2);
		ll I=n*max((ll)0,right-left);
		ll cost=0;
		int matched=0;
		ll toAdd=(r1-l1)+(r2-l2)-(2*max((ll)0,right-left));
		if(left>right)toAdd+=left-right;
		ll toAddCost=left-min(l1,l2)+max(r1,r2)-right;
		while(matched<n && I+toAdd<k){
			I+=toAdd;
			cost+=toAddCost;
			matched++;
			minCost=min(minCost,(k-I)*2+cost);
		}
		if(I>=k){
			cout << min(minCost,cost)<<"\n";
		}else{
			if(matched==n){
				cout << min(minCost,(k-I)*2+cost) << "\n";
			}else{
				ll rem=k-I;
				if(left<=right){
					cout << min(minCost,cost+rem)<<"\n";
				}else{
					cost+=left-right;
					cout << min(minCost,cost+rem)<<"\n";
				}
			}
		}
	}	
    return 0;
}
