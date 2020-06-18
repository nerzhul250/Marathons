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
const int INF=1e9;
int dp[2005][2005];
int bToi(string s){
	reverse(ALL(s));
	int num=0;
	fore(i,0,s.size()){
		if(s[i]=='1'){
			num+=(1<<i);
		}
	}
	return num;
}
int main(){FIN;
	int n,k;
	cin >> n >> k;
	vector<vector<int>> board;
	vector<int> nums(n,INF);
	string digits[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	vector<int> digMask;
	fore(i,0,10)digMask.pb(bToi(digits[i]));
	fore(i,0,n){
		board.pb(vector<int>(10,INF));
		string s;
		cin >> s;
		int mask=bToi(s);
		fore(j,0,10){
			if((mask|digMask[j])==digMask[j]){
				int cnt=0;
				fore(k,0,7){
					//cout << mask << " "<<digMask[j]<<"\n";
					if(((1<<k)&(mask))==0 && ((1<<k)&(digMask[j]))!=0){
						cnt++;
					}
				}
				board[i][j]=cnt;
			}
		}
	}
	dp[n][0]=1;
	for(int i=n-1;i>=0;i--){
		fore(kk,0,k+1){
			fore(j,0,10){
				if(kk>=board[i][j]){
					if(dp[i+1][kk-board[i][j]]){
						dp[i][kk]=1;
					}
				}
			}
		}
	}
	string ans="";
	int org=k;
	fore(i,0,n){
		for(int j=9;j>=0;j--){
			if(board[i][j]!=INF && dp[i+1][k-board[i][j]]){
				k-=board[i][j];
				ans+=to_string(j);
				break;
			}
		}
	}
	if(dp[0][org]){
		cout << ans <<"\n";	
	}else{
		cout <<"-1\n";
	}
    return 0;
}
