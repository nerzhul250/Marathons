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

struct vertex {
	map<char,int> next;
	char pch;
	vertex(char pch=-1):pch(pch){}
};
vector<vertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(vertex());
}
void add_string(string s){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(vertex(c));
		}
		v=t[v].next[c];
	}
}
int N;
int brother[3605];
int son[3605];
int dp[3605][105];
int cnt[3605];
int set_up(int v){
	vector<int> sons;
	//cout << v << endl;
	for(auto it=t[v].next.begin();it!=t[v].next.end();it++){
		sons.pb(it->ss);
	}
	fore(i,0,sons.size()){
		if(i==0){
			son[v]=sons[i];
		}
		if(i+1<sons.size()){
			brother[sons[i]]=sons[i+1];
		}
		cnt[v]+=set_up(sons[i]);
	}
	cnt[v]+=(t[v].next.size()==0);
	return cnt[v];
}
int go(int v,int n){
	if(brother[v]==-1 && son[v]==-1)return n>1?INF:0;
	int &r=dp[v][n];
	if(r!=-1)return r;
	if(brother[v]==-1){
		return r=(n==1?0:n)+(cnt[v]-n==1?0:cnt[v]-n)+go(son[v],n);
	}
	if(son[v]==-1){
		return r=min(go(brother[v],n),go(brother[v],max(n-1,0)));;
	}
	r=1e8;
	fore(m,0,n+1){
		r=min(r,(m==1?0:m)+(cnt[v]-m==1?0:cnt[v]-m)+go(son[v],m)+go(brother[v],n-m));
	}
	return r;
}
int main(){FIN;
	while(cin >> N){
		//if(N==0)break;
		aho_init();
		memset(brother,-1,sizeof brother);
		memset(son,-1,sizeof son);
		memset(dp,-1,sizeof dp);
		memset(cnt,0,sizeof cnt);
		fore(i,0,2*N){
			string s;
			cin >> s;
			add_string(s);
		}
		set_up(0);
		int toErase=(N==1?0:N)+(cnt[0]-N==1?0:cnt[0]-N);
		cout << (go(0,N)-toErase+2*N)*N << "\n";
	}
    return 0;
}
