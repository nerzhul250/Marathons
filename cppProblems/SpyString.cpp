#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
char table[15][15];
int rows[15];
int n,m;
bool construct(vector<int>&res,int j){
	//cout << j<<endl;
	if(res.size()==m)return true;
	fore(l,0,26){
		bool possible=true;
		fore(i,0,n){
			if((table[i][j]-'a')!=l && rows[i]==0){
				possible=false;
			}
		}
		if(possible){
			fore(i,0,n){
				if((table[i][j]-'a')!=l){
					rows[i]--;
				}
			}
			res.pb(l);
			if(construct(res,j+1))return true;
			res.pop_back();
			fore(i,0,n){
				if((table[i][j]-'a')!=l){
					rows[i]++;
				}
			}
		}
	}
	return false;
}
int main(){FIN;
	int t;
	cin >>t;
	while(t--){
		cin >>n>>m;
		fore(i,0,n){
			rows[i]=1;
			fore(j,0,m){
				cin >> table[i][j];
			}
		}
		vector<int> res;
		construct(res,0);
		if(res.size()==m){
			string ans="";
			fore(i,0,res.size()){
				ans+='a'+res[i];
			}
			cout << ans<<"\n";
		}else{
			cout << "-1\n";
		}
	}
    return 0;
}

