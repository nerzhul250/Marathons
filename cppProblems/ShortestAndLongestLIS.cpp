#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
char symbols[200005];
int arr[200005];
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		fore(i,0,n-1)cin >> symbols[i];
		//minLIS
		fore(i,0,n)arr[i]=n-i;
		int lastIndex=0;
		fore(i,1,n){
			if(i==n-1||symbols[i-1]!=symbols[i]){
				if(symbols[i-1]=='<'){
					reverse(arr+lastIndex,arr+i+1);
				}
				lastIndex=i;
			}
		}
		fore(i,0,n){
			if(i==n-1){
				cout << arr[i]<<"\n";
			}else{
				cout << arr[i]<<" ";
			}
		}
		//maxLIS
		fore(i,0,n)arr[i]=i+1;
		lastIndex=0;
		fore(i,1,n){
			if(i==n-1 || symbols[i-1]!=symbols[i]){
				if(symbols[i-1]=='>'){
					reverse(arr+lastIndex,arr+i+1);
				}
				lastIndex=i;
			}
		}
		fore(i,0,n){
			if(i==n-1){
				cout << arr[i]<<"\n";
			}else{
				cout << arr[i]<<" ";
			}
		}
	}
    return 0;
}

