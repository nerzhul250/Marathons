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
int balance[20005];
int subtSz[20005];
int N;
vector<int> adjList[20005];
int goSubtSz(int u,int p){
	//cout << u << " "<<p << endl;
	fore(i,0,adjList[u].size()){
		int v=adjList[u][i];
		if(v!=p){
			subtSz[u]+=goSubtSz(v,u);
		}
	}
	subtSz[u]++;
	return subtSz[u];
}
void goBalance(int u,int p,int pSz){
	int maximo=pSz;
	fore(i,0,adjList[u].size()){
		int v=adjList[u][i];
		if(v!=p){
			maximo=max(maximo,subtSz[v]);
			goBalance(v,u,pSz+subtSz[u]-subtSz[v]);
		}
	}
	balance[u]=maximo;
}
int main(){FIN;
	int t;
	cin >> t;
	while(t--){
		cin >> N;
		fore(i,0,N){
			adjList[i].clear();
			subtSz[i]=0;
			balance[i]=0;
		}
		fore(i,0,N-1){
			int a,b;
			cin >> a >> b;
			a--;
			b--;
			adjList[a].pb(b);
			adjList[b].pb(a);
		}
		goSubtSz(0,-1);
		goBalance(0,-1,0);
		int minimum=1e8;
		int index=-1;
		fore(i,0,N){
			//cout << subtSz[i]<<" "<<balance[i]<<"\n";
			if(balance[i]<minimum){
				minimum=balance[i];
				index=i;
			}
		}
		cout <<  index+1 << " "<<minimum << "\n";
	}
    return 0;
}

