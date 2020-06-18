#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
int arr[100005];
int dp[100005];
int main(){FIN;
	int n;
	cin >>n;
	fore(i,0,n){
		cin >> arr[i];
	}
	int maximum=-1e8;
	fore(mx,-30,31){
		int temp[n];
		fore(i,0,n){
			temp[i]=arr[i];
			if(temp[i]>mx){
				temp[i]=-1e8;
			}
		}
		fore(i,0,n){
			dp[i]=-1e8;
		}
		dp[0]=temp[0];
		fore(i,1,n){
			dp[i]=max(temp[i],dp[i-1]+temp[i]);
		}
		int currMax=-1e8;
		fore(i,0,n){
			currMax=max(currMax,dp[i]);
		}
		maximum=max(currMax-mx,maximum);
	}
	cout << maximum<<"\n";
    return 0;
}
