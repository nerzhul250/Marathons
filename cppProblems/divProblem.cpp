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
	int T;
	cin >> T;
	while(T--){
		int a,b;
		cin >> a >> b;
		int r=a%b;
		if(r==0){
			cout << "0\n";
		}else{
			cout << b-r << "\n";
		}
	}	
    return 0;
}
