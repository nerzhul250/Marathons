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
const int N = 10000000;
int lp[N+1];
vector<int> pr;
ll a,b,c,d;
ll cnt(int index,ll prev){
	
	ll sum=0;
	fore(i,index,pr.size()){
		ll newPrev=prev*pr[i];
		if(newPrev>N)break;
		ll cnt1=(b/newPrev)-((a-1)/newPrev);
		ll cnt2=(d/newPrev)-((c-1)/newPrev);
		ll parNum=cnt1*cnt2;
		sum+=parNum-cnt(i+1,newPrev);
	}
	return sum;
}
int main(){FIN;
	for (int i=2; i<=N; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)lp[i * pr[j]] = pr[j];
	}
	cin >> a >> b >> c >> d;
	ll A=b-a+1;
	ll B=d-c+1;
	cout << A*B-cnt(0,1)<<"\n";
    return 0;
}
