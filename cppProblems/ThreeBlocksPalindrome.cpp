#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
//Ocurrencias,prefxsum
typedef pair<vector<int>,vector<int>> ii;
vector<int> pos[205];
int prefSum[205][200005];
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		fore(i,1,201)pos[i].clear();
		fore(i,1,201){
			fore(j,0,n+1){
				prefSum[i][j]=0;
			}
		}
		fore(i,0,n){
			int nam;
			cin >> nam;
			pos[nam].pb(i);
			prefSum[nam][i]=1;
			prefSum[nam][n]=1;
		}
		fore(u,1,201){
			if(prefSum[u][n]){
				int acum=0;
				fore(i,0,n){
					acum+=prefSum[u][i];
					prefSum[u][i]=acum;
				}
			}
		}
		int maximumLength=0;
		fore(u,1,201){
			if(prefSum[u][n]){
				maximumLength=max(maximumLength,prefSum[u][n-1]);
				fore(i,0,pos[u].size()){
					if(pos[u][i]<pos[u][pos[u].size()-1-i]){
						int sumaMaxima=0;
						fore(v,1,201){
							if(prefSum[v][n]){
								int l=pos[u][i]+1;
								int r=pos[u][pos[u].size()-1-i]-1;
								sumaMaxima=max(sumaMaxima,2*(i+1)+max(0,prefSum[v][r]-prefSum[v][l-1]));
							}
						}
						maximumLength=max(sumaMaxima,maximumLength);
					}else{
						break;
					}
				}
			}
		}
		cout << maximumLength<<"\n";
	}
    return 0;
}
