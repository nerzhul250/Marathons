#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
int exist[1030],arr[1030];
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		fore(i,0,n){
			cin >> arr[i];
			exist[arr[i]]=1;
		}
		int thek=-1;
		fore(k,1,1024){
			bool possible=true;
			fore(i,0,n){
				if(!exist[arr[i]^k]){
					possible=false;
					break;
				}
				exist[arr[i]^k]=0;
			}
			if(possible){
				thek=k;
				break;
			}else{
				fore(i,0,n){
					exist[arr[i]]=1;
				}
			}
		}
		fore(i,0,n){
			exist[arr[i]]=0;
		}
		cout << thek<<"\n";
	}
    return 0;
}
