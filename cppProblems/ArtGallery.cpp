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
	pt unit(){return *this/norm();}
	double operator%(pt p){return x*p.y-y*p.x;}
	// 2D from now on
	bool operator<(pt p)const{ // for convex hull
		return x<p.x-EPS||(abs(x-p.x)<=EPS&&y<p.y-EPS);}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>EPS;}
};


int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
		return r;
	}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	double dist(pt r){return (r-proj(r)).norm();}
};

int sgn(double x){return x<-EPS?-1:x>EPS;}
// CCW order
// Includes collinear points (change sign of EPS in left to exclude)
int getConcavePoint(vector<pt> p){
	vector<pt> orgp=p;
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
	fore(i,0,orgp.size()){
		bool isIn=false;
		//cout << orgp[i].x << " "<<orgp[i].y<<endl;
		fore(j,0,r.size()){
			if(orgp[i]==r[j]){
				isIn=true;
			}
		}
		if(!isIn){
			return i;
		}
	}
	return -1;
}

struct pol {
	int n;vector<pt> p;
	pol(){}
	pol(vector<pt> _p){p=_p;n=p.size();}
	double area(){
		double r=0.;
		fore(i,0,n)r+=p[i]%p[(i+1)%n];
		return abs(r)/2; // negative if CW, positive if CCW
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
	
	pol cut(ln l,pt light,int cpi){   // cut CONVEX polygon by line l
		vector<pt> q;  // returns part at left of l.pq
		int newOne=-1;
		fore(i,0,n){
			int d0=sgn(l.pq%(p[i]-l.p)),d1=sgn(l.pq%(p[(i+1)%n]-l.p));
			q.pb(p[i]);
			ln m(p[i],p[(i+1)%n]);
			if(d0*d1<0&&!(l/m)){
				double det=(((l^m)-light))*(l.pq);
				if(det>0){
					q.pb(l^m);
					newOne=q.size()-1;
				}
			}else if(d0==0&&!(l/m) && i!=cpi){
				double det=(((l^m)-light))*(l.pq);
				if(det>0){
					newOne=i;
				}
			}
		}
		cpi=getConcavePoint(q);
		//cout << cpi << endl;
		//fore(i,0,q.size())cout << q[i].x << " "<<q[i].y<<"\n";
		assert(cpi!=-1);
		if(newOne==-1){
			return pol(q);
		}else{
			vector<pt> q1;
			vector<pt> q2;
			int i=cpi;
			while(i!=newOne){
				q1.pb(q[i]);
				i++;
				i=i%q.size();
			}
			q1.pb(q[newOne]);
			i=newOne;
			while(i!=cpi){
				q2.pb(q[i]);
				i++;
				i=i%q.size();
			}
			q2.pb(q[cpi]);
			pol p1(q1);
			pol p2(q2);
			if(p1.has(light)){
				return p1;
			}else{
				return p2;
			}
		}
	}
};

int main(){FIN;
	int N;
	int t=0;
	cout << fixed;
	cout << setprecision(2);
	while(cin >> N){
		t++;
		if(N==0)break;
		vector<pt> puntos;
		fore(i,0,N){
			double x,y;
			cin >> x>>y;
			puntos.pb(pt(x,y));
		}
		pol polygon(puntos);
		int cpi=getConcavePoint(polygon.p);
		pt concavePoint=polygon.p[cpi];
		int L;
		cin >> L;
		cout << "Gallery #"<<t<<"\n";
		double x,y;
		if(N==1 || N==2){
			fore(l,0,L){
				cin >> x >> y;
				double ans=0;
				cout << ans << "\n";
			}
		}else if(N==3){
			fore(l,0,L){
				cin >> x >> y;
				cout << polygon.area() << "\n";
			}
		}else{
			fore(l,0,L){
				double x,y;
				cin >> x >> y;
				if(cpi==-1){
					cout <<"0\n";
				}else{
					pt light(x,y);
					ln ltc(light,concavePoint);
					pol newPol=polygon.cut(ltc,light,cpi);
					cout << newPol.area()<<"\n";
				}
			}	
		}
	}
    return 0;
}
