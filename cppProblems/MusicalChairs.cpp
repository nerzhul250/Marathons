#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int n,p;
int length[1005];
int chairs[1005];
int nexChair[1005][1005][2];
int dp[1005][1005];
int possible(int round,int pos){
	if(round>0 && chairs[round-1]==pos)return 0;
	if(round==n-1)return 1;
	int &r=dp[round][pos];
	if(r!=-1)return r;
	r=0;
	r|=possible(round+1,nexChair[round][pos][0]);
	r|=possible(round+1,nexChair[round][pos][1]);
	return r;
}
int main(){FIN;
	memset(nexChair,-1,sizeof nexChair);
	memset(dp,-1,sizeof dp);
	cin >> n >> p;
	p--;
	fore(i,0,n-1)cin >> length[i];
	fore(i,0,n-1){
		cin >> chairs[i];
		chairs[i]--;
	}
	vector<int> state;
	fore(i,0,n)state.pb(i);
	fore(i,0,n-1){
		int toRemove=-1;
		fore(j,0,state.size()){
			int invIn=(state.size()-j-1+length[i])%state.size();
			nexChair[i][state[j]][0]=state[state.size()-invIn-1];
			nexChair[i][state[j]][1]=state[(j+length[i])%state.size()];
			if(state[j]==chairs[i])toRemove=j;
		}
		state.erase(state.begin()+toRemove);
	}
	if(possible(0,p)){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
    return 0;
}
