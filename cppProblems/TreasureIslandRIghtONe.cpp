#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
vector<vector<int>> theCnt;
vector<vector<char>> theMap;
map<int,int> types;
int n,m;

void forward(int i, int j){
	if(!(i>=0 && i<n && j>=0 && j<m && theMap[i][j]!='#' && theCnt[i][j]==0))return;
	theCnt[i][j]++;
	forward(i+1,j);
	forward(i,j+1);
}
void backward(int i, int j){
	if(!(i>=0 && i<n && j>=0 && j<m && theMap[i][j]!='#'&& theCnt[i][j]==1))return;
	theCnt[i][j]++;
	backward(i-1,j);
	backward(i,j-1);
}
int main(){FIN;
	cin >> n >> m;
	fore(i,0,n){theCnt.pb(vector<int>(m,0));theMap.pb(vector<char>(m,'.'));}
	fore(i,0,n)fore(j,0,m)cin >> theMap[i][j];
	
	forward(0,0);
	backward(n-1,m-1);

	fore(i,0,n){
		fore(j,0,m){
			//cout << i<< " " << j <<endl;
			//cout << theCnt[i][j]<<endl;
			if(theCnt[i][j]==2){
				types[i+j]++;
			}
		}
	}
	int minimum=1e9;
	fore(i,1,n+m-2){
		minimum=min(minimum,types[i]);
	}
	if(minimum>=2){
		cout << "2\n";
	}else {
		cout << minimum << "\n";
	}
    return 0;
}
