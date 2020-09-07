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
typedef pair<int,int> ii;
vector<int> ans;
ii recsx[1005],recsy[1005];
map<int,vector<int>> mpx,mpy;
int X,Y;
int N;
int own1,own2;
int dp[1005][5];
int go(int pos,int state,map<int,vector<int>> &mp,ii *recs,int limit){
	if(recs[pos].ss==limit){
		if(state==2){
			return dp[pos][state]=1;
		}else{
			return dp[pos][state]=0;
		}
	}
	if(dp[pos][state]!=-1)return dp[pos][state];
	int &r=dp[pos][state];
	r=0;
	vector<int> &poss=mp[recs[pos].ss];
	for(int id:poss){
		if(recs[id].ff==recs[pos].ss){
			if(id==own1 || id==own2){
				r=r|go(id,state+1,mp,recs,limit);
			}else{
				r=r|go(id,state,mp,recs,limit);
			}
		}
	}
	return r;
}

void build(int pos,int state,map<int,vector<int>> &mp,ii *recs,int limit){
	ans.pb(pos+1);
	if(recs[pos].ss==limit){
		return ;
	}
	vector<int> &poss=mp[recs[pos].ss];
	for(int id:poss){
		if(recs[id].ff==recs[pos].ss){
			if(id==own1 || id==own2){
				if(dp[id][state+1]){
					build(id,state+1,mp,recs,limit);
					return;
				}
			}else{
				if(dp[id][state]){
					build(id,state,mp,recs,limit);
					return;
				}
			}
		}
	}
}
int main(){FIN;
	cin >> X >> Y;
	cin >> N;
	fore(i,0,N){
		cin >> recsx[i].ff >> recsy[i].ff;
		cin >> recsx[i].ss >> recsy[i].ss;
		mpx[recsx[i].ff].pb(i);
		mpx[recsx[i].ss].pb(i);
		mpy[recsy[i].ff].pb(i);
		mpy[recsy[i].ss].pb(i);
	}
	cin >> own1 >> own2;
	own1--;
	own2--;
	
	memset(dp,-1,sizeof dp);
	vector<int> &posx=mpx[0];
	for(int id:posx){
		int val=go(id,((id==own1 || id==own2)?1:0),mpx,recsx,X);
		if(val){
			build(id,((id==own1 || id==own2)?1:0),mpx,recsx,X);
			cout << ans.size()<<"\n";
			fore(i,0,ans.size()){
				if(i==ans.size()-1)cout << ans[i]<<"\n";
				else cout << ans[i]<<" ";
			}
			return 0;
		}
	}
	
	memset(dp,-1,sizeof dp);
	vector<int> &posy=mpy[0];
	for(int id:posy){
		int val=go(id,((id==own1 || id==own2)?1:0),mpy,recsy,Y);
		if(val){
			build(id,((id==own1 || id==own2)?1:0),mpy,recsy,Y);
			cout << ans.size()<<"\n";
			fore(i,0,ans.size()){
				if(i==ans.size()-1)cout << ans[i]<<"\n";
				else cout << ans[i]<<" ";
			}
			return 0;
		}
	}
	cout << "-1\n";
    return 0;
}
