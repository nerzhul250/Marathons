#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<double,double> dd;
double T[100005],S[100005],A[100005];
int main(){FIN;
	int N;
	cin >>N;
	fore(i,0,N){
		cin >> T[i]>>S[i]>>A[i];
	}
	double cur=0;
	double PI=acos(-1);
	vector<dd> stars;
	fore(i,0,N){
		if(S[i]!=0 && T[i]/S[i]<PI){
			stars.pb({A[i]-(T[i]/S[i]),S[i]});
			stars.pb({A[i],-2*S[i]});
			stars.pb({A[i]+(T[i]/S[i]),S[i]});
			
			stars.pb({A[i]-(T[i]/S[i])+2*PI,S[i]});
			stars.pb({A[i]+2*PI,-2*S[i]});
			stars.pb({A[i]+(T[i]/S[i])+2*PI,S[i]});
		}else if(S[i]==0){
			cur+=T[i];
		}else{
			cur+=T[i]-PI*S[i];
			stars.pb({A[i]-PI,S[i]});
			stars.pb({A[i],-2*S[i]});
			
			stars.pb({A[i]+PI,2*S[i]});
			stars.pb({A[i]+2*PI,-2*S[i]});
		}
	}
	sort(ALL(stars));
	double slope=0;
	double best=cur;
	double lastAngle=stars[0].ff;
	fore(i,0,stars.size()){
		double deltaAngle=stars[i].ff-lastAngle;
		lastAngle=stars[i].ff;
		cur+=deltaAngle*slope;
		slope+=stars[i].ss;
		best=max(best,cur);
	}
	cout << setprecision(6);
	cout << fixed;
	cout << best<<"\n";
    return 0;
}
