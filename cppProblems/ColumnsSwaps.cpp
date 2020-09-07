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
const int MAXN=400005;
// MAXN: max number of nodes or 2 * max number of variables (2SAT)
//2 SAT MIGHT NOT BE THE RIGHT APPROACH
bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
stack<int> st;
void tjn(int u){
	lw[u]=idx[u]=++qidx;
	st.push(u);cmp[u]=-2;
	for(int v:g[u]){
		if(!idx[v]||cmp[v]==-2){
			if(!idx[v]) tjn(v);
			lw[u]=min(lw[u],lw[v]);
		}
	}
	if(lw[u]==idx[u]){
		int x,l=-1;
		do{x=st.top();st.pop();cmp[x]=qcmp;if(min(x,neg(x))<nvar)l=x;}
		while(x!=u);
		if(l!=-1)truth[qcmp]=(cmp[neg(l)]<0); // (2SAT)
		qcmp++;
	}
}
void scc(){
	qidx=0;
	qcmp=0;
	fore(i,0,nvar){
		idx[i]=0;
		idx[neg(i)]=0;
		cmp[i]=-1;
		cmp[neg(i)]=-1;
	}
	while(!st.empty())st.pop();
	fore(i,0,nvar){
		if(!idx[neg(i)])tjn(neg(i));
		if(!idx[i])tjn(i);
	}
}
// Only for 2SAT:
void addCon(int a, int b){g[a].pb(b);g[neg(b)].pb(neg(a));}
bool satisf(int _nvar){
	nvar=_nvar;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}


int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		int N;
		cin >> N;
		fore(j,0,N){
			g[j].clear();
			g[neg(j)].clear();
		}
		map<int,vector<ii>> mp;
		fore(i,0,2){
			fore(j,0,N){
				int nam;
				cin >> nam;
				mp[nam].pb(ii(i,j));
			}
		}
		bool possible=true;
		for(auto it=mp.begin();it!=mp.end() && possible;it++){
			if((it->ss).size()!=2){
				cout << "-1\n";
				possible=false;
			}
		}
		if(possible){
			for(auto it=mp.begin();it!=mp.end() && possible;it++){
				ii pos1=(it->ss)[0];
				ii pos2=(it->ss)[1];
				if(pos1.ss!=pos2.ss){
					if(pos1.ff==pos2.ff){
						addCon(pos1.ss,neg(pos2.ss));
						addCon(neg(pos2.ss),pos1.ss);
					}else{
						addCon(pos1.ss,pos2.ss);
						addCon(pos2.ss,pos1.ss);
					}
				}
			}
			if(satisf(N)){
				int cnt=0;
				vector<int> trues,falses;
				fore(j,0,N){
					if(truth[cmp[j]]){
						cnt++;
						trues.pb(j+1);
					}else{
						falses.pb(j+1);
					}
				}
				cout << min(N-cnt,cnt)<<"\n";
				if(cnt<=N-cnt){
					fore(i,0,trues.size()){
						cout << trues[i]<<" ";
					}
					cout << "\n";
				}else{
					fore(i,0,falses.size()){
						cout << falses[i]<<" ";
					}
					cout << "\n";
				}
			}else{
				cout << "-1\n";
			}
		}
	}
    return 0;
}
