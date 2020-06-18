#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

char matrix[205][205];
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		fore(i,0,n){
			matrix[i][0]='B';
		}
		fore(i,0,m){
			matrix[0][i]='B';
		}
		fore(i,1,n){
			fore(j,1,m){
				matrix[i][j]='W';
			}
		}
		fore(i,0,n){
			fore(j,0,m){
				cout << matrix[i][j];
			}
			cout << "\n";
		}
	}
    return 0;
}

