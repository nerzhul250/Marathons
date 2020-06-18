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

int main(){FIN;
	int T;
	cin >> T;
	int org=T;
	while(T--){
		ll x,y;
		cin >> x >> y;
		bool possible=false;
		ll i=-1;
		while(i<=29 && !possible){
			i++;
			ll curx=x,cury=y;
			for(ll j=i;j>=0;j--){
				if(curx<cury && cury>-curx){//up
					cury-=(1<<j);
				}else if(curx<cury && cury<-curx){//left
					curx+=(1<<j);
				}else if(curx>cury && cury<-curx){//down
					cury+=(1<<j);
				}else if(curx>cury && cury>-curx){//right
					curx-=(1<<j);
				}else{
					curx=1;
					break;
				}
			}
			if(curx==0 && cury==0){
				possible=true;
			}
		}
		if(possible){
			ll curx=x,cury=y;
			string ans="";
			for(ll j=i;j>=0;j--){
				if(curx<cury && cury>-curx){//up
					cury-=(1<<j);
					ans+='N';
				}else if(curx<cury && cury<-curx){//left
					curx+=(1<<j);
					ans+='W';
				}else if(curx>cury && cury<-curx){//down
					cury+=(1<<j);
					ans+='S';
				}else if(curx>cury && cury>-curx){//right
					curx-=(1<<j);
					ans+='E';
				}
			}
			reverse(ALL(ans));
			cout << "Case #"<<org-T<<": "<<ans<<"\n";
		}else{
			cout << "Case #"<<org-T<<": IMPOSSIBLE\n";
		}
	}
    return 0;
}

