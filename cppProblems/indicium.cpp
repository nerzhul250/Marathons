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

ll row[20],column[20];
int latinaSquare[55][55];
int N,K;
int sumas[2500];
bool check(int y,int x,int val){
	return row[y]!=(row[y]|(1<<val)) && column[x]!=(column[x]|(1<<val));
}
bool solve(int y,int x,int sum){	
	if(y==N){
		sumas[sum]=1;
		return sum==K;
	}
	fore(i,1,N+1){
		if(check(y,x,i)){
			latinaSquare[y][x]=i;
			row[y]|=(1<<i);
			column[x]|=(1<<i);
			if(!solve((x+1==N?y+1:y),(x+1)%N,(y==x?i+sum:sum))){
				row[y]^=(1<<i);
				column[x]^=(1<<i);
				latinaSquare[y][x]=0;
			}else{
				return true;
			}
		}
	}
	return false;
}
int main(){FIN;
	/*int T;
	cin >> T;
	int org=T;
	while(T--){*/
	fore(nn,6,7){
		cout << nn<<",";
		fore(kk,nn,nn*nn+1){
			cout << kk<<endl;
			if(sumas[kk]){
				cout <<"P";
				continue;
			}
			N=nn;
			K=kk;
			memset(latinaSquare,0,sizeof latinaSquare);
			memset(row,0,sizeof row);
			memset(column,0,sizeof column);
			if(solve(0,0,0)){
				//cout << "Case #"<<org-T<<": POSSIBLE\n";
				cout << "P";
				/*fore(i,0,N){
					fore(j,0,N){
						if(j==N-1){
							cout << latinaSquare[i][j]<<"\n";
						}else{
							cout << latinaSquare[i][j]<<" ";
						}
					}
				}*/
			}else{
				//cout << "Case #"<<org-T<<": IMPOSSIBLE\n";
				cout << "I";
			}
		}
		cout <<"\n";
		
	}
    return 0;
}
