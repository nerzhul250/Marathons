#include <vector>
#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef pair<int,vector<int>> ivi;

const int INF=1e9;

map<int,vector<int>> cowsCoordinates;
vector<ivi>cowLine;
int N,K,B;
int dp[1005][1005][10];
int minArea(int pos,int barn,int state){
	//cout << pos <<" "<<barn<<" "<<state<<"\n";
	if(pos==-1){
		if(barn==0 && state==0){
			return 0;
		}else{
			return INF;
		}
	}
	if(barn<0)return INF;
	int &r=dp[pos][barn][state];
	if(r!=-1)return r;
	int dis=cowLine[pos].ff-(pos==0?0:cowLine[pos-1].ff);
	//cout << dis<<"\n";
	if(state==0){
		if(cowLine[pos].ss.size()==1){
			if(cowLine[pos].ss[0]==0){
				//top
				r=minArea(pos-1,barn-1,0)+1;
				r=min(r,minArea(pos-1,barn,2)+dis);
				//double
				r=min(r,minArea(pos-1,barn-2,0)+2);
				r=min(r,minArea(pos-1,barn,1)+2*dis);
				r=min(r,minArea(pos-1,barn-1,2)+dis+1);
				r=min(r,minArea(pos-1,barn-1,3)+dis+1);
				//whole
				r=min(r,minArea(pos-1,barn-1,0)+2);
				r=min(r,minArea(pos-1,barn,4)+2*dis);
			}else{
				// bot
				r=minArea(pos-1,barn-1,0)+1;
				r=min(r,minArea(pos-1,barn,3)+dis);
				//double
				r=min(r,minArea(pos-1,barn-2,0)+2);
				r=min(r,minArea(pos-1,barn,1)+2*dis);
				r=min(r,minArea(pos-1,barn-1,2)+dis+1);
				r=min(r,minArea(pos-1,barn-1,3)+dis+1);
				//whole
				r=min(r,minArea(pos-1,barn-1,0)+2);
				r=min(r,minArea(pos-1,barn,4)+2*dis);
			}
		}else{
			//double
			r=minArea(pos-1,barn-2,0)+2;
			r=min(r,minArea(pos-1,barn,1)+2*dis);
			r=min(r,minArea(pos-1,barn-1,2)+dis+1);
			r=min(r,minArea(pos-1,barn-1,3)+dis+1);
			//whole
			r=min(r,minArea(pos-1,barn-1,0)+2);
			r=min(r,minArea(pos-1,barn,4)+2*dis);
		}
	}else if(state==1){
		//double
		r=minArea(pos-1,barn-2,0)+2;
		r=min(r,minArea(pos-1,barn,1)+2*dis);
		r=min(r,minArea(pos-1,barn-1,2)+dis+1);
		r=min(r,minArea(pos-1,barn-1,3)+dis+1);
	}else if(state==2){
		if(cowLine[pos].ss.size()==1){
			if(cowLine[pos].ss[0]==0){
				//top
				r=minArea(pos-1,barn-1,0)+1;
				r=min(r,minArea(pos-1,barn,2)+dis);
				//double
				r=min(r,minArea(pos-1,barn-2,0)+2);
				r=min(r,minArea(pos-1,barn,1)+2*dis);
				r=min(r,minArea(pos-1,barn-1,2)+dis+1);
				r=min(r,minArea(pos-1,barn-1,3)+dis+1);
			}else{
				//double
				r=minArea(pos-1,barn-2,0)+2;
				r=min(r,minArea(pos-1,barn,1)+2*dis);
				r=min(r,minArea(pos-1,barn-1,2)+dis+1);
				r=min(r,minArea(pos-1,barn-1,3)+dis+1);
			}
		}else{
			//double
			r=minArea(pos-1,barn-2,0)+2;
			r=min(r,minArea(pos-1,barn,1)+2*dis);
			r=min(r,minArea(pos-1,barn-1,2)+dis+1);
			r=min(r,minArea(pos-1,barn-1,3)+dis+1);
		}
	}else if(state==3){
		if(cowLine[pos].ss.size()==1){
			if(cowLine[pos].ss[0]==0){
				//double
				r=minArea(pos-1,barn-2,0)+2;
				r=min(r,minArea(pos-1,barn,1)+2*dis);
				r=min(r,minArea(pos-1,barn-1,2)+dis+1);
				r=min(r,minArea(pos-1,barn-1,3)+dis+1);
			}else{
				//bot
				r=minArea(pos-1,barn-1,0)+1;
				r=min(r,minArea(pos-1,barn,3)+dis);
				//double
				r=min(r,minArea(pos-1,barn-2,0)+2);
				r=min(r,minArea(pos-1,barn,1)+2*dis);
				r=min(r,minArea(pos-1,barn-1,2)+dis+1);
				r=min(r,minArea(pos-1,barn-1,3)+dis+1);
			}
		}else{
			//double
			r=minArea(pos-1,barn-2,0)+2;
			r=min(r,minArea(pos-1,barn,1)+2*dis);
			r=min(r,minArea(pos-1,barn-1,2)+dis+1);
			r=min(r,minArea(pos-1,barn-1,3)+dis+1);
		}
	}else if(state==4){
		//whole
		r=minArea(pos-1,barn-1,0)+2;
		r=min(r,minArea(pos-1,barn,4)+2*dis);
	}
	return r;
}
int main(){FIN;
	cin >> N >> K >> B;
	memset(dp,-1,sizeof dp);
	fore(i,0,N){
		int a,b;
		cin >> a >> b;
		a--,b--;
		if(cowsCoordinates.count(b)){
			cowsCoordinates[b].pb(a);
		}else{
			cowsCoordinates[b]=vector<int>();
			cowsCoordinates[b].pb(a);
		}
	}
	for(map<int,vector<int>>::iterator it=cowsCoordinates.begin();it!=cowsCoordinates.end();it++){
		cowLine.pb(ivi(it->ff,it->ss));
	}
	cout << minArea(cowLine.size()-1,K,0)<<"\n";
    return 0;
}
