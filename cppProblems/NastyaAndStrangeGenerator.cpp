#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int per[100005];
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		fore(i,1,n+1){
			int num;
			cin >> num;
			per[num]=i;
		}
		int lastIndex=n;
		int firstIndex=per[1];
		bool possible=true;
		fore(i,1,n+1){
			if(per[i]==lastIndex){
				lastIndex=firstIndex-1;
				firstIndex=per[i+1];
			}else{
				if(per[i]+1!=per[i+1]){
					possible=false;
					break;
				}
			}
		}
		if(possible){
			cout << "Yes\n";
		}else{
			cout << "No\n";
		}
	}
    return 0;
}
