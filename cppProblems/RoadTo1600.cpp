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
const int MAXN=505;
int ans[MAXN][MAXN];
int main(){FIN;
	int N;
	cin >> N;
	if(N==1 || N==2){
		cout << "-1\n";
	}else{
		int curr=N*N;
		ans[0][0]=curr;ans[0][1]=curr-4;ans[0][2]=curr-3;
		ans[1][0]=curr-2;ans[1][1]=curr-7;ans[1][2]=curr-1;
		ans[2][0]=curr-8;ans[2][1]=curr-6;ans[2][2]=curr-5;
		curr=curr-9;
		int flag=1;
		fore(i,0,N-3){
			if(flag){
				fore(j,0,4+i){
					ans[i+3][j]=curr;
					curr--;
				}
				fore(j,0,3+i){
					ans[2+i-j][3+i]=curr;
					curr--;
				}
			}else{
				fore(j,0,3+i){
					ans[j][3+i]=curr;
					curr--;
				}
				fore(j,0,4+i){
					ans[i+3][3+i-j]=curr;
					curr--;
				}
			}
			flag=1-flag;
		}
		fore(i,0,N){
			fore(j,0,N){
				cout << ans[i][j]<<" ";
			}
			cout << "\n";
		}
	}
    return 0;
}
