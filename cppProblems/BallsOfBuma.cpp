#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;
int main(){FIN;
	string balls;
	cin >> balls;
	vector<int> counter;
	vector<char> type;
	int cnt=0;
	fore(i,0,balls.size()){
		cnt++;
		if(i==balls.size()-1 || balls[i]!=balls[i+1]){
			counter.pb(cnt);
			type.pb(balls[i]);
			cnt=0;
		}
	}
	if(counter.size()%2==0){
		cout << "0\n";
	}else{
		int index=counter.size()/2;
		if(counter[index]+1>=3){
			int l=index-1;
			int r=index+1;
			while(counter[l]+counter[r]>=3 && type[l]==type[r]){
				l--;
				r++;
			}
			if(l==-1 &&r==counter.size()){
				cout << counter[index]+1<<"\n";
			}else{
				cout << "0\n";
			}
		}else{
			cout << "0\n";
		}
	}
    return 0;
}
