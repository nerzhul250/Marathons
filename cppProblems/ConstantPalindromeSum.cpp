#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int arr[200005],cntx[400005],prefx[400005];
int n,k;
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> k;
		fore(i,0,n)cin>>arr[i];
		memset(cntx,0,sizeof cntx);
		memset(prefx,0,sizeof prefx);
		fore(i,0,n/2){
			cntx[arr[i]+arr[n-i-1]]++;
			prefx[min(arr[i],arr[n-i-1])+1]+=1;
			prefx[max(arr[i],arr[n-i-1])+k+1]+=-1;
		}
		int acum=0;
		fore(i,2,2*k+1){
			acum+=prefx[i];
			prefx[i]=acum;
		}
		int minNum=1e9;
		fore(i,2,2*k+1){
			minNum=min(minNum,(prefx[i]-cntx[i])+2*(n/2-prefx[i]));
		}
		cout << minNum<<"\n";
	}
    return 0;
}
