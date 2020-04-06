#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef long long int ll;

int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		ll n,k;
		cin >> n>>k;
		ll left=1;
		ll right=n;
		ll index=-1;
		while(left<=right){
			ll m=(right+left)/2;
			if((m*(m+1))/2>=k){
				index=m;
				right=m-1;	
			}else{
				left=m+1;
			}
		}
		ll kmax=((index+1)*index)/2;
		ll index2=index-1-kmax+k;
		//cout << index << " "<<index2<<"\n";
		vector<char>answer;
		fore(i,0,n){
			if(i==index || i==index2){
				answer.pb('b');
			}else{
				answer.pb('a');
			}
		}
		for(int i=n-1;i>=0;i--){
			if(i==0){
				cout << answer[i] <<"\n";
			}else{
				cout << answer[i];
			}
		}
	}	
    return 0;
}
