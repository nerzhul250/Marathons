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
	ll N,A,R,M;
	cin >>N>>A>>R>>M;
	map<ll,ll> heights;
	ll totalBricks=0;
	fore(i,0,N){
		ll h;
		cin>>h;
		totalBricks+=h; //over
		heights[h]++;
	}
	if(heights.count(totalBricks/N)==0)heights[totalBricks/N]=0;
	if(heights.count(totalBricks/N + 1)==0)heights[totalBricks/N + 1]=0;
	ll curB=0;
	ll curn=0;
	ll minCost=1e18;
	for(auto it=heights.begin();it!=heights.end();it++){
		ll h=it->ff;
		ll n=it->ss;
		int flag=0;
		if(n==0){
			flag=1;
			n=1;
		}
		ll cost=0;
		if(h*N<totalBricks){//over
			ll hole=h*N-h*(N-curn)-curB;//overflow
			while(hole>0){
				hole--;
				cost+=min(R+A,M);
			}
			cost+=(R*(totalBricks-h*N));
		}else if(h*N>totalBricks){
			ll bricksAboveH=totalBricks-((N-curn)*h+curB);
			//cout << "bah "<<bricksAboveH << " "<<totalBricks<<" "<<N<<" "<<n<<" "<<h<<" "<<curB<<endl;
			while(bricksAboveH>0){
				bricksAboveH--;
				cost+=min(R+A,M);
			}
			cost+=(A*(h*N-totalBricks));
			//cout << (A*(h*N-totalBricks))<<endl;
			//cout << h << " "<<cost<<endl;
		}else{
			ll bricksAboveH=totalBricks-((N-curn)*h+curB);
			while(bricksAboveH>0){
				bricksAboveH--;
				cost+=min(R+A,M);
			}
		}
		if(flag){
			h=0;
			n=0;
		}
		curB+=(h*n);
		curn+=n;
		minCost=min(minCost,cost);
	}
	cout <<minCost<<"\n";
    return 0;
}

