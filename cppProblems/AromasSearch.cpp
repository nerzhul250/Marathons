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

ll xo,yo,ax,ay,bx,by,xs,ys,t;

ll nextX(ll x){
	return x*ax+bx;
}
ll nextY(ll y){
	return y*ay+by;
}
ll prevX(ll x){
	return (x-bx)/ax;
}
ll prevY(ll y){
	return (y-by)/ay;
}

int main(){FIN;
	cin >> xo >> yo >> ax >> ay >> bx >> by >> xs >> ys >> t;
	ll curx=xo,cury=yo;
	ll maxAns=0;
	while(!(curx>=xs && cury>=ys && curx-xs+cury-ys>t)){
		ll remTime=t;
		ll px=xs,py=ys,cx=curx,cy=cury;
		ll ans=0;
		while(!(px==xo && py==yo) && abs(cx-px)+abs(cy-py)<=remTime){
			ans++;
			remTime-=(abs(cx-px)+abs(cy-py));
			px=cx;
			py=cy;
			cx=prevX(cx);
			cy=prevY(cy);
		}
		maxAns=max(maxAns,ans);
		
		remTime=t;
		px=xs,py=ys,cx=curx,cy=cury;
		ans=0;
		while(abs(cx-px)+abs(cy-py)<=remTime){
			ans++;
			remTime-=(abs(cx-px)+abs(cy-py));
			px=cx;
			py=cy;
			cx=nextX(cx);
			cy=nextY(cy);
		}
		maxAns=max(maxAns,ans);		
		
		curx=nextX(curx);
		cury=nextY(cury);
	}
	cout << maxAns<<"\n";
    return 0;
}
