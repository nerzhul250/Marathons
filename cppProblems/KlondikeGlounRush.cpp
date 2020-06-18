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
int main(){FIN;
	int N,M;
	cin >> N >> M;
	fore(i,0,N)cin >> arr[i];
	int minTransforms=1e8;
	fore(i,1,M+1){
		int transforms=0;
		int prev=-1;
		fore(j,0,N){
			if(arr[j]!=prev){
				prev=arr[j];
				if(prev!=i){
					transforms++;
				}
			}
		}
		minTransforms=min(minTransforms,transforms);
	}
	cout << minTransforms<<"\n";
    return 0;
}
