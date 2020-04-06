#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef vector<int> vi;

vi adjList[85];
int m,h,r,n;
int hSon=-1,mSon=-1;

int getHeight(int u,int p){
	int maximum=0;
	for(int v : adjList[u]){
		if(v!=p)maximum=max(maximum,getHeight(v,u));
	}
	return maximum+1;
}

void explore(int u, int p){
	for(int v : adjList[u]){
		if(v!=p){
			if(v==m){
				mSon=u;
			}else if(v==h){
				hSon=u;
			}else{
				explore(v,u);
			}
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r >> h >> m;
    r--,h--,m--;
    fore(i,0,n-1){
		int u,v;
		cin >> u >> v;
		u--;
		v--;
		adjList[u].pb(v);
		adjList[v].pb(u);
	}
	
	explore(r,r);
	
	if(mSon==-1){
		cout << getHeight(hSon,h)<<"\n";
	}else if(hSon==-1){
		cout << getHeight(mSon,m)<<"\n";
	}else{
		int minimum=min(getHeight(hSon,h),getHeight(mSon,m));
		fore(i,0,n){
			int val=getHeight(i,i);
			if(i==h || i==m){val--;}
			minimum=min(minimum,val);
		}
		cout << minimum<<"\n";
	}
    return 0;
}
