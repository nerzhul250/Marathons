#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>

#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
const int INF=1e8;
char letras[30]={'a','b','c','d','e','f','g','h','i','j','k',
				 'l','m','n','o','p','q','r','s','t','u','v',
				 'w','x','y','z','+','*','/','?'};
map<char,int> mp;
int cnt[35];
int dp[35][15];
int cost[35][35];
int go(int pos,int k){
	if(k<0)return INF;
	int &r=dp[pos][k];
	if(r!=-1)return r;
	if(pos==30)return r=(k==0?0:INF);
	r=1e8;
	fore(i,pos,30){
		r=min(r,cost[pos][i]+go(i+1,k-1));
	}
	//cout << pos <<" "<<k<<" "<<r <<endl;
	return r;
}
void constructSol(int pos,int k,vector<int> &ans){
	fore(i,pos,30){
		if(dp[pos][k]==(dp[i+1][k-1]+cost[pos][i])){
			if(i+1<30){
				ans.pb(i+1);
				constructSol(i+1,k-1,ans);
			}
			break;
		}
	}
}
int main(){FIN;
	fore(i,0,30)mp[letras[i]]=i;
	int t;
	cin >> t;
	while(t--){
		memset(cnt,0,sizeof cnt);
		memset(dp,-1,sizeof dp);
		int M;
		cin >> M;
		fore(i,0,M){
			string s;
			cin >> s;
			fore(j,0,s.size())cnt[mp[s[j]]]++;
		}
		//fore(j,0,30)cout << cnt[j]<<" ";
		//cout <<endl;
		fore(i,0,30){
			fore(j,i,30){
				int sum=0;
				fore(k,i,j+1){
					sum+=(cnt[k]*(k-i+1));
				}
				cost[i][j]=sum;
				//cout <<i<<" "<<j<<" "<<cost[i][j]<<endl;
			}
		}
		go(0,12);
		//cout << dp[0][12]<<endl;
		vector<int> ans;
		constructSol(0,12,ans);
		fore(i,0,ans.size()){
			if(i==ans.size()-1)cout << letras[ans[i]] << "\n";
			else cout<< letras[ans[i]];
		}
	}
    return 0;
}

