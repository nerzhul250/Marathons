#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

const int MAXN=10005;

// MAXN: max number of nodes or 2 * max number of variables (2SAT)
bool truth[MAXN]; // truth[cmp[i]]=value of variable i (2SAT)
int nvar;int neg(int x){return MAXN-1-x;} // (2SAT)
vector<int> g[MAXN];
int n,lw[MAXN],idx[MAXN],qidx,cmp[MAXN],qcmp;
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
	fore(i,0,n)if(!idx[i])tjn(i);
}
bool satisf(int _nvar){
	nvar=_nvar;n=MAXN;scc();
	fore(i,0,nvar)if(cmp[i]==cmp[neg(i)])return false;
	return true;
}

int k;
int main(){FIN;
	cin >> k >> n;
	fore(i,0,n){
		vector<pair<int,char>> gs;
		fore(j,0,3){
			int lamp;
			char guess;
			cin >> lamp >> guess;
			lamp--;
			gs.pb({lamp,guess});
		}
		fore(j,0,3){
			pair<int,char> e1=gs[j];
			pair<int,char> e2=gs[(j+1)%3];
			pair<int,char> e3=gs[(j+2)%3];
			int n1=(e1.ss=='B'?neg(e1.ff):e1.ff);
			int n2=(e2.ss=='B'?e2.ff:neg(e2.ff));
			int n3=(e3.ss=='B'?e3.ff:neg(e3.ff));
			g[n1].pb(n2);
			g[n1].pb(n3);
		}
	}
	if(satisf(k)){
		string ans="";
		fore(i,0,k){
			if(truth[cmp[i]]){
				ans+='B';	
			}else{
				ans+='R';
			}
		}
		cout << ans<<"\n";
	}else{
		cout <<"-1\n";
	}
    return 0;
}
