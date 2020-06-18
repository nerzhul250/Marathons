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
int main(){FIN;
	int T;
	cin>>T;
	while(T--){
		int ng[3];
		cin >>ng[0]>>ng[1]>>ng[2];
		//0->r,1->g,2->b
		map<ll,vector<int>> mpGems;
		set<ll> stGems[3];
		ll prevGem[3];
		prevGem[0]=-1;
		prevGem[1]=-1;
		prevGem[2]=-1;
		fore(i,0,3){
			fore(j,0,ng[i]){
				ll g;
				cin >> g;
				stGems[i].insert(g);
				if(mpGems.count(g)==0){
					mpGems[g]=vector<int>(3,0);
					mpGems[g][i]=1;
				}else{
					mpGems[g][i]=1;
				}
			}
		}
		ll minDis=9e18;
		for(auto it=mpGems.begin();it!=mpGems.end();it++){
			ll pos=it->ff;
			vector<int> posGems=it->ss;
			fore(i,0,3){
				if(posGems[i]==1)prevGem[i]=pos;
			}
			fore(i,0,3){
				if(posGems[i]==1){
					ll posx[3];
					posx[i]=pos;
					fore(j,0,3){
						if(i!=j){
							posx[j]=-1;							
							if(prevGem[j]!=-1){
								posx[j]=prevGem[j];
							}
							auto iter=stGems[j].upper_bound(pos);
							if(iter!=stGems[j].end()){
								if(posx[j]==-1 || abs(posx[j]-pos)>abs(*iter-pos)){
									posx[j]=*iter;
								}
							}
						}
					}
					minDis=min(minDis,(posx[0]-posx[1])*(posx[0]-posx[1])+
					(posx[0]-posx[2])*(posx[0]-posx[2])+(posx[1]-posx[2])*(posx[1]-posx[2]));
				}
			}
		}
		cout << minDis<<"\n";
	}
    return 0;
}
