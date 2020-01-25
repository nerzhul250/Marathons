#include <bits/stdc++.h>

#include <assert.h>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)
#define PI 3.14159265358979323846
using namespace std;

double const EPS=1e-9;

typedef complex<double> cd;
typedef pair<cd,int> point;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    int N;
    cin >> N;
    vector<point> points;
    fore(i,0,N){
        double x,y;
        int b;
        cin >> x >> y >> b;
        points.pb({{x,y},b});
    }

    double maxLeft1=-1e9,minRight1=1e9,maxLeft2=-1e9,minRight2=1e9;
    fore(i,0,N){fore(j,0,N){
            if(points[j].ss>points[i].ss){
                cd dir=points[j].ff-points[i].ff;
                double ang=arg(dir);
                if(imag(dir)>-EPS){
                    maxLeft1=max(maxLeft1,-EPS);
                    minRight1=min(minRight1,PI-ang+EPS);

                    maxLeft2=max(maxLeft2,-EPS);
                    minRight2=min(minRight2,ang+EPS);
                }else if(imag(dir)<EPS){
                    ang=-ang;
                    maxLeft1=max(maxLeft1,ang-EPS);
                    minRight1=min(minRight1,PI+ang+EPS);

                    maxLeft2=max(maxLeft2,PI-ang-EPS);
                    minRight2=min(minRight2,2*PI-ang+EPS);
                }else{
                    assert(real(dir)>EPS);
                    assert(real(dir)<-EPS);
                    if(real(dir)>-EPS){
                        maxLeft1=max(maxLeft1,-EPS);
                        minRight1=min(minRight1,PI+EPS);

                        maxLeft2=max(maxLeft2,PI-EPS);
                        minRight2=min(minRight2,2*PI+EPS);
                    }else{
                        maxLeft1=max(maxLeft1,PI-EPS);
                        minRight1=min(minRight1,2*PI+EPS);

                        maxLeft2=max(maxLeft2,-EPS);
                        minRight2=min(minRight2,PI+EPS);
                    }
                }
            }
        }
    }
    //ver si originalmente ya estaban ordenados
	int decr=1,incr=1;
	fore(i,0,N) fore(j,0,N){
		if(points[i].ss>points[j].ss&&imag(points[i].ff)<imag(points[j].ff)) decr=0;
		if(points[i].ss>points[j].ss&&imag(points[i].ff)>imag(points[j].ff)) incr=0;
	}
    if(maxLeft1-EPS<=minRight1 || maxLeft2-EPS<=minRight2){
        cout << "Y\n";
    }else{
        if(incr||decr) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}
