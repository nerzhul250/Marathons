#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;

class EllysPronunciation {
	public:
	int getGood(vector<string>);
};

int EllysPronunciation::getGood(vector<string> words) {
	int cnt=0;
	fore(i,0,words.size()){
		string w=words[i];
		int vow=0,cons=0;
		fore(i,0,w.size()){
			if(w[i]=='a' ||w[i]=='e' ||w[i]=='i' ||w[i]=='o' ||w[i]=='u'){
				vow++;
			}else{
				cons++;
			}
		}
		if(cons==vow){
			cnt++;
		}
	}
	return cnt;
}

int main(){FIN;
	vector<string> words={"ab","aa","bu"};
	cout << EllysPronunciation().getGood(words)<<"\n"; 
}
