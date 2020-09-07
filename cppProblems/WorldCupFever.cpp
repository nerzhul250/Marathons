#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef pair<int,int> ii;
const int INF=1e9;
struct pt {  // for 3D add z coordinate
	int x,y;
	pt(int x, int y):x(x),y(y){}
	pt(){}
	int norm2(){return *this**this;}
	bool operator==(pt p){return x-p.x==0 && y-p.y==0;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p)const{return pt(x-p.x,y-p.y);}
	pt operator*(int t){return pt(x*t,y*t);}
	pt operator/(int t){return pt(x/t,y/t);}
	int operator*(pt p){return x*p.x+y*p.y;}
	int operator%(pt p){return x*p.y-y*p.x;}
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
int n;
pt player[25];
vector<int> valid[25];
int bfs(int u){
	queue<ii> q;
	vector<int> visited(2*n,0);
	visited[u]=1;
	q.push(ii(u,0));
	while(!q.empty()){
		ii v=q.front();
		q.pop();
		if(v.ff==n-1){
			return v.ss;
		}
		for(int x:valid[v.ff]){
			if(!visited[x]){
				visited[x]=1;
				q.push(ii(x,v.ss+1));				
			}
		}
	}
	return -1;
}
int main(){FIN;
	cin >> n;
	fore(i,0,n*2)cin >> player[i].x >> player[i].y;
	fore(i,0,2*n){
		map<pt,ii,Cmp> mp(Cmp(player[i]));
		fore(j,0,2*n){
			if(i!=j){
				if(mp.count(player[j])){
					int currDis=mp[player[j]].ff;
					if((player[j]-player[i]).norm2()<currDis){
						mp[player[j]]=ii((player[j]-player[i]).norm2(),j);
					}
				}else{
					mp[player[j]]=ii((player[j]-player[i]).norm2(),j);
				}
			}
		}
		for(auto it=mp.begin();it!=mp.end();it++){
			ii ideal=it->ss;
			int index1=ideal.ss;
			if((i<n && index1<n) || (i>=n && index1>=n)){
				valid[i].pb(index1);
			}
		}
	}
	cout << bfs(0)<<"\n";
    return 0;
}
