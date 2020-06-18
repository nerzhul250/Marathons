#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
int main(){FIN;
	int A,B;
	cin >> A >>B;
	if(A<=B){
		cout << B-A<<"\n";
	}else{
		int cnt=0;
		while(A>B){
			if(A%2==0){
				A/=2;
				cnt++;
			}else{
				A++;
				A/=2;
				cnt+=2;
			}
		}
		cout << cnt+B-A<<"\n";
	}
    return 0;
}
