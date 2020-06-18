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
typedef long long int ll;
ll skill[1<<15];
ll dp[1<<15][20];
int R;
ii range(int i,int r){
	int p=(i+(1<<R))/(1<<(r+1));
	int u=-1;
	if(p*2==((i+(1<<R))/(1<<r))){
		u=p*2+1;	
	}else{
		u=p*2;
	}
	int left=u*(1<<r)-(1<<R);
	int right=left+(1<<r)-1;
	ii ran={left,right};
	return ran;
}
ll toTrain(int a,int b){
	return max(skill[b]-skill[a],0LL)*max(skill[b]-skill[a],0LL);
}
ll minTraining(int i, int r){
	if(dp[i][r]!=-1)return dp[i][r];
	if(r==0){
		int u=range(i,r).ff;
		return toTrain(i,u);
	}
	ii ran=range(i,r);
	ll minimo=1e18;
	fore(o,ran.ff,ran.ss+1){
		minimo=min(minimo,minTraining(o,r-1)+toTrain(i,o));
	}
	return dp[i][r]=minTraining(i,r-1)+minimo;
}
int main(){FIN;
	memset(dp,-1,sizeof dp);
	cin >> R;
	fore(i,0,1<<R)cin >> skill[i];
	cout << minTraining(0,R-1)<<"\n";
	return 0;
}
