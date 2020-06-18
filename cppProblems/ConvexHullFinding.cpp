#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
const double EPS=1e-9;
struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(double t){return pt(x*t,y*t);}
	pt operator/(double t){return pt(x/t,y/t);}
	double operator*(pt p){return x*p.x+y*p.y;}
//	pt operator^(pt p){ // only for 3D
//		return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
	double angle(pt p){ // redefine acos for values out of range
		return acos(*this*p/(norm()*p.norm()));}
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>-EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);

// CCW order
// Includes collinear points (change sign of EPS in left to exclude)
vector<pt> chull(vector<pt> p){
	if(SZ(p)<3)return p;
	vector<pt> r;
	sort(p.begin(),p.end()); // first x, then y
	fore(i,0,p.size()){ // lower hull
		while(r.size()>=2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	int k=r.size();
	for(int i=p.size()-1;i>=0;--i){ // upper hull
		while(r.size()>=k+2&&r.back().left(r[r.size()-2],p[i]))r.pop_back();
		r.pb(p[i]);
	}
	r.pop_back();
	return r;
}
int main(){FIN;
	int t;
	cin >> t;
	cout << t<<"\n";
	while(t--){
		int n;
		cin >> n;
		vector<pt> p;
		fore(i,0,n){
			int a,b;
			cin >> a>>b;
			double x=a,y=b;
			if(i!=n-1){
				p.pb(pt(x,y));
			}
		}
		vector<pt> r=chull(p);
		cout << r.size()+1 << "\n";
		int index=-1;
		double valy=1e9;
		double valx=1e9;
		fore(i,0,r.size()){
			if(r[i].y<valy){
				valy=r[i].y;
				valx=r[i].x;
				index=i;
			}else if(r[i].y==valy && r[i].x<valx){
				valy=r[i].y;
				valx=r[i].x;
				index=i;
			}
		}
		fore(i,0,r.size()){
			cout << (int)r[(i+index)%SZ(r)].x << " "<<(int)r[(i+index)%SZ(r)].y<<"\n";
		}
		cout << (int)r[index].x << " "<<(int)r[index].y<<"\n";
		int basura;
		if(t!=0){
			cin >> basura;
			cout << basura << "\n";
		}
	}
    return 0;
}

