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
int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		bool one=false;
		fore(i,0,n){
			cin>>arr[i];
			if(arr[i]>k){
				arr[i]=2;
			}else if(arr[i]==k){
				arr[i]=1;
				one=true;
			}else if(arr[i]<k){
				arr[i]=0;
			}
		}
		if(!one){
			cout << "no\n";
		}else{
			bool magicalPair=false;
			fore(i,0,n-1){
				if(arr[i]>0 && arr[i+1]>0){
					magicalPair=true;
					break;
				}
				if(i+2<n && arr[i]>0 && arr[i+2]>0){
					magicalPair=true;
					break;
				}
			}
			if(n==1)magicalPair=true;
			if(magicalPair){
				cout << "yes\n";
			}else{
				cout << "no\n";
			}
		}
	}
    return 0;
}

