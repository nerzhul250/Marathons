#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int arr[200005];
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		int n,k;
		cin >> n >> k;
		fore(i,0,n)cin >> arr[i];
		int cnt=0;
		fore(i,0,k)if(i!=k-1 && i!=0 && arr[i]>arr[i-1] && arr[i]>arr[i+1])cnt++;
		int l=0,r=k-1;
		int maxCount=cnt;
		int index=0;
		while(r<n-1){
			if(arr[l+1]>arr[l] && arr[l+1]>arr[l+2])cnt--;
			l++;
			if(arr[r]>arr[r-1] && arr[r]>arr[r+1])cnt++;
			r++;
			if(cnt>maxCount){
				maxCount=cnt;
				index=l;
			}
		}
		cout << maxCount+1 <<" "<< index+1<<"\n";
	}
    return 0;
}
