#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
double dp[105][105][105];
int visited[105][105][105];
int R,S,P;
double go(int r, int s, int p, int t){
	if(t==0 && r==0){
		return 0;
	}else if(t==1 && s==0){
		return 0;
	}else if(t==2 && p==0){
		return 0;
	}
	if(t==0 && r>0 && s==0 && p==0){
		return 1;
	}else if(t==1 && r==0 && s>0 && p==0 ){
		return 1;
	}else if(t==2 && r==0 && s==0 && p>0){
		return 1; 
	}
	double &k=dp[r][s][p];
	if(visited[r][s][p])return k;
	visited[r][s][p]=1;
	k=0;
	double allPairs=((r+s+p)*(r+s+p-1))/2.0;
	if(r>0 && s-1>=0)k+=go(r,s-1,p,t)*((r*s)/allPairs);
	if(s>0 && p-1>=0)k+=go(r,s,p-1,t)*((s*p)/allPairs);
	if(p>0 && r-1>=0)k+=go(r-1,s,p,t)*((p*r)/allPairs);
	k/=(1-((((r*(r-1))/(2.0))+((s*(s-1))/(2.0))+((p*(p-1))/(2.0)))/allPairs));
	return k;
}
int main(){FIN;
	cin >> R >> S >> P;
	cout << fixed;
	cout << setprecision(13);
	cout << go(R,S,P,0)<<" ";
	memset(dp,0,sizeof dp);
	memset(visited,0,sizeof visited);
	cout << go(R,S,P,1)<<" ";
	memset(dp,0,sizeof dp);
	memset(visited,0,sizeof visited);
	cout << go(R,S,P,2)<<"\n";
    return 0;
}
