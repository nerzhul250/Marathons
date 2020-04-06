#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;

int N,C,T[5];
int holes[1005];
int nxtHole[1005][5];
int dp[1005][1005];
int minLength(int holesCov, int currPos){
	if(holesCov>=N)return 0;
	if(dp[holesCov][currPos]!=0)return dp[holesCov][currPos];
	int minimum=1e9;
	fore(k,0,2){
		int increase=0;
		if(nxtHole[currPos][k]-currPos>0){
			increase=nxtHole[currPos][k]-currPos;
		}else{
			increase=nxtHole[currPos][k]+N-currPos;
		}
		minimum=min(minimum,minLength(holesCov+increase,nxtHole[currPos][k])+T[k]);
	}
	return dp[holesCov][currPos]=minimum;
}

int main(){FIN;
	cin >> N >> C >> T[0] >> T[1];
	fore(i,0,N)cin >> holes[i];
	fore(i,0,N){
		nxtHole[i][0]=(upper_bound(begin(holes),begin(holes)+N,(holes[i]+T[0])%C)-begin(holes))%N;
		nxtHole[i][1]=(upper_bound(begin(holes),begin(holes)+N,(holes[i]+T[1])%C)-begin(holes))%N;
	}
	int minimum=1e9;
	fore(pos,0,N){
		minimum=min(minimum,minLength(0,pos));
	}
	cout << minimum << "\n";
    return 0;
}
