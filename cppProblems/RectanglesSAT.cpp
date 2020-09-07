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
typedef pair<ll,ll> ii;
struct pt {  // for 3D add z coordinate
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	bool operator==(pt p){return (x==p.x)&&(y==p.y);}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ll t){return pt(x*t,y*t);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll operator%(pt p){return x*p.y-y*p.x;}
	ll orient(pt p, pt q){ // is it to the left of directed line pq?
		return (q-p)%(*this-p);}
};
typedef pair<pt,pt> seg;
bool intersect(seg sg1,seg sg2){
	ll o1=sg1.ff.orient(sg2.ff,sg2.ss);
	ll o2=sg1.ss.orient(sg2.ff,sg2.ss);
	if(o1==0 && o2==0){
		return max(min(sg1.ff.x,sg1.ss.x),min(sg2.ff.x,sg2.ss.x))<=min(max(sg1.ff.x,sg1.ss.x),max(sg2.ff.x,sg2.ss.x)) &&
			   max(min(sg1.ff.y,sg1.ss.y),min(sg2.ff.y,sg2.ss.y))<=min(max(sg1.ff.y,sg1.ss.y),max(sg2.ff.y,sg2.ss.y));
	}
	bool one=false;
	if(o1==0 || o2==0){
		one=true;
	}else{
		one=(o1<0 && o2>0)||(o2<0 && o1>0);
	}
	ll o3=sg2.ff.orient(sg1.ff,sg1.ss);
	ll o4=sg2.ss.orient(sg1.ff,sg1.ss);
	bool two=false;
	if(o3==0 || o4==0){
		two=true;
	}else{
		two=(o3<0 && o4>0)||(o4<0 && o3>0);
	}
	return one && two;
}
const int MAXN=4005;
// MAXN: max number of nodes or 2 * max number of variables (2SAT)
bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,MAXN)if(!idx[i])tjn(i);
}
// Only for 2SAT:
void addcon(int a,int b){g[a].pb(b);g[neg(b)].pb(neg(a));}
bool satisf(int _nvar){
	nvar=_nvar;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}
int main(){FIN;
	int n;
	cin >> n;
	while(n){
		vector<seg> segments;
		fore(i,0,n){
			vector<ii> points;
			fore(j,0,4){
				ii point;
				cin >> point.ff >> point.ss;
				points.pb(point);
			}
			sort(ALL(points));
			segments.pb({pt(points[0].ff,points[0].ss),pt(points[3].ff,points[3].ss)});
			segments.pb({pt(points[1].ff,points[1].ss),pt(points[2].ff,points[2].ss)});	
		}
		fore(i,0,MAXN)g[i].clear();
		fore(i,0,segments.size()-1){
			fore(j,i+1,segments.size()){
				if(i%2==0 && j==i+1){
					addcon(i,neg(j));
					addcon(neg(j),i);
				}else if(intersect(segments[i],segments[j])){
					addcon(i,neg(j));
				}
			}
		}
		if(satisf(2*n)){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
		cin >> n;
	}	
    return 0;
}
