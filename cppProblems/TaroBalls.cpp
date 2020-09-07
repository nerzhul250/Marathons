#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;

class TaroBalls {
	public:
	string getWinner(int,int);
};

string TaroBalls::getWinner(int R, int B) {
	if(R==B){
		return "Friend";
	}else{
		return "Taro";
	}
}

int main(){FIN;
	int R=1;
	int B=1;
	TaroBalls tb();
	cout << TaroBalls().getWinner(R,B)<<"\n";
}
