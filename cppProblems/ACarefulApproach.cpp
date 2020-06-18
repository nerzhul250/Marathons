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
int main(){FIN;
	int n;
	int t=0;
	while(cin >> n){
		t++;
		if(n==0)break;
		ii intervals[10];
		fore(i,0,n){
			int a,b;
			cin >> a >> b;
			intervals[i]=ii(a,b);
		}
		int it=100;
		double d1=0,d2=1440;
		while(it--){
			double dmid=(d1+d2)/2;
			vector<int> order;
			fore(i,0,n)order.pb(i);
			bool possible=false;
			do{
				double pos=0;
				possible=true;
				fore(i,0,n){
					if(intervals[order[i]].ff>pos){
						pos=intervals[order[i]].ff+dmid;
					}else if(intervals[order[i]].ff<=pos &&intervals[order[i]].ss>=pos){
						pos+=dmid;
					}else{
						possible=false;
						break;
					}
				}
			}while(!possible && next_permutation(ALL(order)));
			if(possible){
				d1=dmid;
			}else{
				d2=dmid;
			}
		}
		int minutos=d1;
		int segundos=round((d1-minutos)*60);
		if(segundos==60){
			minutos++;
			segundos=0;
		}
		cout <<"Case "<<t<<": "<<minutos<<":"<<(segundos<10?"0"+to_string(segundos):to_string(segundos))<<"\n";
	}
    return 0;
}

