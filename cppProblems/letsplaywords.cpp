#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;

typedef pair<string,int> ii;

map<string,int> stoin;

void reversals(set<string> &w1,set<string> &w2,vector<int> &ans){
	auto it=w1.begin();
	while(w1.size()>w2.size()+1){
		string os=*it;
		reverse(ALL(os));
		if(stoin.count(os)==0){
			w2.insert(os);
			reverse(ALL(os));
			ans.pb(stoin[os]+1);
			it=w1.erase(it);
		}else{
			it++;
		}		
	}
}

int main(){FIN;
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		int a11=0,a00=0,a01=0,a10=0;
		set<string> w01,w10;
		stoin.clear();
		fore(i,0,n){
			string s;
			cin >> s;
			if(s.front()=='0' && s.back()=='0'){
				a00++;
			}else if(s.front()=='1' && s.back()=='0'){
				a10++;
				w10.insert(s);
			}else if(s.front()=='0' && s.back()=='1'){
				a01++;
				w01.insert(s);
			}else if(s.front()=='1' && s.back()=='1'){
				a11++;
			}
			stoin[s]=i;
		}
		bool possible=true;
		if(a00>0 && a11>0)possible=(a01!=0 || a10!=0);
		if(possible){
			vector<int> ans;
			if(a01>a10+1){
				reversals(w01,w10,ans);
			}else if(a10>a01+1){
				reversals(w10,w01,ans);
			}
			cout << ans.size() << "\n";
			fore(i,0,ans.size()){
				if(i==ans.size()-1){
					cout << ans[i] << "\n";
				}else{
					cout << ans[i] << " ";
				}
			}
		}else{
			cout << "-1\n";
		}
	}
    return 0;
}
