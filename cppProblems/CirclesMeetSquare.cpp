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
const double DINF=1e18;
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
		return (q-p)%(*this-p)>EPS;}
	pt rot(pt r){return pt(*this%r,*this*r);}
	pt rot(double a){return rot(pt(sin(a),cos(a)));}
};

int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
//	bool operator /(ln l){return (pq.unit()^l.pq.unit()).norm()<=EPS;} // 3D
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	double angle(ln l){return pq.angle(l.pq);}
	int side(pt r){return has(r)?0:sgn2(pq%(r-p));} // 2D
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	pt ref(pt r){return proj(r)*2-r;}
	double dist(pt r){return (r-proj(r)).norm();}
//	double dist(ln l){ // only 3D
//		if(*this/l)return dist(l.p);
//		return abs((l.p-p)*(pq^l.pq))/(pq^l.pq).norm();
//	}
	ln rot(auto a){return ln(p,p+pq.rot(a));} // 2D
};

struct circle {
	pt o;double r;
	circle(pt o, double r):o(o),r(r){}
	bool has(pt p){return (o-p).norm()<=r+EPS;}
	vector<pt> operator^(ln l){
		vector<pt> s;
		pt p=l.proj(o);
		double d=(p-o).norm();
		if(d-EPS>r)return s;
		if(abs(d-r)<=EPS){s.pb(p);return s;}
		d=sqrt(r*r-d*d);
		s.pb(p+l.pq.unit()*d);
		s.pb(p-l.pq.unit()*d);
		return s;
	}
	bool in(circle c){ // non strict
		double d=(o-c.o).norm();
		return d+r<=c.r+EPS;
	}
	double intertriangle(pt a, pt b){ // area of intersection with oab
		if(abs((o-a)%(o-b))<=EPS)return 0.;
		vector<pt> q={a},w=*this^ln(a,b);
		if(w.size()==2)for(auto p:w)if((a-p)*(b-p)<-EPS)q.pb(p);
		q.pb(b);
		if(q.size()==4&&(q[0]-q[1])*(q[2]-q[1])>EPS)swap(q[1],q[2]);
		double s=0;
		fore(i,0,q.size()-1){
			if(!has(q[i])||!has(q[i+1]))s+=r*r*(q[i]-o).angle(q[i+1]-o)/2;
			else s+=abs((q[i]-o)%(q[i+1]-o)/2);
		}
		return s;
	}
};
int sgn(double x){return x<-EPS?-1:x>EPS;}
struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	double area(){
		double r=0.;
		fore(i,0,n)r+=p[i]%p[(i+1)%n];
		return abs(r)/2; // negative if CW, positive if CCW
	}
	pt centroid(){ // (barycenter)
		pt r(0,0);double t=0;
		fore(i,0,n){
			r=r+(p[i]+p[(i+1)%n])*(p[i]%p[(i+1)%n]);
			t+=p[i]%p[(i+1)%n];
		}
		return r/t/3;
	}
	bool has(pt q){ // O(n)
		fore(i,0,n)if(ln(p[i],p[(i+1)%n]).seghas(q))return true;
		int cnt=0;
		fore(i,0,n){
			int j=(i+1)%n;
			int k=sgn((q-p[j])%(p[i]-p[j]));
			int u=sgn(p[i].y-q.y),v=sgn(p[j].y-q.y);
			if(k>0&&u<0&&v>=0)cnt++;
			if(k<0&&v<0&&u>=0)cnt--;
		}
		return cnt!=0;
	}
	void normalize(){ // (call before haslog, remove collinear first)
		if(p[2].left(p[0],p[1]))reverse(p.begin(),p.end());
		int pi=min_element(p.begin(),p.end())-p.begin();
		vector<pt> s(n);
		fore(i,0,n)s[i]=p[(pi+i)%n];
		p.swap(s);
	}
	bool haslog(pt q){ // O(log(n)) only CONVEX. Call normalize first
		if(q.left(p[0],p[1])||q.left(p.back(),p[0]))return false;
		int a=1,b=p.size()-1;  // returns true if point on boundary
		while(b-a>1){          // (change sign of EPS in left
			int c=(a+b)/2;       //  to return false in such case)
			if(!q.left(p[0],p[c]))a=c;
			else b=c;
		}
		return !q.left(p[a],p[a+1]);
	}
	pt farthest(pt v){ // O(log(n)) only CONVEX
		if(n<10){
			int k=0;
			fore(i,1,n)if(v*(p[i]-p[k])>EPS)k=i;
			return p[k];
		}
		if(n==SZ(p))p.pb(p[0]);
		pt a=p[1]-p[0];
		int s=0,e=n,ua=v*a>EPS;
		if(!ua&&v*(p[n-1]-p[0])<=EPS)return p[0];
		while(1){
			int m=(s+e)/2;pt c=p[m+1]-p[m];
			int uc=v*c>EPS;
			if(!uc&&v*(p[m-1]-p[m])<=EPS)return p[m];
			if(ua&&(!uc||v*(p[s]-p[m])>EPS))e=m;
			else if(ua||uc||v*(p[s]-p[m])>=-EPS)s=m,a=c,ua=uc;
			else e=m;
			assert(e>s+1);
		}
	}
	pol cut(ln l){   // cut CONVEX polygon by line l
		vector<pt> q;  // returns part at left of l.pq
		fore(i,0,n){
			int d0=sgn(l.pq%(p[i]-l.p)),d1=sgn(l.pq%(p[(i+1)%n]-l.p));
			if(d0>=0)q.pb(p[i]);
			ln m(p[i],p[(i+1)%n]);
			if(d0*d1<0&&!(l/m))q.pb(l^m);
		}
		return pol(q);
	}
	double intercircle(circle c){ // area of intersection with circle
		double r=0.;
		fore(i,0,n){
			int j=(i+1)%n;double w=c.intertriangle(p[i],p[j]);
			if((p[j]-c.o)%(p[i]-c.o)>0)r+=w;
			else r-=w;
		}
		return abs(r);
	}
	double callipers(){ // square distance of most distant points
		double r=0;     // prereq: convex, ccw, NO COLLINEAR POINTS
		for(int i=0,j=n<2?0:1;i<j;++i){
			for(;;j=(j+1)%n){
				r=max(r,(p[i]-p[j]).norm2());
				if((p[(i+1)%n]-p[i])%(p[(j+1)%n]-p[j])<=EPS)break;
			}
		}
		return r;
	}
     vector<pt> intersectionsCircle(circle c){
		vector<pt> ans;
		fore(i,0,n){
			int j=(i+1)%n;
			ln line(p[i],p[j]);
			vector<pt> inters=c^line;
			for(pt x:inters){
				if(line.seghas(x)){
					ans.pb(x);
				}
			}
		}
		return ans;
	}
};

int main(){FIN;
	double x,y,r;
	cin >> x >> y >> r;
	circle cir(pt(x,y),r);
	double tx,ty,s;
	cin >> tx >> ty >> s;
	vector<pt> points;
	points.pb(pt(tx,ty));
	points.pb(pt(tx+s,ty));
	points.pb(pt(tx+s,ty+s));
	points.pb(pt(tx,ty+s));
	pol square(points);
	if(square.has(cir.o) || 
	(cir.has(square.p[0]) && cir.has(square.p[1]) && cir.has(square.p[2]) && cir.has(square.p[3]))){
		cout << "2\n";
	}else{
		vector<pt> ans;
		fore(i,0,4){
			if(cir.has(square.p[i])){
				ans.pb(square.p[i]);
			}
		}
		vector<pt> inters=square.intersectionsCircle(cir);
		for(pt x:inters){
			bool rep=false;
			for(pt y:ans){
				if(x==y){
					rep=true;
					break;
				}
			}
			if(!rep){
				ans.pb(x);
			}
		}
		if(ans.size()>=2){
			cout << "2\n";
		}else{
			cout << ans.size() << "\n";
		}
	}
    return 0;
}
