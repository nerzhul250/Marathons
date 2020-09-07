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
	double a,b,d,R,r,R1,r1,h;
	cin >> a >> b >> d;
	cin >> r >> R;
	cin >> r1 >> R1;
	cin >> h;
	double x,x1;
	x=(R-r)*d/h;
	x1=(R1-r1)*d/h;
	if(d>=h){
		x=R-r;
		x1=R1-r1;
	}
	if(r1+x1>r+x){
		swap(x,x1);
		swap(r,r1);
		swap(R,R1);
	}
	if(a>b)swap(a,b);
	if(r+x+R+R1+r1+x1<=b){
		if(a>=2*(r+x)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}	
	}else{
		if(2*(r+x)>b){
			cout << "NO\n";
		}else{
			double ang=acos((b-r-x-r1-x1)/(R+R1));
			double height=max(2*(r+x),r+x+sin(ang)*(R+R1)+r1+x1);
			if(height<=a){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}
	}
    return 0;
}
