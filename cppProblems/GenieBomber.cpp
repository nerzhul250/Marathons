#include <bits/stdc++.h>
#include <complex>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef complex<double> cd;
typedef pair<double,int> di;
int N;
double R,r;
cd points[105];
bool cmp(const di &a,const di &b){
	if(a.ff!=b.ff){
		return a.ff<b.ff;
	}else{
		return a.ss>b.ss;
	}
}
int main(){FIN;
	cin >> N;
	fore(i,0,N){
		double x,y;
		cin >> x>>y;
		points[i]=cd(x,y);
	}
	cin >> R >> r;
	if(R<r){
		cout << "0\n";
	}else{
		double PI=acos(-1);
		int maximum=1;
		//for each point, put a circle on its boundary, rotate circle,
		//register events when new circles enter or leave
		fore(i,0,N){
			cd P=points[i];
			vector<di> events;
			fore(j,0,N){
				if(i!=j && abs(P-points[j])+2*r<=2*R){
					cd Q=points[j];
					double A=arg(Q-P);
					double B=acos((abs(Q-P))/(2*(R-r)));//because of cosine law
					events.pb({A-B,1});
					events.pb({A+B,-1});
					events.pb({A-B+2*PI,1});
					events.pb({A+B+2*PI,-1});
				}
			}
			sort(ALL(events),cmp);
			int cnt=1;
			fore(j,0,events.size()){
				cnt+=events[j].ss;
				maximum=max(maximum,cnt);
			}
		}
		cout << maximum<<"\n";
	}
    return 0;
}
