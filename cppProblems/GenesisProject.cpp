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
ii puntos[1005];
int main(){FIN;
	int N;
	cin >>N;
	fore(i,0,N)cin >> puntos[i].ff >>puntos[i].ss;
	if(N<=3){
		cout << "0\n";
	}else{
		set<ii> st;
		bool isOne=false;
		fore(i,0,N-1){
			fore(j,i+1,N){
				if(st.count(ii(puntos[i].ff+puntos[j].ff,puntos[i].ss+puntos[j].ss))){
					isOne=true;
					break;
				}else{
					st.insert(ii(puntos[i].ff+puntos[j].ff,puntos[i].ss+puntos[j].ss));
				}
			}
		}
		if(isOne){
			cout << "1\n";
		}else{
			cout << "2\n";
		}
	}
    return 0;
}

