#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
char table[55][55];
int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		int n;
		cin >>n;
		fore(i,0,n){
			fore(j,0,n){
				cin >>table[i][j];
			}
		}
		bool possible=true;
		fore(i,0,n){
			fore(j,0,n){
				if(table[i][j]=='1'){
					possible&=((i+1==n || table[i+1][j]=='1')||(j+1==n || table[i][j+1]=='1'));
				}
			}
		}
		if(possible){
			cout <<"YES\n";
		}else{
			cout <<"NO\n";
		}
	}
    return 0;
}
