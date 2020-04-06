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
	ll n,h;
	cin >> n >> h;
	ll original[n+1];
	ll sortedOriginal[n+1];
	fore(i,0,n){cin >> original[i];sortedOriginal[i]=original[i];}
	int left=0;
	int right=n-1;
	int ans=0;
	while(left<=right){
		int k=(left+right)/2;
		sort(sortedOriginal,sortedOriginal+k+1);
		int j=k;
		ll sum=0;
		while(j>=0){
			sum+=sortedOriginal[j];
			j-=2;
		}
		fore(i,0,k+1)sortedOriginal[i]=original[i];
		if(sum>h){
			right=k-1;
		}else{
			left=k+1;
			ans=k;
		}
	}
	cout << ans+1 << "\n";
    return 0;
}
