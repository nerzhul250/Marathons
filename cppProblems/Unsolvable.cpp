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
const ll MOD=7+1e9;
ll mersenne[40]={2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607,
	1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243,
	110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011};
int main(){FIN;
	int n;
	cin >>n;
	n--;
	ll pow=1;
	fore(i,0,mersenne[n]-1){
		pow*=2;
		pow%=MOD;
	}
	pow--;
	pow+=MOD;
	pow%=MOD;
	cout << pow << "\n";
    return 0;
}
