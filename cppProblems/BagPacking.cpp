#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;

class BagPacking {
	public:
	int minPay(vector<int>);
};

int BagPacking::minPay(vector<int> bagsizes) {
	int cnt[105];
	memset(cnt,0,sizeof cnt);
	for(int b:bagsizes)cnt[b]++;
	vector<int> bags;
	fore(i,1,101){
		if(cnt[i]>0){
			bags.pb(cnt[i]);
		}
	}
	int curr=0;
	fore(i,0,bags.size()-1){
		curr+=bags[i];
		int inside=min(curr,bags[i+1]);
		curr-=inside;
	}
	curr+=bags.back();
	return curr;
}

int main(){FIN;	
	vector<int> bagsizes={59, 59, 59, 56, 59, 56, 56, 59, 59, 55, 60, 57, 56, 60, 58, 56, 57, 58, 57, 58, 56, 58, 55};
	cout << BagPacking().minPay(bagsizes);
    return 0;
}
