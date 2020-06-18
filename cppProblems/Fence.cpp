#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
const int INF=1e8;
int dp[205][40005][5];
int sum[205],fences[205];
int N,a,b;
//0->nada,1->rojo,2->green
int go(int pos,int x,int prev){
	if(!(x<=a && (pos?sum[pos-1]:0)-x<=b))return INF;
	if(pos==N){
		if(x<=a && (pos?sum[pos-1]:0)-x<=b){
			return 0;
		}else{
			return INF;
		}
	}
	int &r=dp[pos][x][prev];
	if(r!=-1)return r;
	r=0;
	if(prev==0){
		return r=min(go(pos+1,x+fences[pos],1),go(pos+1,x,2));
	}else if(prev==1){
		return r=min(go(pos+1,x+fences[pos],1),min(fences[pos-1],fences[pos])+go(pos+1,x,2));
	}else if(prev==2){
		return r=min(min(fences[pos-1],fences[pos])+go(pos+1,x+fences[pos],1),go(pos+1,x,2));
	}
}
int main(){FIN;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> N;
	cin >> a >> b;
	fore(i,0,N){
		cin >> fences[i];
		sum[i]=fences[i];
		if(i)sum[i]+=sum[i-1];
	}
	memset(dp,-1,sizeof dp);
	int ans=go(0,0,0);
	if(ans==INF)cout << "-1\n";
	else cout << ans<<"\n";
    return 0;
}
