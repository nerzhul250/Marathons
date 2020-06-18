#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
set<string> st;
map<string,int> mp;
string anim[205];
int validPairs[205][205];
vector<pair<int,pair<int,vector<int>>>> indices;
map<int,int> mpInd;
int main(){FIN;
	int S,L,N;
	cin >> S >>L >> N;
	fore(i,0,S){
		string s;
		cin >> s;
		st.insert(s);
	}
	int animal=0;
	for(string s:st){
		mp[s]=animal;
		anim[animal]=s;
		animal++;
	}
	fore(i,0,L){
		string s1,s2;
		cin >> s1 >> s2;
		validPairs[mp[s1]][mp[s2]]=1;
		validPairs[mp[s2]][mp[s1]]=1;
	}
	fore(i,0,N){
		string s;
		cin >> s;
		if(mpInd.count(mp[s])==0){
			mpInd[mp[s]]=indices.size();
			indices.pb({mp[s],{0,vector<int>()}});
			indices.back().ss.ss.pb(i);
		}else{
			indices[mpInd[mp[s]]].ss.ss.pb(i);
		}
	}
	vector<int> ans;
	fore(i,0,N){
		int minimum=indices[0].ff;
		fore(j,1,indices.size()){
			bool possible=true;
			fore(k,0,j){
				if(!validPairs[indices[k].ff][indices[j].ff]){
					possible=false;
					break;
				}
			}
			if(possible && indices[j].ff<minimum){
				minimum=indices[j].ff;
			}
		}
		ans.pb(minimum);
		indices[mpInd[minimum]].ss.ff++;
		if(indices[mpInd[minimum]].ss.ff==indices[mpInd[minimum]].ss.ss.size()){
			fore(j,mpInd[minimum]+1,indices.size()){
				mpInd[indices[j].ff]--;
			}
			indices.erase(indices.begin()+mpInd[minimum]);
		}else{
			int currInd=mpInd[minimum];
			while(currInd+1<indices.size() &&
				  indices[currInd].ss.ss[indices[currInd].ss.ff]>indices[currInd+1].ss.ss[indices[currInd+1].ss.ff]){
					  mpInd[indices[currInd].ff]++;
					  mpInd[indices[currInd+1].ff]--;
					  swap(indices[currInd].ff,indices[currInd+1].ff);
					  swap(indices[currInd].ss.ff,indices[currInd+1].ss.ff);
					  indices[currInd].ss.ss.swap(indices[currInd+1].ss.ss);
					  currInd++;
			}
		}
	}
	fore(i,0,ans.size()){
		if(i==ans.size()-1)cout << anim[ans[i]]<<"\n";
		else cout << anim[ans[i]]<<" ";
	}
    return 0;
}
