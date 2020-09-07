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
const int MAXN=200005;
// MAXN: max number of nodes or 2 * max number of variables (2SAT)
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
	memset(idx,0,sizeof(idx));qidx=0;
	memset(cmp,-1,sizeof(cmp));qcmp=0;
	fore(i,0,MAXN)if(!idx[i])tjn(i);
}
// Only for 2SAT:
void addcon(int a, int b){g[a].pb(b);g[neg(b)].pb(neg(a));}
bool satisf(int _nvar){
	nvar=_nvar;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}
int status[MAXN];
vector<int> switches[MAXN];
int main(){FIN;
	int n,m;
	cin >> n >> m;
	fore(i,0,n)cin >> status[i];
	fore(i,0,m){
		int nam;
		cin >> nam;
		fore(j,0,nam){
			int room;
			cin >> room;
			room--;
			switches[room].pb(i);
		}
	}
	fore(i,0,n){
		int s1=switches[i][0];
		int s2=switches[i][1];
		if(status[i]){
			addcon(s1,s2);
			addcon(s2,s1);
		}else{
			addcon(s1,neg(s2));
			addcon(neg(s2),s1);
		}
	}
	if(satisf(m)){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}
    return 0;
}
