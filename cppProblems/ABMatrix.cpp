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
	int t;
	cin >>t;
	while(t--){
		int n,m,a,b;
		cin >>n>>m>>a>>b;
		if(n*a==b*m){
			cout << "YES\n";
			int table[n][m];
			vector<ii> rem;
			fore(i,0,m){
				rem.pb(ii(-b,i));
			}
			fore(i,0,n){
				sort(ALL(rem));
				fore(j,0,a){
					table[i][rem[j].ss]=1;
					rem[j].ff++;
				}
				fore(j,a,m){
					table[i][rem[j].ss]=0;
				}
			}
			fore(i,0,n){
				fore(j,0,m){
					cout <<table[i][j];
				}
				cout <<"\n";
			}
		}else{
			cout <<"NO\n";
		}
	}
    return 0;
}
