#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
typedef long long int ll;
int main(){FIN;
	double AD,AC,BD,BC;
	cin >> AD >> AC >> BD >> BC;
	double k=(AD*AC)/(BD*BC);
	double k2=(AD*AD+AC*AC)/(BD*BD+BC*BC);
	double mult=BD*BD+BC*BC;
	if(BD*BC==AD*AC){
		cout << "Impossible.\n";
	}else{
		double part2=((k2-k)/(1-k));
		if((mult<0 && part2>0) || (mult>0 && part2<0)){
			cout << "Impossible.\n";
		}else{
			mult=sqrt(abs(mult));
			part2=sqrt(abs(part2));
			//printf("Distance is %.0lf km.\n",mult*part2*1000);
			cout << "Distance is "<<((ll)round(mult*part2*1000))<<" km.\n";
		}
	}
    return 0;
}
