#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;
int main(){FIN;
	int t;
	double sz;
	cin >>t>> sz;
	int n;
	cin >> n;
	int cnt=0;
	while(n--){
		int tt;
		double szz;
		cin >> tt >> szz;
		if(t==1){
			if(tt==1){
				if(szz<=sz){
					cnt++;
				}//chuleado
			}else if(tt==2){
				if(szz<=2*sz){
					cnt++;
				}//chuleado
			}else if(tt==3){
				if(3*szz*szz<=16*sz*sz){
					cnt++;
				}//chuleado
			}
		}else if(t==2){
			if(tt==1){
				if(2*szz*szz<=sz*sz){
					cnt++;
				}//check
			}else if(tt==2){
				if(szz*szz<=sz*sz*2){
					cnt++;
				}//check
			}else if(tt==3){
				if(3*szz*szz<=sz*sz*8){
					cnt++;
				}//check
			}
		}else if(t==3){
			if(tt==1){
				if(szz*2<=sz){
					cnt++;
				}
			}else if(tt==2){
				if(szz<=sz){
					cnt++;
				}
			}else if(tt==3){
				if(3*szz*szz<=4*sz*sz){
					cnt++;
				}
			}
		}
	}
	cout << cnt << "\n";
    return 0;
}
