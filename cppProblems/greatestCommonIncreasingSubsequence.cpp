#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
typedef long long int ll;
int arr[505],brr[505];
int lcis[505];
vector<int> previous[505];
int N,M;
int main(){FIN;
	cin >> N;
	fore(i,0,N)cin >> arr[i];
	cin >> M;
	fore(i,0,M)cin >> brr[i];
	fore(j,0,M)lcis[j]=0;
	fore(i,0,N){
		int curr=0;
		vector<int> currPrev;
		fore(j,0,M){
			if(arr[i]==brr[j]){
				if(curr+1>lcis[j]){
					lcis[j]=curr+1;
					previous[j]=currPrev;
					previous[j].pb(brr[j]);					
				}
			}	
			if(arr[i]>brr[j]){
				if(lcis[j]>curr){
					curr=lcis[j];
					currPrev=previous[j];
				}
			}
		}
	}
	int maximo=0;
	int indexj=-1;
	fore(j,0,M){
		//cout << lcis[j]<< " "<< prev[j] << endl;
		if(maximo<lcis[j]){
			maximo=lcis[j];
			indexj=j;
		}
	}
	vector<int> ans=previous[indexj];
	cout << ans.size() << "\n";
	fore(i,0,ans.size()){
		if(i==ans.size()-1)cout << ans[i] << "\n";
		else cout << ans[i]<< " ";
	}
    return 0;
}
