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
const double EPS=1e-9;
const double PI=acos(-1);
struct pt{
	double x,y,z;
	pt(double x, double y,double z):x(x),y(y),z(z){}
	pt(){}
	double norm2(){return x*x+y*y+z*z;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS&&abs(z-p.z)<=EPS;}
	pt operator/(double t){return pt(x/t,y/t,z/t);}
	pt operator+(pt p){return pt(x+p.x,y+p.y,z+p.z);}
	pt operator-(pt p){return pt(x-p.x,y-p.y,z-p.z);}
	pt operator*(double t){return pt(x*t,y*t,z*t);}
	double operator*(pt p){return x*p.x+y*p.y+z*p.z;}
	pt operator%(pt p){return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	pt unit(){return *this/norm();}
};
pt beacon[5];
int main(){FIN;
	ll x0,y0,z0;
	cin >> x0 >> y0 >> z0;
	ll R;
	cin >> R;
	fore(i,0,3){
		int lat,lon;
		cin >> lat >> lon;
		double d=lat*(PI/180.0);
		double l=lon*(PI/180.0);
		beacon[i]=pt(R*cos(d)*cos(l),R*cos(d)*sin(l),R*sin(d));
	}
	ll x1,y1,z1;
	cin >> x1 >> y1 >> z1;
	x1-=x0;
	y1-=y0;
	z1-=z0;
	pt spaceship(x1,y1,z1);
	ll vx,vy,vz;
	cin >> vx >> vy >> vz;
	pt velocity(vx,vy,vz);
	ll a=vx*vx+vy*vy+vz*vz;
	ll b=2*(vx*x1+vy*y1+vz*z1);
	ll c=x1*x1+y1*y1+z1*z1-R*R;
	ll det=b*b-4*a*c;
	if(det<0 || a==0){
		cout << "NO\n";
	}else{
		double t1=(-b/(2*a+0.0))-(sqrt(det)/(2*a+0.0));
		double t2=(-b/(2*a+0.0))+(sqrt(det)/(2*a+0.0));
		double t=min(t1,t2);
		if(det==0)t=(-b/(2*a+0.0));
		if(t>0){
			pt inter=(velocity*t)+spaceship;
			bool outside=(((beacon[0]%beacon[1])*inter)*((beacon[0]%beacon[1])*beacon[2])<-EPS) ||
						(((beacon[0]%beacon[2])*inter)*((beacon[0]%beacon[2])*beacon[1])<-EPS) ||
						(((beacon[1]%beacon[2])*inter)*((beacon[1]%beacon[2])*beacon[0])<-EPS);
			if(!outside){
				cout << "YES\n";
			}else{
				cout << "NO\n";
			}
		}else{
			cout << "NO\n";
		}
	}
	return 0;
}
