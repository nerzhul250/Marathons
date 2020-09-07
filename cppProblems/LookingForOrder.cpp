#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
ii coor[30];
int dp[(1 << 24) + 5];
int sq[30][30];
int n;
int xo,yo;
int squared(int x1,int y1,int x2, int y2){
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int go(int mask){
	if (mask == (1 << n)-1)return dp[mask]=0;
	int &r = dp[mask];
	if (r != -1)return r;
	r=1e9;
	int frst=-1;
	fore(i,0,n){
		if((mask&(1<<i))==0){
			if(frst==-1){
				frst=i;
			}else{
				r= min(r,go((mask | (1 << i)) | (1 << frst))+sq[i][n]+sq[frst][n]+sq[i][frst]);
			}
		}
	}
	r= min(r,2*sq[frst][n]+go(mask | (1 << frst)));
	return r;
}
void build(int mask){
	if(mask == (1 << n)-1)return;
	int frst=-1;
	fore(i,0,n){
		if((mask&(1<<i))==0){
			if(frst==-1){
				frst=i;
			}else if(dp[mask]==dp[(mask | (1 << i)) | (1 << frst)]+sq[i][n]+sq[frst][n]+sq[i][frst]){
   			  cout << "0 "<<frst+1<<" "<<i+1<<" ";
			  build((mask | (1 << i)) | (1 << frst));
			  return;
			}
		}
	}
	if(dp[mask]==dp[mask | (1 << frst)]+2*sq[frst][n]){
		cout << "0 "<<frst+1<<" ";
		build(mask | (1 << frst));
		return ;
	}
}
int main()
{FIN;
	cin >> xo >> yo >> n;
	fore(i,0,n)cin >> coor[i].ff >> coor[i].ss;
	fore(i,0,n){
		sq[i][n]=squared(xo,yo,coor[i].ff,coor[i].ss);
		sq[n][i]=sq[i][n];
		fore(j,0,n){
			sq[i][j]=squared(coor[i].ff,coor[i].ss,coor[j].ff,coor[j].ss);
			sq[j][i]=sq[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	cout << go(0) << "\n";
	build(0);
	cout << "0";
	cout << "\n";
	return 0;
}
