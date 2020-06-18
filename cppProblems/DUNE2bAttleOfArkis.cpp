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
ll table[1005][1005];
ll xs[1005],ys[1005];
ll sumx[1005],sumy[1005];
int main(){FIN;
	int n,m,Q;
	cin >> n >> m >>Q;
	fore(i,0,n){
		fore(j,0,m){
			cin >> table[i][j];
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			xs[i]+=table[i][j];
		}
	}
	fore(j,0,m){
		fore(i,0,n){
			ys[j]+=table[i][j];
		}
	}
	fore(i,0,n){
		fore(j,0,n){
			sumx[i]+=abs(i-j)*xs[j];
		}
	}
	fore(j,0,m){
		fore(i,0,m){
			sumy[j]+=abs(j-i)*ys[i];
		}
	}
	ll minx=1e18;
	ll miny=1e18;
	fore(i,0,n){
		if(sumx[i]<minx){
			minx=sumx[i];
		}
	}
	fore(j,0,m){
		if(sumy[j]<miny){
			miny=sumy[j];
		}
	}
	cout << minx+miny << " ";
	fore(q,0,Q){
		int x,y,z;
		cin >> x >> y >>z;
		x--;
		y--;
		ll tmpxs=xs[x];
		ll tmpys=ys[y];
		xs[x]-=table[x][y];
		xs[x]+=z;
		ys[y]-=table[x][y];
		ys[y]+=z;
		table[x][y]=z;
		minx=1e18;
		miny=1e18;
		fore(i,0,n){
			sumx[i]-=abs(i-x)*tmpxs;
			sumx[i]+=abs(i-x)*xs[x];
			if(sumx[i]<minx){
				minx=sumx[i];
			}
		}
		fore(j,0,m){
			sumy[j]-=abs(j-y)*tmpys;
			sumy[j]+=abs(j-y)*ys[y];
			if(sumy[j]<miny){
				miny=sumy[j];
			}
		}
		if(q==Q-1)cout << miny+minx<<"\n";
		else cout << miny+minx<<" ";
	}
    return 0;
}
