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
	int N;
	cin >> N;
	if(N==1){
		cout << "89\n";
		cout << "98\n";
	}else if(N==2){
		cout << "9899\n";
		cout << "9998\n";
	}else if(N==3){
		cout << "998999\n";
		cout << "999998\n";
	}else if(N==4){
		cout << "99989999\n";
		cout << "99999998\n";
	}else if(N==5){
		cout << "9999899999\n";
		cout << "9999999998\n";
	}else if(N==6){
		cout << "999998999999\n";
		cout << "999999999998\n";
	}else if(N==7){
		cout << "99999989999999\n";
		cout << "99999999999998\n";
	}else if(N==8){
		cout << "9999999899999999\n";
		cout << "9999999999999998\n";
	}else if(N==9){
		cout << "999999998999999999\n";
		cout << "999999999999999998\n";
	}else if(N==10){
		cout << "99999999989999999999\n";
		cout << "99999999999999999998\n";
	}
    return 0;
}
