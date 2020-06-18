#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
 
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
	double operator%(pt p){return x*p.y-y*p.x;}
	pt unit(){return *this/norm();}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>-EPS;}
};

int sgn2(double x){return x<0?-1:1;}
struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool has(pt r){return dist(r)<=EPS;}
	bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
	bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
	pt operator^(ln l){ // intersection
		if(*this/l)return pt(DINF,DINF);
		pt r=l.p+l.pq*((p-l.p)%pq/(l.pq%pq));
//		if(!has(r)){return pt(NAN,NAN,NAN);} // check only for 3D
		return r;
	}
	pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
	double dist(pt r){return (r-proj(r)).norm();}
};

double area(pt a, pt b, pt c){
	double r=0.;
	r+=a%b;
	r+=b%c;
	r+=c%a;
	return abs(r)/2; // negative if CW, positive if CCW
}
vector<pt> thePoints;
int m;
double dp[110][110];
bool segIntersect(ln seg1,ln seg2){
	if(!(seg1/seg2)){
		pt interPoint=seg1^seg2;
		if(seg1.seghas(interPoint) && seg2.seghas(interPoint)){
			if((seg1.p==interPoint||(seg1.p+seg1.pq)==interPoint) &&
			(seg2.p==interPoint||(seg2.p+seg2.pq)==interPoint)){
				return false;
			}else{
				return true;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}
bool valid(int l, int k, int r){
	bool possible=true;
	fore(i,0,m){
		ln polseg(thePoints[i],thePoints[i+1]);
		possible&=(!segIntersect(polseg,ln(thePoints[l],thePoints[k])));
		possible&=(!segIntersect(polseg,ln(thePoints[k],thePoints[r])));
		possible&=(!segIntersect(polseg,ln(thePoints[r],thePoints[l])));
	}
	return possible;
}

int isEmptyTriangle(pt a, pt b, pt c) {
	for (int i = 0; i < m; i++) {
		if (thePoints[i] == a || thePoints[i] == b || thePoints[i] == c)
			continue;
		if (((thePoints[i]-a)%(b-a))*((thePoints[i]-a)%(c-a))< 0 && 
			((thePoints[i]-b)%(a-b))*((thePoints[i]-b)%(c-b))< 0 &&
			((thePoints[i]-c)%(a-c))*((thePoints[i]-c)%(b-c))< 0)
			return 0;
	}
	return 1;
}

int main(){FIN;
	int n;
	cin >> n;	
	cout << fixed;
	cout << setprecision(1);
	thePoints.assign(110,pt());
	while(n--){
		cin >> m;
		fore(i,0,m){
			double x,y;
			cin >> x >> y;
			thePoints[i]=pt(x,y);
		}
		/*double polygonArea=0;
		fore(i,0,m)polygonArea+=(thePoints[i]%thePoints[(i+1)%m]);
		if(polygonArea<0)reverse(thePoints.begin(),thePoints.begin()+m);*/
		fore(i,0,m)thePoints[i+m]=thePoints[i];
		double minMaxArea=1e18;
		fore(j,0,2*m){
			fore(i,0,2*m){
				dp[j][i]=1e18;
			}
			dp[j][j+1]=0;
		}
		fore(i,2,m){
			fore(j,0,m){
				double &v=dp[j][j+i];
				fore(k,j+1,j+i){
					if(isEmptyTriangle(thePoints[j],thePoints[k],thePoints[j+i])){
							v=min(v,
							max(area(thePoints[j],thePoints[k],thePoints[j+i]),
							max(dp[j][k],dp[k][j+i])));
					}
				}
				if(i==m-1)minMaxArea=min(minMaxArea,dp[j][j+i]);
			}
		}
		cout << minMaxArea<<"\n";
	}
    return 0;
}
