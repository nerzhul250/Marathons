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
typedef pair<ii,int> iii;

int main(){FIN;
	int T;
	cin >> T;
	int org=T;
	while(T--){
		int N;
		cin >> N;
		vector<iii> times;
		fore(i,0,N){
			int s,e;
			cin >> s >> e;
			times.pb(iii(ii(s,1),i));
			times.pb(iii(ii(e,-1),i));
		}
		sort(ALL(times));
		int sum=0;
		string ans="";
		fore(i,0,N)ans+='*';
		int occu[5];
		occu[0]=occu[1]=-1;
		fore(i,0,times.size()){
			sum+=times[i].ff.ss;
			if(sum>2 && (i+1==times.size() || times[i].ff.ff!=times[i+1].ff.ff))break;
			if(times[i].ff.ss==1){
				if(occu[0]==-1){
					occu[0]=times[i].ss;
					ans[times[i].ss]='C';
				}else{
					occu[1]=times[i].ss;
					ans[times[i].ss]='J';
				}	
			}else{
				if(occu[0]==times[i].ss){
					occu[0]=-1;
				}else{
					occu[1]=-1;
				}
			}
		}
		if(sum>2){
			cout << "Case #"<<org-T<<": IMPOSSIBLE\n";
		}else{
			cout << "Case #"<<org-T<<": "<<ans<<"\n";
		}
	}
    return 0;
}

