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
		cin >> n;
		fore(i,0,n)cin>>arr[i];
		sort(begin(arr),begin(arr)+n);
		int minimo=1e8;
		int index1=-1;
		int index2=-1;
		fore(i,0,n){
			fore(j,i+1,n){
				if(minimo>abs(arr[i]-arr[j])){
					minimo=abs(arr[i]-arr[j]);
					index1=i;
					index2=j;
				}
			}
		}
		cout <<minimo<<"\n";
	}
    return 0;
}
