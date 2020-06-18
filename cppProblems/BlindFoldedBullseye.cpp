#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int main(){FIN;
	int T,a,b;
	cin >> T >>a >> b;
	while(T--){
		string ans="";
		fore(x,-50,51){
			fore(y,-50,51){
				cout << x <<" "<<y << endl;
				cin >> ans;
				if(ans=="CENTER"){
					break;		
				}else if(ans=="WRONG"){
					return 0;
				}
			}
			if(ans=="CENTER"){
				break;		
			}
		}
		if(ans!="CENTER"){
			return 0;
		}
	}
    return 0;
}
