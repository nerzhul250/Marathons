#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
char mp[100][100];
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		int n,m;
		cin >> n >> m;
		bool allP=true;
		bool allA=true;
		fore(i,0,n){
			fore(j,0,m){
				cin >> mp[i][j];
				if(mp[i][j]=='A'){
					allP=false;
				}else{
					allA=false;
				}
			}
		}
		if(allP){
			cout << "MORTAL\n";
		}else if(allA){
			cout << "0\n";
		}else{
			bool colrowA=false;
			bool all1=true;
			bool all2=true;		
			fore(i,0,n){
				if(mp[i][0]!='A')all1=false;
				if(mp[i][m-1]!='A')all2=false;
			}
			if(all1 || all2){
				colrowA=true;
			}
			all1=true;
			all2=true;
			fore(j,0,m){
					if(mp[0][j]!='A')all1=false;
					if(mp[n-1][j]!='A')all2=false;
			}
			if(all1 || all2){
				colrowA=true;
			}
			if(colrowA){
				cout << "1\n";
			}else{
				bool colrowA=false;
				fore(i,1,n-1){
					bool all=true;
					fore(j,0,m){
						if(mp[i][j]!='A'){all=false;break;}
					}
					if(all){
						colrowA=true;
					}
				}
				fore(j,1,m-1){
					bool all=true;
					fore(i,0,n){
						if(mp[i][j]!='A'){all=false;break;}
					}
					if(all){
						colrowA=true;
					}
				}
				if(mp[0][0]=='A' ||mp[0][m-1]=='A' ||mp[n-1][0]=='A' ||mp[n-1][m-1]=='A' || colrowA){
					cout << "2\n";
				}else{
					bool foundA=false;
					fore(i,0,n){
						if(mp[i][0]=='A'){foundA=true;break;}
						if(mp[i][m-1]=='A'){foundA=true;break;}
					}
					fore(j,0,m){
						if(mp[0][j]=='A'){foundA=true;break;}
						if(mp[n-1][j]=='A'){foundA=true;break;}
					}
					if(foundA){
						cout << "3\n";
					}else{
						cout <<"4\n";
					}
				}
			}
		}
	}
    return 0;
}

