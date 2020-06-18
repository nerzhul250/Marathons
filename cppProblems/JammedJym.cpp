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

int eType[105],mType[105];
dd coord[105];
int n,m;
//maquinaActual,ejercicioActual
int dpPos[105][105];
double dp[105][105];
double minDis(int ma,int ej){
	int &rpos=dpPos[ma][ej];
	double &r=dp[ma][ej];
	if(rpos)return r;
	if(ej==n)return 0;
	double minimo=1000;
	fore(i,1,m+1){
		if(eType[ej]==mType[i]){
			minimo=min(minimo,minDis(i,ej+1)+hypot(coord[ma].ff-coord[i].ff,coord[ma].ss-coord[i].ss));
		}
	}
	rpos=1;
	r=minimo;
	return r;
}
int main(){FIN;
	cin >> n;
	fore(i,0,n)cin >> eType[i];
	cin >> m;
	coord[0].ff=0;
	coord[0].ss=0;
	double angle=acos(-1)/2;
	double delta=2*acos(-1)/m;
	fore(i,1,m+1){
		cin >> mType[i];
		coord[i].ff=cos(angle);
		coord[i].ss=sin(angle);
		angle-=delta;
	}
	cout << setprecision(9);
	cout << fixed;
	
	cout << minDis(0,0)<<"\n";
    return 0;
}
