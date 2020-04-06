#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int score[55];
double acumScore[55];
double individualScore[55];
int main(){FIN;
	int n;
	cin >> n;
	fore(i,0,n)cin >> score[i];
	double ratio=1;
	acumScore[0]=score[0]/5.0;
	individualScore[0]=score[0]/5.0;
	fore(i,1,n){
		ratio*=(4/5.0);
		individualScore[i]=ratio*score[i]/5.0;
		acumScore[i]+=acumScore[i-1]+ratio*score[i]/5.0;
	}
	
	cout << fixed;
	cout << setprecision(9);
	
	cout << acumScore[n-1] << "\n";
	double ans=0;
	ratio=4/5.0;
	fore(i,0,n){
		ans+=((i?acumScore[i-1]:0)+((acumScore[n-1]-acumScore[i])/ratio))/n;
	}
	cout << ans << "\n";
    return 0;
}

