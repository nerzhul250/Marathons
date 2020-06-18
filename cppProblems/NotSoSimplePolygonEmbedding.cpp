#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef complex<double> cc;
cc height,rightV,leftV;
double f(double m){
	return max(imag(height*polar(1.0,m)),real(rightV*polar(1.0,m))-real(leftV*polar(1.0,m)));
}
int main(){FIN;	
	cout << fixed;
	cout << setprecision(10);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >>n;
		double rotAngle=acos(-1)/n;
		cc delta=polar(1.0,rotAngle);
		
		leftV=polar(1.0,0.0);
		rightV=polar(1.0,0.0);
		height=polar(1.0,0.0);
		cc toSum=delta;
		fore(i,0,n-1){
			height+=toSum;
			toSum*=delta;
		}
		toSum=delta;
		fore(i,0,n/2){
			rightV+=toSum;
			toSum*=delta;
		}
		toSum=delta;
		fore(i,0,n+n/2){
			leftV+=toSum;
			toSum*=delta;
		}
		double l=0;
		double r=rotAngle/2;
		double eps = 1e-9;              //set the error limit here
		while (r - l > eps) {
			double m1 = l + (r - l) / 3;
			double m2 = r - (r - l) / 3;
			double f1 = f(m1);      //evaluates the function at m1
			double f2 = f(m2);      //evaluates the function at m2
			if (f1 > f2){
				l=m1;
			}else{
				r=m2;
			}
		}
		cout << f(l)<<"\n";
	}
    return 0;
}

