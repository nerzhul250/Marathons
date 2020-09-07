#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
int square[305][305];
int dp[605][305][305];
int maximo(int t, int i1, int i2){
	if(t==0)return square[0][0];
	int &r=dp[t][i1][i2];
	if(r!=-1e9)return r;
	r=-1e9;
	if(t-1-i1>=0 && t-1-i2>=0)r=max(r,maximo(t-1,i1,i2));
	if(i1-1>=0 && t-1-i2>=0)r=max(r,maximo(t-1,i1-1,i2));
	if(t-1-i1>=0 && i2-1>=0)r=max(r,maximo(t-1,i1,i2-1));
	if(i1-1>=0 && i2-1>=0)r=max(r,maximo(t-1,i1-1,i2-1));
	r+=(i1==i2?square[i1][t-i1]:(square[i1][t-i1]+square[i2][t-i2]));
	return r;
}
int main(){FIN;	
	int n;
	cin >> n;
	fore(i,0,n)fore(j,0,n)cin >> square[i][j];
	fore(i,0,605){
		fore(j,0,305){
			fore(k,0,305){
				dp[i][j][k]=-1e9;
			}
		}
	}
	cout << maximo(2*n-2,n-1,n-1)<<"\n";
    return 0;
}
