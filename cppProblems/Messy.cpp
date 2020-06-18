#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,int> ii;
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int k,n;
		cin >> n >> k;
		char arr[n];
		fore(i,0,n){
			cin >> arr[i];
		}
		vector<ii> opers;
		fore(i,0,n){
			if(i%2==0){
				if(arr[i]!='('){
					fore(j,i+1,n){
						if(arr[j]=='('){
							opers.pb(ii(i+1,j+1));
							reverse(arr+i,arr+j+1);
							break;
						}
					}
				}
			}else{
				if(arr[i]!=')'){
					fore(j,i+1,n){
						if(arr[j]==')'){
							opers.pb(ii(i+1,j+1));
							reverse(arr+i,arr+j+1);
							break;
						}
					}
				}
			}
		}
		int currK=n/2;
		int left=1;
		int right=2;
		while(currK>k){
			opers.pb(ii(left+1,right+1));
			reverse(arr+left,arr+right+1);
			currK--;
			while(arr[left]!=')'){
				left++;
			}
			while(arr[right]!='('){
				right++;
			}
		}
		cout << opers.size() << "\n";
		for(ii oper:opers){
			cout << oper.ff << " "<<oper.ss << "\n";
		}
	}
    return 0;
}
