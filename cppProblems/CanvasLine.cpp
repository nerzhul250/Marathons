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

int n,p;
ii canvases[1005];
map<int,vector<int>> posToCanvases;
set<int> orgLims;

int canvasPegNum[1005];
set<int> pegs;

vector<int> ans;

bool putPegOn(int pos){
	if(pegs.count(pos)){
		return false;
	}else{
		vector<int> canvas=posToCanvases[pos];
		if(canvas.size()==1){
			if(canvasPegNum[canvas[0]]==2){
				return false;
			}else{
				canvasPegNum[canvas[0]]++;
			}
		}else{
			if(canvasPegNum[canvas[0]]==2 ||canvasPegNum[canvas[1]]==2){
				return false;
			}else{
				canvasPegNum[canvas[0]]++;
				canvasPegNum[canvas[1]]++;
			}
		}
		pegs.insert(pos);
		ans.pb(pos);
	}
	return true;
}



int main(){FIN;
	cin >> n;
	fore(i,0,n){
		cin >> canvases[i].ff >> canvases[i].ss;
		posToCanvases[canvases[i].ff].pb(i);
		posToCanvases[canvases[i].ss].pb(i);
		orgLims.insert(canvases[i].ff);
		orgLims.insert(canvases[i].ss);
	}
	cin >> p;
	fore(i,0,p){
		int peg;
		cin >> peg;
		pegs.insert(peg);
		int canvasLim=(*orgLims.lower_bound(peg));
		vector<int> canvas=posToCanvases[canvasLim];
		if(canvas.size()==1){
			if(peg<=canvases[canvas[0]].ss && peg>=canvases[canvas[0]].ff){
				canvasPegNum[canvas[0]]++;
			}
		}else if(canvas.size()==2){
			if(peg<=canvases[canvas[0]].ss && peg>=canvases[canvas[0]].ff){
				canvasPegNum[canvas[0]]++;
			}
			if(peg<=canvases[canvas[1]].ss && peg>=canvases[canvas[1]].ff){
				canvasPegNum[canvas[1]]++;
			}
		}
	}
	
	bool possible=true;
	fore(i,0,n){
		if(canvasPegNum[i]>2){
			possible=false;
			break;
		}
	}
	
	if(!possible){
		cout << "impossible\n";
	}else{
		fore(i,0,n){
			
			if(canvasPegNum[i]==0){
				if(!putPegOn(canvases[i].ss)){
					if(!putPegOn(canvases[i].ff)){
						canvasPegNum[i]+=2;
						int peggy=canvases[i].ff+1;
						while(pegs.count(peggy))peggy++;
						ans.pb(peggy);
						pegs.insert(peggy);
						
						while(pegs.count(peggy))peggy++;
						ans.pb(peggy);
						pegs.insert(peggy);
					}else{
						canvasPegNum[i]++;
						
						int peggy=canvases[i].ff+1;
						while(pegs.count(peggy))peggy++;
						ans.pb(peggy);
						pegs.insert(peggy);
					}
				}else{
					if(!putPegOn(canvases[i].ff)){
						canvasPegNum[i]++;
						
						int peggy=canvases[i].ff+1;
						while(pegs.count(peggy))peggy++;
						ans.pb(peggy);
						pegs.insert(peggy);
					}
				}
			}else if(canvasPegNum[i]==1){
				if(!putPegOn(canvases[i].ss)){
					if(!putPegOn(canvases[i].ff)){
						canvasPegNum[i]++;
						
						int peggy=canvases[i].ff+1;
						while(pegs.count(peggy))peggy++;
						ans.pb(peggy);
						pegs.insert(peggy);
					}
				}
			}
		}
		cout << ans.size() <<"\n";
		fore(i,0,ans.size()){
			if(i==ans.size()-1){
				cout << ans[i] <<"\n";
			}else{
				cout << ans[i] << " ";
			}
		}
	}
    return 0;
}
