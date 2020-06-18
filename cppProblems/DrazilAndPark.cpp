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
typedef pair<ll,int> lli;

const int K=19;

lli st[2][K][200005][2];
lli INF=lli(-1e18,-1);
int d[200005],h[200005];
int n,m;
void upd(lli tar[],lli v){
	if(v.ss==tar[0].ss || v.ss==tar[1].ss)return;
	if(v.ff>tar[0].ff){
		tar[1]=tar[0];
		tar[0]=v;
	}else if(v.ff>tar[1].ff){
		tar[1]=v;
	}
}
ll query(int s, int e){
	int k=31-__builtin_clz(e-s);
	lli res[2][2];
	fore(i,0,2)fore(l,0,2)res[i][l]=st[i][k][s][l];
	fore(i,0,2)fore(l,0,2)upd(res[i],st[i][k][e-(1<<k)][l]);	
	if(res[0][0].ss!=res[1][0].ss)return res[0][0].ff+res[1][0].ff;
	return max(res[0][0].ff+res[1][1].ff,res[0][1].ff+res[1][0].ff);
}
int main(){FIN;
	cin >> n >> m;
	fore(i,0,n)cin >> d[i],d[i+n]=d[i];
	fore(i,0,n)cin >> h[i],h[i+n]=h[i];
	ll acum=0;
	fore(i,0,2*n){
		st[0][0][i][0]=lli(2*h[i]+acum,i);
		st[1][0][i][0]=lli(2*h[i]-acum,i);
		st[0][0][i][1]=st[1][0][i][1]=INF;
		acum+=d[i];
	}
	fore(i,0,2){
		fore(k,1,K){
			fore(j,0,2*n-(1<<k)+1){
				fore(l,0,2)st[i][k][j][l]=st[i][k-1][j][l];
				fore(l,0,2)upd(st[i][k][j],st[i][k-1][j+(1<<(k-1))][l]);
			}
		}
	}
	fore(i,0,m){
		int a,b;
		cin >> a >> b;
		a--,b--;
		int s,e;
		if(a<=b){
			s=b+1;
			e=a+n;
		}else{
			s=b+1;
			e=a;
		}
		cout << query(s,e)<<"\n";
	}
    return 0;
}
