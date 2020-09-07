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
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		int minMoves=1e9;
		fore(d,0,10){
			int moves=0;
			fore(i,0,s.size()){
				if((s[i]-'0')!=d){
					moves++;
				}
			}
			minMoves=min(minMoves,moves);
		}
		fore(d1,0,10){
			fore(d2,0,10){
				if(d1!=d2){
					int cnt1=0;
					int cnt2=0;
					int looking=d1;
					fore(i,0,s.size()){
						if((s[i]-'0')==looking){
							if(looking==d1){
								cnt1++;
								looking=d2;
							}else{
								cnt2++;
								looking=d1;
							}
						}
					}
					int parejas=min(cnt1,cnt2);
					minMoves=min(minMoves,(int)(s.size()-parejas*2));
				}
			}
		}
		cout << minMoves<<"\n";
	}
    return 0;
}
