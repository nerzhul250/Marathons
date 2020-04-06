#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

int matrix[105][105];
int row[105][105],column[105][105];

int main(){FIN;
	int T;
	cin >> T;
	int org=T;
	while(T--){
		int N;
		cin >> N;
		int r=0,c=0,k=0;
		memset(row,0,sizeof row);
		memset(column,0,sizeof column);
		fore(i,0,N){
			fore(j,0,N){
				cin >> matrix[i][j];
				if(i==j){
					k+=matrix[i][j];
				}
				row[i][matrix[i][j]]++;
				column[j][matrix[i][j]]++;
			}
		}
		fore(i,0,N){
			fore(j,1,N+1){
				if(row[i][j]>1){
					r++;
					break;
				}
			}
		}
		fore(i,0,N){
			fore(j,1,N+1){
				if(column[i][j]>1){
					c++;
					break;
				}
			}
		}
		cout << "Case #" <<org-T << ": "<<k<<" "<<r<<" "<<c<<"\n";
	}
    return 0;
}

