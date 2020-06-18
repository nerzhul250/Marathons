#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int arr[100005],brr[100005],poss[100005];
int main(){FIN;
	int t;
	cin >>  t;
	while(t--){
		int n;
		cin >> n;
		fore(i,0,n)cin >> arr[i];
		fore(i,0,n)cin >> brr[i];
		bool ones=false;
		bool minusOne=false;
		fore(i,0,n){
			if(ones && minusOne){
				poss[i]=3;
			}else if(ones){
				poss[i]=1;
			}else if(minusOne){
				poss[i]=2;
			}else{
				poss[i]=0;
			}
			if(arr[i]==1){
				ones=true;
			}else if(arr[i]==-1){
				minusOne=true;
			}
		}
		bool possible=true;
		fore(i,0,n){
			if(brr[i]<arr[i]){
				possible&=(poss[i]==3 || poss[i]==2);
			}else if(brr[i]>arr[i]){
				possible&=(poss[i]==3 || poss[i]==1);
			}
		}
		if(possible){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
    return 0;
}

