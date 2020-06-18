#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int costos[15][105];
int kas[15];
int B;
int sz[5];
int possi[2][4000005];
void compute(int index,int limit,int pos,int currSum){
	if(index==limit){
		possi[pos][sz[pos]]=currSum;
		sz[pos]++;
	}else{
		fore(i,0,kas[index]){
			if(costos[index][i]<B-currSum){
				compute(index+1,limit,pos,currSum+costos[index][i]);
			}
		}
	}
	return ;
}
int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		cin >> B;
		int N;
		cin >>N;
		fore(i,0,N)cin >> kas[i];
		fore(i,0,N){
			fore(j,0,kas[i]){
				cin >> costos[i][j];
			}
		}
		if(N==1){
			int MAX=0;
			fore(i,0,kas[0]){
				if(costos[0][i]<=B){
					MAX=max(MAX,costos[0][i]);
				}
			}
			cout << MAX << "\n";
		}else{
			sz[0]=sz[1]=0;
			compute(0,N/2,0,0);
			compute(N/2,N,1,0);
			sort(begin(possi[0]),begin(possi[0])+sz[0]);
			sort(begin(possi[1]),begin(possi[1])+sz[1]);
			int MAX=0;
			fore(i,0,sz[0]){
				int to=B-possi[0][i];
				auto it=upper_bound(begin(possi[1]),begin(possi[1])+sz[1],to);
				int index=it-begin(possi[1]);
				if(index-1>=0){
					MAX=max(MAX,possi[0][i]+possi[1][index-1]);
				}
			}
			cout << MAX << "\n";
		}
	}
    return 0;
}
