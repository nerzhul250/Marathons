#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
int arr[305];
vector<int> groups;
int dp[305][305];
int go(int l,int r){
	if(l+1==r)return 0;
	if(dp[l][r]!=-1)return dp[l][r];
	int &m=dp[l][r];
	m=1e9;
	fore(i,l+1,r){
		m=min(m,((groups[l]==groups[i] || groups[i]==groups[r])?0:1)+go(l,i)+go(i,r));
	}
	return m;
}
int main(){FIN;
	int N,M;	
	cin >> N >> M;
	fore(i,0,N)cin >> arr[i];
	int prev=arr[0];
	fore(i,1,N){
		if(prev!=arr[i]){
			groups.pb(prev);
			prev=arr[i];
		}
	}
	groups.pb(prev);
	if(groups.size()==1){
		cout << "0\n";
		return 0;
	}
	groups.insert(groups.begin(),-1);
	memset(dp,-1,sizeof dp);
	int minimo=1e9;
	fore(l,1,groups.size()-1){
		fore(r,l+1,groups.size()){
			minimo=min(minimo,(groups[l]==groups[r]?0:1)+go(0,l)+go(l,r)+go(r,groups.size()));
		}
	}
	cout << minimo<<"\n";
	return 0;
}
