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
ii scores[100005];
int esIgual[100005];
struct cmp {
    bool operator() (const ii& a, const ii& b) const {
        return a.ff*b.ss<b.ff*a.ss;
    }
};
int main(){FIN;
	int N;
	cin >> N;
	fore(i,0,N)cin >> scores[i].ff >>scores[i].ss;
	map<ii,vector<int>,cmp>mp;
	int x1=scores[0].ff,x2=scores[0].ss;
	vector<int> iguales;
	fore(i,1,N){
		int y1=scores[i].ff,y2=scores[i].ss;
		if(x1==y1 && x2==y2){
			iguales.pb(i);
			esIgual[i]=1;
		}else{
			if(x1-x2-y1+y2!=0){
				if(y2-x2==0){
					mp[ii(0,1)].pb(i);
				}else{
					int a=y2-x2;
					int b=x1-x2-y1+y2;
					if(a*b>0 && abs(a)<=abs(b)){
						int g=__gcd(abs(a),abs(b));
						a/=g;
						b/=g;
						mp[ii(abs(a),abs(b))].pb(i);
					}
				}
			}
		}
	}
	vector<ii> currOrdering;
	fore(i,0,N){
		if(!esIgual[i]){
			currOrdering.pb(ii(scores[i].ss,i));
		}
	}
	sort(ALL(currOrdering));
	vector<int> rankings(N,-1);
	fore(i,0,currOrdering.size()){
		rankings[currOrdering[i].ss]=i;
	}
	int maximo=rankings[0]+iguales.size(),minimo=rankings[0];
	for(auto it=mp.begin();it!=mp.end();it++){
		vector<int> equalScore=it->ss;
		int low=0;
		int high=0;
		vector<ii> newOrdering;
		newOrdering.pb(ii(scores[0].ff-scores[0].ss,0));
		for(int id:equalScore){
			if(rankings[id]<rankings[0]){
				low--;
				int otherId=currOrdering[rankings[0]+low].ss;
				swap(rankings[otherId],rankings[id]);
				assert(currOrdering[rankings[otherId]].ss==id);
				assert(currOrdering[rankings[id]].ss=otherId);
				swap(currOrdering[rankings[otherId]],currOrdering[rankings[id]]);
			}else{
				high++;
				int otherId=currOrdering[rankings[0]+high].ss;
				swap(rankings[otherId],rankings[id]);
				assert(currOrdering[rankings[otherId]].ss==id);
				assert(currOrdering[rankings[id]].ss=otherId);
				swap(currOrdering[rankings[otherId]],currOrdering[rankings[id]]);
			}
			newOrdering.pb(ii(scores[id].ff-scores[id].ss,id));
		}
		sort(ALL(newOrdering));
		minimo=min(minimo,(int)(rankings[0]+low));
		maximo=max(maximo,(int)(rankings[0]+high+iguales.size()));
		int startIndex=rankings[0]+low;
		fore(i,0,newOrdering.size()){
			assert(startIndex+i>=0);
			rankings[newOrdering[i].ss]=startIndex+i;
			currOrdering[startIndex+i]=ii(scores[newOrdering[i].ss].ss,newOrdering[i].ss);
		}
	}
	
	cout << N-maximo << " "<<N-minimo<<"\n";
	
    return 0;
}
