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

int types[200005];

int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		//cout << "neCAse\n";
		int n;
		cin >> n;
		vector<ii> typeCnt;
		memset(types,0,sizeof types);
		fore(i,0,n)cin >> types[i];
		int currentType=types[0];
		int cnt=1;
		fore(i,1,n){
			if(types[i]==currentType){
				cnt++;
			}else{
				typeCnt.pb(ii(currentType,cnt));
				cnt=1;
				currentType=types[i];
			}
		}
		typeCnt.pb(ii(currentType,cnt));
		int begD=0;
		if(SZ(typeCnt)!=1 && typeCnt.back().ff==typeCnt.begin()->ff){
			typeCnt.begin()->ss=typeCnt.begin()->ss+typeCnt.back().ss;
			begD=typeCnt.back().ss;
			typeCnt.pop_back();
		}
		if(SZ(typeCnt)==1){
			cout << "1\n";
			fore(i,0,n){
				if(i==n-1){
					cout << "1\n";
				}else{
					cout << "1 ";
				}
			}
		}else{
			bool allOnes=true;
			fore(i,0,SZ(typeCnt))if(typeCnt[i].ss!=1)allOnes=false;
			if(allOnes){
				if(SZ(typeCnt)%2==0){
					int toPrint=1;
					cout << "2\n";
					fore(i,0,SZ(typeCnt)){
						if(i==SZ(typeCnt)-1){
							cout << toPrint << "\n";
						}else{
							cout << toPrint << " ";
						}
						toPrint=(toPrint==1?2:1);
					}
				}else{
					int toPrint=1;
					cout << "3\n";
					fore(i,0,SZ(typeCnt)){
						if(i==SZ(typeCnt)-1){
							cout << "3" << "\n";
						}else{
							cout << toPrint << " ";
						}
						toPrint=(toPrint==1?2:1);
					}
				}
			}else{
				cout << "2\n";
				vector<vector<int>> groupColors;
				int toPrint=1;
				int begPos=0;
				fore(i,0,SZ(typeCnt)){
					if(typeCnt[(i-1+SZ(typeCnt))%SZ(typeCnt)].ss>1 && typeCnt[i].ss==1){
						begPos=i;
						break;
					}
				}
				fore(i,0,SZ(typeCnt))groupColors.pb(vector<int>(typeCnt[i].ss,1));
 				fore(i,0,SZ(typeCnt)){
					//cout  << typeCnt[i].ss<<" ";
					//cout << "justChecking " << (i+begPos)%SZ(typeCnt) <<endl;
					if(typeCnt[(i+begPos)%SZ(typeCnt)].ss==1){
						groupColors[(i+begPos)%SZ(typeCnt)][0]=toPrint;
						toPrint=(toPrint==1?2:1);
					}
				}
				//cout << "\n";
				fore(i,0,SZ(typeCnt)){
					if(typeCnt[i].ss!=1){
						toPrint=groupColors[(i-1+SZ(groupColors))%SZ(groupColors)].back();
						toPrint=(toPrint==1?2:1);
						groupColors[i][0]=toPrint;
						toPrint=*groupColors[(i+1)%SZ(groupColors)].begin();
						toPrint=(toPrint==1?2:1);
						groupColors[i][SZ(groupColors[i])-1]=toPrint;
					}
				}
				
				vector<int>theAns;
				fore(i,0,SZ(groupColors)){
					fore(j,0,SZ(groupColors[i])){
						theAns.pb(groupColors[i][j]);
					}
				}
				fore(i,0,SZ(theAns)){
					if((i+begD)%SZ(theAns)==(begD-1+SZ(theAns))%SZ(theAns)){
						cout << theAns[(i+begD)%SZ(theAns)] << "\n";
					}else{
						cout << theAns[(i+begD)%SZ(theAns)] << " ";
					}
				}
			}
		}
	}
    return 0;
}
