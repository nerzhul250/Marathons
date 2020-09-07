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

struct pt {  // for 3D add z coordinate
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
	pt operator*(ll t){return pt(x*t,y*t);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool left(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p)>0;}
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
int main(){FIN;
	ll N;
	cin >> N;
	vector<pt> points(N,pt());
	fore(i,0,N)cin >> points[i].x >> points[i].y;
	ll nonConvex=0;
	fore(i,0,N){
		pt center=points[i];
		//cout << "CENTER: "<<center.x << " "<<center.y <<endl;
		vector<pt> radial;
		fore(j,0,N)if(j!=i)radial.pb(points[j]);
		sort(ALL(radial),Cmp(center));
		int opIndex=0;
		ll outsideTriangles=0;
		fore(j,0,radial.size()){
			while(radial[(opIndex+1)%radial.size()].left(center,radial[j])){
				opIndex++;
				opIndex%=radial.size();
			}
			/*cout << "CurrPoint: "<<points[j].x << " "<<points[j].y<<endl;
			cout << "OpositePoint: "<<points[opIndex].x << " "<<points[opIndex].y<<endl;*/
			ll n=0;
			if(opIndex>=j){
				n=opIndex-j-1;
			}else{
				n=(opIndex+1)+(radial.size()-1-j)-1;
			}
			n=(n*(n+1))/2;
			/*cout <<"Triangles outside of center: "<< n << endl;
			cout << n << endl;*/
			outsideTriangles+=n;
		}
		nonConvex+=(((N-1)*(N-2)*(N-3))/6)-outsideTriangles;
	}
	cout << ((N*(N-1)*(N-2)*(N-3))/24) - nonConvex << "\n";
    return 0;
}
