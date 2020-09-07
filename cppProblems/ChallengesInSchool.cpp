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
int main(){FIN;
	int n,k;
	cin >> n >> k;
	vector<int> state(n,0);
	fore(i,0,n){
		char c;
		cin >> c;
		if(c=='R'){
			state[i]=1;
		}else{
			state[i]=0;
		}
	}
	int requiredMoves=0;
	int lastPos=n-1;
	for(int i=n-1;i>=0;i--){
		if(state[i]==1){
			requiredMoves+=(lastPos-i);
			lastPos--;
		}
	}
	int available=0;
	fore(i,0,n-1)if(state[i]==1 && state[i+1]==0)available++;
	vector<vector<int>> moves;
	while(available){
		moves.pb(vector<int>());
		fore(i,0,n-1){
			if(state[i]==1 && state[i+1]==0){
				state[i]=0;
				state[i+1]=1;
				moves.back().pb(i+1);
				i++;
			}
		}
		available=0;
		fore(i,0,n-1)if(state[i]==1 && state[i+1]==0)available++;
	}
	if(k>=moves.size() && k<=requiredMoves){
		int currSize=moves.size();
		vector<int> pila;
		while(currSize<k){
			int child=moves.back().back();
			moves.back().pop_back();
			pila.pb(child);
			currSize++;
			if(moves.back().size()==0){
				moves.pop_back();
				currSize--;
			}
		}
		while(pila.size()!=0){
			int e=pila.back();
			pila.pop_back();
			moves.pb({e});
		}
		fore(i,0,k){
			cout << moves[i].size() << " ";
			fore(j,0,moves[i].size()){
				cout << moves[i][j]<<" ";
			}
			cout << "\n";
		}
	}else{
		cout << "-1\n";
	}
    return 0;
}
