#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#define EPS 1e-9


using namespace std;
struct pt {  // for 3D add z coordinate
	double x,y;
	pt(double x, double y):x(x),y(y){}
	pt(){}
	double norm2(){return *this**this;}
	double norm(){return sqrt(norm2());}
	bool operator==(pt p){return abs(x-p.x)<=EPS&&abs(y-p.y)<=EPS;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const {return pt(x-p.x,y-p.y);}
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
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};
pt ccw90(1,0);
pt cw90(-1,0);
struct circle {
	pt o;double r;
	circle(pt o, double r):o(o),r(r){}
	vector<pt> operator^(circle c){ // ccw
		vector<pt> s;
		double d=(o-c.o).norm();
		if(d>r+c.r+EPS||d+min(r,c.r)+EPS<max(r,c.r))return s;
		double x=(d*d-c.r*c.r+r*r)/(2*d);
		double y=sqrt(r*r-x*x);
		pt v=(c.o-o)/d;
		s.pb(o+v*x-v.rot(ccw90)*y);
		if(y>EPS)s.pb(o+v*x+v.rot(ccw90)*y);
		return s;
	}
	bool in(circle c){ // non strict
		double d=(o-c.o).norm();
		return d+r<=c.r+EPS;
	}
};
struct Cmp { // IMPORTANT: add const in pt operator -
	pt r;
	Cmp(pt r):r(r){}
	int cuad(const pt &a)const {
		if(a.x>0&&a.y>=0)return 0;
		if(a.x<=0&&a.y>0)return 1;
		if(a.x<0&&a.y<=0)return 2;
		if(a.x>=0&&a.y<0)return 3;
		assert(a.x==0&&a.y==0);
		return -1;
	}
	bool cmp(const pt& p1, const pt& p2)const {
		int c1=cuad(p1),c2=cuad(p2);
		if(c1==c2)return p1.y*p2.x<p1.x*p2.y;
		return c1<c2;
	}
	bool operator()(const pt& p1, const pt& p2)const {
		return cmp(p1-r,p2-r);
	}
};
vector<double> intercircles(vector<circle> c){
	vector<double> r(SZ(c)+1); // r[k]: area covered by at least k circles
	fore(i,0,SZ(c)){           // O(n^2 log n) (high constant)
		int k=1;Cmp s(c[i].o);
		vector<pair<pt,int> > p={
			{c[i].o+pt(1,0)*c[i].r,0},
			{c[i].o-pt(1,0)*c[i].r,0}};
		fore(j,0,SZ(c))if(j!=i){
			bool b0=c[i].in(c[j]),b1=c[j].in(c[i]);
			if(b0&&(!b1||i<j))k++;
			else if(!b0&&!b1){
				auto v=c[i]^c[j];
				if(SZ(v)==2){
					p.pb({v[0],1});p.pb({v[1],-1});
					if(s(v[1],v[0]))k++;
				}
			}
		}
		sort(p.begin(),p.end(),
			[&](pair<pt,int> a, pair<pt,int> b){return s(a.ff,b.ff);});
		fore(j,0,SZ(p)){
			pt p0=p[j?j-1:SZ(p)-1].ff,p1=p[j].ff;
			double a=(p0-c[i].o).angle(p1-c[i].o);
			r[k]+=(p0.x-p1.x)*(p0.y+p1.y)/2+c[i].r*c[i].r*(a-sin(a))/2;
			k+=p[j].ss;
		}
	}
	return r;
}
double times[105];
pt centers[105];
int main(){FIN;
	int n;
	double limitArea;
	cin >> n >> limitArea;
	fore(i,0,n)cin >> centers[i].x>> centers[i].y >> times[i];	
	int it=100;
	double d1=0,d2=2000000;
	while(it--){
		double dmid=(d1+d2)/2;
		vector<circle> circles;
		fore(i,0,n){
			if(dmid-times[i]>0){
				circles.pb(circle(centers[i],dmid-times[i]));
			}
		}
		double areaUnion=intercircles(circles)[1];
		if(areaUnion<limitArea){
			d1=dmid;
		}else if(areaUnion>=limitArea){
			d2=dmid;
		}
	}
	cout << fixed;
	cout << setprecision(9);
	cout << d1<<"\n";
    return 0;
}
